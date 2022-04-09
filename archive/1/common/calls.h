#pragma once
#include <iostream> 
#include <cstring>
#include <fstream> 

#define SCR_W 100
#define SCR_H 100

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
std::string _CurrErrorString = "null";
#include <Windows.h>
#include <winternl.h>
LRESULT CALLBACK msgBoxHook(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HCBT_CREATEWND) {
		CREATESTRUCT* pcs = ((CBT_CREATEWND*)lParam)->lpcs;
        if ((pcs->style & WS_DLGFRAME) || (pcs->style & WS_POPUP)) {
			HWND hwnd = (HWND)wParam;   
            int x = rand() % (SCR_W - pcs->cx);
            int y = rand() % (SCR_H - pcs->cy);
            pcs->x=x;pcs->y=y;
        }
    } 
    return CallNextHookEx(0, nCode, wParam, lParam);    
}
DWORD WINAPI hookProc(LPVOID param) {
    HHOOK hook = SetWindowsHookEx(WH_CBT, msgBoxHook, 0, GetCurrentThreadId());
	std::string desc = _CurrErrorString; 
	MessageBoxA(NULL, (LPCSTR) desc.c_str(), "Error", MB_OK | MB_SYSTEMMODAL | MB_ICONHAND);
	UnhookWindowsHookEx(hook);
	return 0;
}
#endif

void hard_error(int code, std::string reason = "null[2]") {
 #ifdef SIM_WINDOWS 
    _CurrErrorString = reason;
    CreateThread(NULL, 4096, &hookProc, NULL, NULL)
 #endif   
    exit(code);
}

std::string getAppDataPath() {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) 
        const char* subpath= "\\GalaticSimulator";
        return (std::string) strcat(getenv("APPDATA"), subpath);
    #else // (MacOS)
         return "~//Library//Application Support//GalaticSimulator";
    #endif
    return NULL;
}
