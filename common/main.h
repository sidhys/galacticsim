/*--------------------------------- 
|    includes                     | 
|    everything                   |
---------------------------------*/
#pragma once
#include "calls.h"
#include "../ims/ims.h"


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
#define SIM_WINDOWS
#endif

const char* UI_TITLE = "[DEBUG] space sim thing";