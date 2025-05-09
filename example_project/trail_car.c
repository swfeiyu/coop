#include <stdio.h>

#include "trace.h"
#include "motor.h"
#include "trail_car.h"

int trailCarRun(void* self, int speedStraight, int speedTurnFast, int speedTurnLow)
{
    TrailCar* pTrailCar= (TrailCar*)self;

    pTrailCar->trailCarStat= CAR_RUN;

    int result0, result1, result2, result3, result4;
    traceReadFn(pTrailCar->trailCarTrace0, &result0);
    traceReadFn(pTrailCar->trailCarTrace1, &result1);
    traceReadFn(pTrailCar->trailCarTrace2, &result2);
    traceReadFn(pTrailCar->trailCarTrace3, &result3);
    traceReadFn(pTrailCar->trailCarTrace4, &result4);

    if(result0==1&&result1==1&&result2==1&&result3==1&&result4==1)
    {
        motorStopFn(pTrailCar->trailCarMotorLeft);
        motorStopFn(pTrailCar->trailCarMotorRight);
        printf("trail car stopped\n");
    }
    else if(result0==0&&result1==0&&result2==1&&result3==0&&result4==0)
    {
        motorForwardFn(pTrailCar->trailCarMotorLeft, speedStraight);
        motorForwardFn(pTrailCar->trailCarMotorRight, speedStraight);
        printf("trail car went straight\n");
    }
    else if(result0==0&&result1==1&&result2==0&&result3==0&&result4==0)
    {
        motorForwardFn(pTrailCar->trailCarMotorLeft, speedTurnLow);
        motorForwardFn(pTrailCar->trailCarMotorRight, speedTurnFast);
        printf("trail car turned left\n");
    }
    else if(result0==0&&result1==0&&result2==0&&result3==1&&result4==0)
    {
        motorForwardFn((void*)(pTrailCar->trailCarMotorLeft), speedTurnFast);
        motorForwardFn((void*)(pTrailCar->trailCarMotorRight), speedTurnLow);
        printf("trail car turned right\n");
    }
    else
    {
        motorForwardFn(pTrailCar->trailCarMotorLeft, speedStraight);
        motorForwardFn(pTrailCar->trailCarMotorRight, speedStraight);
        printf("trail car went straight\n");
    }

    return 1;
}

int trailCarStop(void* self)
{
    TrailCar* pTrailCar= (TrailCar*)self;

    pTrailCar->trailCarStat= CAR_RUN;

    motorStopFn(pTrailCar->trailCarMotorLeft);
    motorStopFn(pTrailCar->trailCarMotorRight);

    printf("trail car stopped\n");
    return 1;
}

static TrailCarMethodsT TraceMethods=
{
    .trailCarRunFn= (TrailCarRunFnT)trailCarRun,
    .trailCarStopFn= (TrailCarStopFnT)trailCarStop
};

int trailCarInit
(
    void* self,
    Trace* trace0,
    Trace* trace1,
    Trace* trace2,
    Trace* trace3,
    Trace* trace4,
    Motor* motorLeft,
    Motor* motorRight
)
{
    TrailCar* pTrailCar= (TrailCar*)self;

    pTrailCar->pTrailCarMethods= &TraceMethods;
    pTrailCar->trailCarTrace0= trace0;
    pTrailCar->trailCarTrace1= trace1;
    pTrailCar->trailCarTrace2= trace2;
    pTrailCar->trailCarTrace3= trace3;
    pTrailCar->trailCarTrace4= trace4;
    pTrailCar->trailCarMotorLeft= motorLeft;
    pTrailCar->trailCarMotorRight= motorRight;

    // trailCarStopFn(self);
    // pTrailCar->pTrailCarMethods.trailCarStopFn(pTrailCar);
    motorStopFn(pTrailCar->trailCarMotorLeft);
    motorStopFn(pTrailCar->trailCarMotorRight);
    pTrailCar->trailCarStat= CAR_STOP;

    return 1;
}
