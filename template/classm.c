#include "classm.h"

int classMMethod0(void* self, ...)
{
    ClassM* pClassM= (ClassM*)self;

    // ...

    return 1;
}

int classMMethod1(void* self, ...)
{
    ClassM* pClassM= (ClassM*)self;

    // ...

    return 1;
}

// ...

int classMMethodn(void* self, ...)
{
    ClassM* pClassM= (ClassM*)self;

    // ...

    return 1;
}


static MethodsT classMMethods=
{
	.method0Fn= classMMethod0,
	.method1Fn= classMMethod1,
    // ...
	.methodnFn= classMMethodn
};

int classMInit(void* self, ...)
{
	ClassM* pClassM= (ClassM*)self;

	pClassM->methods= &classMMethods;
	pClassM->attribute0= 0;
	pClassM->attribute1= 0;
    // ...
	pClassM->attributen= 0;

    // ...

	return 1;
}
