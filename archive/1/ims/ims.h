// Makeshift way of storing settings
#ifndef IMS_H_
#define IMS_H_
#include "../common/main.h"
#include "ims_EXPORT.h"

typedef const char* keystr;

extern void SHARED_EXPORT    ImsVerify(); 
extern int   SHARED_EXPORT   ImsWrite(keystr name, keystr value);
extern keystr  SHARED_EXPORT     ImsFetch(keystr name);
extern int   SHARED_EXPORT   ImsRemove(keystr name);

#endif