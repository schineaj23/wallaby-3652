#include "servos.h"

void openClaw()
{
    set_servo_position(SERVO_CLAW_MOTOR, 1500);
}

void closeClaw()
{
    set_servo_position(SERVO_CLAW_MOTOR, 300);
}

void wave(int amt)
{
    int current = 0;
    while(current < amt)
    {
        openClaw();
        msleep(500);
        closeClaw();
        current++;
        printf("waving %d times!\n", current);
    }
    printf("done waving.\n");
}

void armUp(int pos, int time)
{
    set_servo_position(SERVO_ARM_MOTOR, pos*-1);
    msleep(time);
    printf("Arm going up!\n");
}

void armDown(int pos, int time)
{
    set_servo_position(SERVO_ARM_MOTOR, pos*-1);
    msleep(time);
    printf("Arm going down!\n");
}

