#ifndef _TRAIL_CAR_H
#define _TRAIL_CAR_H

#include "trace.h"
#include "motor.h"

enum TrailCarStat
{
    CAR_STOP,
    CAR_RUN
};


typedef int (*TrailCarRunFnT)(void* self, int speedStraight, int speedTurnFast, int speedTurnLow);
typedef int (*TrailCarStopFnT)(void* self);


typedef struct
{
    TrailCarRunFnT trailCarRunFn;
    TrailCarStopFnT trailCarStopFn;
} TrailCarMethodsT;


typedef struct
{
    TrailCarMethodsT* pTrailCarMethods;
    Trace* trailCarTrace0;
    Trace* trailCarTrace1;
    Trace* trailCarTrace2;
    Trace* trailCarTrace3;
    Trace* trailCarTrace4;
    Motor* trailCarMotorLeft;
    Motor* trailCarMotorRight;
    enum TrailCarStat trailCarStat;
} TrailCar;


static inline int trailCarRunFn(void* self, int speedStraight, int speedTurnFast, int speedTurnLow)
{
    return (*(TrailCarMethodsT**)self)->trailCarRunFn(self, speedStraight, speedTurnFast, speedTurnLow);
}

static inline int trailCarStopFn(void* self)
{
    return (*(TrailCarMethodsT**)self)->trailCarStopFn(self);
}


int trailCarRun(void* self, int speedStraight, int speedTurnFast, int speedTurnLow);
int trailCarStop(void* self);
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
);

#endif
