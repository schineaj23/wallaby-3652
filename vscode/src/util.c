#include <stdbool.h>
#include "util.h"
#include "chassis.h"
#include "score.h"

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
    for(i=0;i<linesToSkip;i++)
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

    getToLine();

    cmpc(RIGHT_MOTOR);
    cmpc(LEFT_MOTOR);

    score();
}

void getToLine()
{

    /*
    1. Reach the first line
    2. Cross the first line
    3. Reach the second line
    4. Cross the second line
    */

    skipLine(FORWARD, 2);

    moveForward(100, 500);

    while(!isTracking())
        spinLeft(100, 1);

}