#include "score.h"

#define FORWARD 0
#define BACKWARD 1

void trackToDist(int distance)
{
    cmpc(LEFT_MOTOR);
    cmpc(RIGHT_MOTOR);

    int leftCounter = gmpc(LEFT_MOTOR);
    int rightCounter = gmpc(RIGHT_MOTOR);

    while(leftCounter <= distance) // TODO: Not checking both sides because of veering problem, will fix
    {
        if(isTracking())
            veerRight(100, 30, 1);
        else
            veerLeft(100, 30, 1);

        leftCounter = gmpc(LEFT_MOTOR);
        rightCounter = gmpc(RIGHT_MOTOR);
        printf("Looping...\nLeft:\t%d\nRight:\t%d\n", leftCounter, rightCounter); // For Debugging purposes
    }
}

void returnToLine()
{
    //1. skip line out of zone
    //2. skip linetracking line
    skipToEdge(BACKWARD, 1);

    while(isTracking())
        turnLeft(100, 1);
    
    skipLine(FORWARD, 1);
    
    while(!isTracking())
        veerLeft(100, 70, 1);
}

void getToZone()
{
    //Turn towards scoring zone
    spinRight(60, 900);
}


void score()
{
    int i;
    for(i=0;i<3;i++)
    {
        trackToDist(3500);	

        //get to scoring zone
        getToZone();

        //PUT ACTUAL CODE HERE
        //OTHER FUNCTIONS WERE TO TIDY score()

        //Skip line into the zone
        skipLine(FORWARD, 1);

        //move forward into the zone
        moveForward(100, 500);

        //End scoring code

        returnToLine();
    }
}

void tmp() // Testing function lmao
{
    returnToLine();
}


