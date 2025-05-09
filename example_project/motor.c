#include <stdio.h>

#include "motor.h"

int motorStop(void* self)
{
    Motor* pMotor= (Motor*)self;

    pMotor->motorStat= MOTOR_STOP;
    pMotor->motorSpeed= 0;

    printf("motor stopped\n");
    return 1;
}

int motorForward(void* self, int speed)
{
    Motor* pMotor= (Motor*)self;

    pMotor->motorStat= MOTOR_FORWARD;
    pMotor->motorSpeed= speed;

    printf("motor turned forward, speed is %d\n",pMotor->motorSpeed);
    return 1;
}

int motorReverse(void* self, int speed)
{
    Motor* pMotor= (Motor*)self;

    pMotor->motorStat= MOTOR_REVERSE;
    pMotor->motorSpeed= speed;

    printf("motor turned reverse, speed is %d\n",pMotor->motorSpeed);
    return 1;
}

int motorControlSpeed(void* self, int speed)
{
    Motor* pMotor= (Motor*)self;

    pMotor->motorSpeed= speed;

    printf("motor speed is turned to %d\n",pMotor->motorSpeed);
    return 1;
}

static MotorMethodsT MotorMethods=
{
    .motorStopFn= (MotorStopFnT)motorStop,
    .motorForwardFn= (MotorForwardFnT)motorForward,
    .motorReverseFn= (MotorReverseFnT)motorReverse,
    .motorControlSpeedFn= (MotorControlSpeedFnT)motorControlSpeed
};

int motorInit(void* self, int pinA, int pinB, int pinControlSpeed)
{
    Motor* pMotor= (Motor*)self;

    pMotor->pMotorMethods= &MotorMethods;
    pMotor->motorPinA= pinA;
    pMotor->motorPinB= pinB;
    pMotor->motorPinControlSpeed= pinControlSpeed;

    pMotor->motorStat= MOTOR_STOP;
    pMotor->motorSpeed= 0;

    printf("motor object inited successfully\n");
    return 1;
}
