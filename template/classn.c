#include "classn.h"

int classNMethod0(void* self, ...)
{
    ClassN* pClassN= (ClassN*)self;

    // ...

    return 1;
}

int classNMethod1(void* self, ...)
{
    ClassN* pClassN= (ClassN*)self;

    // ...

    return 1;
}

// ...

int classNMethodn(void* self, ...)
{
    ClassN* pClassN= (ClassN*)self;

    // ...

    return 1;
}


static MethodsT classNMethods=
{
	.method0Fn= classNMethod0,
	.method1Fn= classNMethod1,
    // ...
	.methodnFn= classNMethodn
};

int classNInit(void* self, ...)
{
	ClassN* pClassN= (ClassN*)self;

	pClassN->methods= &classNMethods;
	pClassN->attribute0= 0;
	pClassN->attribute1= 0;
    // ...
	pClassN->attributen= 0;

    // ...

	return 1;
}
