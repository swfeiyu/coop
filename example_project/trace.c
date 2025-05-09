#include <stdlib.h>
#include <stdio.h>

#include "trace.h"

int traceRead(void* self, int* result)
{
    Trace* pTrace= (Trace*)self;

    int num= rand()%2;
    if(num!=0&&num!=1)
        return 0;

    *result=num;
    printf("trace result is %d\n",*result);
    return 1;
}

static TraceMethodsT TraceMethods=
{
    .traceReadFn= (TraceReadFnT)traceRead
};

int traceInit(void* self, int pin)
{
    Trace* pTrace= (Trace*)self;

    pTrace->pTraceMethods= &TraceMethods;
    pTrace->tracePin= pin;

    printf("Trace object inited successfully\n");
    return 1;
}
