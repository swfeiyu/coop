#ifndef _TRACE_H
#define _TRACE_H

typedef int (*TraceReadFnT)(void* self, int* result);


typedef struct
{
    TraceReadFnT traceReadFn;
} TraceMethodsT;


typedef struct
{
    TraceMethodsT* pTraceMethods;
    int tracePin;
} Trace;

static inline int traceReadFn(void* self, int* result)
{
    return (*(TraceMethodsT**)self)->traceReadFn(self, result);
}

int traceRead(void* self, int* result);
int traceInit(void* self, int pin);

#endif
