#include <stdlib.h>
#include <stdio.h>

#include "motor.h"

#define MOTOR0_PINA 0
#define MOTOR0_PINB 1
#define MOTOR0_PINCONTROLSPEED 2
#define MOTOR0_SPEED0 100
#define MOTOR0_SPEED1 200

int main()
{
    Motor motor0;
    motorInit(&motor0, MOTOR0_PINA, MOTOR0_PINB, MOTOR0_PINCONTROLSPEED);

    motor0.pMotorMethods->motorStopFn(&motor0);
    motor0.pMotorMethods->motorForwardFn(&motor0, MOTOR0_SPEED0);
    motor0.pMotorMethods->motorReverseFn(&motor0, MOTOR0_SPEED1);
    motor0.pMotorMethods->motorControlSpeedFn(&motor0, MOTOR0_SPEED0);

    return 0;
}
