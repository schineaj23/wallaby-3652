#include "util.h"
#include "chassis.h"
#include <stdbool.h>

#define NOT_TRACKING() analog(LINE_TRACKER) < 800
#define TRACKING() analog(LINE_TRACKER) > 800

void init()
{
    enable_servos();
}

void shutDown()
{
    disable_servos();
    ao();
}

bool isTracking()
{
    if(TRACKING())
        return true;

    return false;
}


void correctPos()
{
    while(isTracking())
        veerRight(75, 10, 500);

    while(!isTracking())
        veerLeft(75, 10, 500);
}

void trackLine()
{
    // reach the first line
    while(!isTracking())
        moveForward(100, 1);

    // cross the first line 
    while(isTracking())
        moveForward(100, 1);

    // reach the second line
    while(!isTracking())
        moveForward(100, 1);

    // cross the second line
    while(isTracking())
        moveForward(100, 1);

    moveForward(100, 500);

    spinLeft(75, 800);
    
    clear_motor_position_counter(RIGHT_MOTOR);
    clear_motor_position_counter(LEFT_MOTOR);

    score();
}
