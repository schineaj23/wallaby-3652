///////////////////////////////////////////////////////////////////////////////////////
//
//     _____           _        _     _        _____       _           _   _          
//    |  __ \         | |      (_)   | |      |  __ \     | |         | | (_)         
//    | |__) |_ _ _ __| | _____ _  __| | ___  | |__) |___ | |__   ___ | |_ _  ___ ___ 
//    |  ___/ _` | '__| |/ / __| |/ _` |/ _ \ |  _  // _ \| '_ \ / _ \| __| |/ __/ __|
//    | |  | (_| | |  |   <\__ \ | (_| |  __/ | | \ \ (_) | |_) | (_) | |_| | (__\__ \
//    |_|   \__,_|_|  |_|\_\___/_|\__,_|\___| |_|  \_\___/|_.__/ \___/ \__|_|\___|___/
//
///////////////////////////////////////////////////////////////////////////////////////

#include "chassis.h"

void moveForward(int speed, int time)
{
    motor(LEFT_MOTOR, speed*0.85); // TODO: Fix wheel veering problem.
    motor(RIGHT_MOTOR, speed);
	msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void moveBackward(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-0.85);
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
    motor(LEFT_MOTOR, speed*0.85);
    motor(RIGHT_MOTOR, speed-veerOffset);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void veerLeft(int speed, int veerOffset, int time)
{
    motor(RIGHT_MOTOR, speed);
    motor(LEFT_MOTOR, speed-veerOffset*0.85);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void turnLeft(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-0.85);
    msleep(time);
   	motor(LEFT_MOTOR, 0);
}

void turnRight(int speed, int time)
{
    motor(RIGHT_MOTOR, speed*-1);
    msleep(time);
    motor(RIGHT_MOTOR, 0);
}


