#include "main.h"

int main()
{
    classMInit(&classM/*, ...*/);
    classNInit(&classN/*, ...*/);

    method0Fn(&classM/*, ...*/);
    method0Fn(&classN/*, ...*/);

    method1Fn(&classM/*, ...*/);
    method1Fn(&classN/*, ...*/);

    // ...

    methodnFn(&classM/*, ...*/);
    methodnFn(&classN/*, ...*/);

    return 0;
}