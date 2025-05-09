#include <stdlib.h>
#include <stdio.h>

#include "trace.h"

#define TRACE0_PIN 0

int main()
{
    Trace trace0;
    traceInit(&trace0, TRACE0_PIN);
    int a;

    while(1)
    {
        traceReadFn(&trace0,&a);
    }

    return 0;
}
