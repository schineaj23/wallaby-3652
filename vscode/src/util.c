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
        printf("skipping line #%d...   \n",i);
        if(FORWARD == direction)
        {
            printf("not tracking, so moving forward\n");
            while(!isTracking()) {
                moveForward(100, 1);
            }

            printf("tracking now, so moving forward\n");
            while(isTracking()) {
                moveForward(100, 1);
            }

            printf("no longer tracking, line #%dhas been skipped\n",i);
        }

        if(BACKWARD == direction)
        {
            while(!isTracking())
                moveBackward(100, 1);

            while(isTracking())
                moveBackward(100, 1);

            printf("Skipping %d line!\n", linesToSkip);
        }     
    }

    printf("Done skipping lines!\n");
}


void correctPos()
{
    while(isTracking())
        veerLeft(75, 30, 1);

    while(!isTracking())
        veerRight(75, 30, 1);
}

void trackLine()
{
    getToLine();
    
    score();
}

void run()
{
    trackLine();
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

    moveForward(100, 200);

    while(!isTracking())
        spinLeft(100, 1);    
}
