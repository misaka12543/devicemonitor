#ifndef CANCEL_BUGS_H
#define CANCEL_BUGS_H

/**
  This head file is to define something may type wrong
  and define the type BOOL like bool
*/
#define mian main
#define ture true
#define flase false
#define viod void
#define eimt emit

///if define this,debug mode will cancel,all debug output will disable
//#define QT_NO_DEBUG_OUTPUT
    #ifndef BOOL
    #define BOOL bool
        #ifndef TRUE
        #define TRUE true
        #define TURE TRUE
        #endif//TRUE
        #ifndef FALSE
        #define FALSE false
        #define FLASE FALSE
        #endif//FALSE
    #endif//BOOL
#endif // CANCEL_BUGS_H
#include "scarray.h"
