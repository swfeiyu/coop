#include <stdlib.h>
#include <stdio.h>

#include "trace.h"
#include "motor.h"
#include "trail_car.h"
#include "main.h"


int main()
{
    traceInit(&trace0,0);
    traceInit(&trace1,1);
    traceInit(&trace2,2);
    traceInit(&trace3,3);
    traceInit(&trace4,4);

    motorInit(&motorLeft,5,6,7);
    motorInit(&motorRight,8,9,10);

    trailCarInit((void*)&trailCar,&trace0,&trace1,&trace2,&trace3,&trace4,&motorLeft,&motorRight);

    trailCarRunFn(&trailCar,100,100,100);
    trailCarStopFn(&trailCar);

    return 0;
}
