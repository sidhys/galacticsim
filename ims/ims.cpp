#include "ims.h" 
#include <cstring> 
#include <fstream>
#include <filesystem> 

namespace fs = std::filesystem;
namespace _ios = std::ios;


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
    
    std::string str_path = getAppDataPath() + (std::string) "\\IMS";
    fs::path& p = (fs::path&) str_path;

    
    return 1;
}
keystr ImsFetch(keystr name) {

    IMSFUNCHEAD
    
    std::string str_path = getAppDataPath() + (std::string) "\\IMS";
    fs::path& p = (fs::path&) str_path;

    return "d";
}
int ImsRemove(keystr name) {
    
    IMSFUNCHEAD
    
    std::string str_path = getAppDataPath() + (std::string) "\\IMS";
    fs::path& p = (fs::path&) str_path;

 return 1;
}
