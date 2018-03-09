#include "chassis.h"

void moveForward(int speed, int time)
{
    motor(LEFT_MOTOR, speed*0.85); // Temp hotfix for veering
    motor(RIGHT_MOTOR, speed);
	msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void moveBackward(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-1);
    motor(RIGHT_MOTOR, speed*-1);
	msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void spinLeft(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-1);
    motor(RIGHT_MOTOR, speed);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void spinRight(int speed, int time)
{
    motor(LEFT_MOTOR, speed);
    motor(RIGHT_MOTOR, speed*-1);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}


void veerRight(int speed, int veerOffset, int time)
{
    motor(LEFT_MOTOR, speed);
    motor(RIGHT_MOTOR, speed-veerOffset);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void veerLeft(int speed, int veerOffset, int time)
{
    motor(RIGHT_MOTOR, speed);
    motor(LEFT_MOTOR, speed-veerOffset);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

