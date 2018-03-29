#include "servos.h"

void openClaw()
{
    set_servo_position(SERVO_CLAW_MOTOR, 2047);
}

void closeClaw()
{
    set_servo_position(SERVO_CLAW_MOTOR, 0);
}