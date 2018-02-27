#include "servos.h"

void openClaw()
{
    set_servo_position(SERVO_CLAW_MOTOR, 1500);
}

void closeClaw()
{
    set_servo_position(SERVO_CLAW_MOTOR, 300);
}

void armUp(int pos, int time)
{
    set_servo_position(SERVO_ARM_MOTOR, pos*-1);
    msleep(time);
}

void armDown(int pos, int time)
{
    set_servo_position(SERVO_ARM_MOTOR, pos*-1);
    msleep(time);
}

