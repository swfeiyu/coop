#ifndef _CLASSM_H
#define _CLASSM_H

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
} ClassM;


int classMMethod0(void* self, ...);
int classMMethod1(void* self, ...);
// ...
int classMMethodn(void* self, ...);

int classMInit(void* self, ...);


#ifdef __cplusplus
}
#endif

#endif _CLASSM_H
