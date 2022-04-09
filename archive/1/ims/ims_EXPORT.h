#ifndef IMS_EXPORT_H__
#define IMS_EXPORT_H__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
    #ifdef imsexport
        #define SHARED_EXPORT __declspec(dllexport)
    #else
        #define SHARED_EXPORT __declspec(dllimport)
    #endif
#else
    #define SHARED_EXPORT /* todo: MacOS support */
#endif


#endif