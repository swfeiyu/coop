#ifndef _INTERFACE_H
#define _INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif


typedef int (*Method0FnT)(void* self/*, ...*/);
typedef int (*Method1FnT)(void* self/*, ...*/);
// ...
typedef int (*MethodnFnT)(void* self/*, ...*/);


typedef struct
{
	Method0FnT method0Fn;
	Method1FnT method1Fn;
    // ...
	MethodnFnT methodnFn;
} MethodsT;


static inline int method0Fn(void* self/*, ...*/)
{
	return (*(MethodsT**)self)->method0Fn(self/*, ...*/);
}

static inline int method1Fn(void* self/*, ...*/)
{
	return (*(MethodsT**)self)->method1Fn(self/*, ...*/);
}

// ...

static inline int methodnFn(void* self/*, ...*/)
{
	return (*(MethodsT**)self)->methodnFn(self/*, ...*/);
}


#ifdef __cplusplus
}
#endif

#endif
