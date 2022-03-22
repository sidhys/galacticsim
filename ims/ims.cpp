/*++

Copyright (c) 2022 <> 

Module Name: 

    ims.cpp

Abstract: 

    ims.dll stores settings, such as a users desired color theme or such. 

Revision History: 

    @daylimbic 3/21/22 Init

--*/ 

#include "ims.h" 
#include <cstring> 
#include <fstream>
#include <filesystem> 
#include <string> 

namespace fs = std::filesystem;

int _dir_exists(fs::path& p) {
    if(fs::exists(p))
        return 1; return -1;
}

void ImsVerify() {
    std::string str_path = getAppDataPath() + (std::string) "\\IMS";
    fs::path& p = (fs::path&) str_path;
    if((_dir_exists(p)) != 1) 
    { 
        fs::create_directories(p);
    }
    if((_dir_exists(p)) != 1) 
        hard_error(1, "Failed to initialize IMS");
} 

#define IMSFUNCHEAD ImsVerify();

int ImsWrite(keystr name, keystr value) {

    IMSFUNCHEAD
    
    std::string str_path = getAppDataPath() + (std::string) "\\IMS" + (std::string) name;
    const char* p = str_path.c_str();

    std::ofstream file(p, std::ios::out | std::ios::trunc);
    
    file << (std::string) value;   

    file.close();

    return 1;
}
keystr ImsFetch(keystr name) {

    IMSFUNCHEAD
    
    std::string str_path = getAppDataPath() + (std::string) "\\IMS";
    const char* p = str_path.c_str();

    std::ifstream file(p); std::string content; int lc; 

    if(file.is_open()) {
        while(getline(file, content)) lc++;
    } else hard_error (1, "[temp, wait for real error handling] failed to open" + str_path);

    if (lc != 1) hard_error (1, "[temp, wait for real error handling] out-of-order line count");

    return content.c_str();
}
int ImsRemove(keystr name) {
    
    IMSFUNCHEAD
    
    std::string str_path = getAppDataPath() + (std::string) "\\IMS";
    fs::path& p = (fs::path&) str_path;

 return 1;
}
