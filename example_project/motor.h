#ifndef _MOTOR_H
#define _MOTOR_H

typedef enum
{
    MOTOR_STOP,
    MOTOR_FORWARD,
    MOTOR_REVERSE
} MotorStat;


typedef int (*MotorStopFnT)(void* self);
typedef int (*MotorForwardFnT)(void* self, int speed);
typedef int (*MotorReverseFnT)(void* self, int speed);
typedef int (*MotorControlSpeedFnT)(void* self, int speed);


typedef struct
{
    MotorStopFnT motorStopFn;
    MotorForwardFnT motorForwardFn;
    MotorReverseFnT motorReverseFn;
    MotorControlSpeedFnT motorControlSpeedFn;
} MotorMethodsT;


typedef struct
{
    MotorMethodsT* pMotorMethods;
    int motorPinA;
    int motorPinB;
    int motorPinControlSpeed;
    MotorStat motorStat;
    int motorSpeed;
} Motor;


static inline int motorStopFn(void* self)
{
    return (*(MotorMethodsT**)self)->motorStopFn(self);
}

static inline int motorForwardFn(void* self, int speed)
{
    return (*(MotorMethodsT**)self)->motorForwardFn(self, speed);
}

static inline int motorReverseFn(void* self, int speed)
{
    return (*(MotorMethodsT**)self)->motorReverseFn(self, speed);
}

static inline int motorControlSpeedFn(void* self, int speed)
{
    return (*(MotorMethodsT**)self)->motorControlSpeedFn(self, speed);
}


int motorStop(void* self);
int motorForward(void* self, int speed);
int motorReverse(void* self, int speed);
int motorControlSpeed(void* self, int speed);
int motorInit(void* self, int pinA, int pinB, int pinControlSpeed);

#endif
