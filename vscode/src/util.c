#include "util.h"
#include "chassis.h"
#include "score.h"
#include <stdbool.h>

#define NOT_TRACKING() analog(LINE_TRACKER) < 800
#define TRACKING() analog(LINE_TRACKER) > 800
#define FORWARD 0
#define BACKWARD 1

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

void skipLine(int direction, int linesToSkip)
{
    int i;
    //for loops dont work in c i cri...
    while(i<linesToSkip)
    {
        if(FORWARD == direction)
        {
            while(!isTracking())
                moveForward(100, 1);

            while(isTracking())
                moveForward(100, 1);
        }

        if(BACKWARD == direction)
        {
            while(!isTracking())
                moveBackward(100, 1);
            
            while(isTracking())
                moveBackward(100, 1);
        }
        
    i++;
    }
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

    /*
    1. Reach the first line
    2. Cross the first line
    3. Reach the second line
    4. Cross the second line
    */

    //Cross 2 lines.
    skipLine(FORWARD, 2);

    moveForward(100, 500);

    spinLeft(75, 800);
    
    clear_motor_position_counter(RIGHT_MOTOR);
    clear_motor_position_counter(LEFT_MOTOR);

    score();
}
