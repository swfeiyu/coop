#ifndef _CLASSN_H
#define _CLASSN_H

#ifdef __cplusplus
extern "C" {
#endif


#include "interface.h"


typedef int Type;


typedef struct
{
	MethodsT* methods;
	Type attribute0;
	Type attribute1;
    // ...
	Type attributen;
} ClassN;


int classNMethod0(void* self, ...);
int classNMethod1(void* self, ...);
// ...
int classNMethodn(void* self, ...);

int classNInit(void* self, ...);


#ifdef __cplusplus
}
#endif

#endif _CLASSN_H
