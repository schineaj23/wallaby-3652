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
            veerLeft(100, 30, 1);
        else
            veerRight(100, 30, 1);
        
        leftCounter = gmpc(LEFT_MOTOR);
        rightCounter = gmpc(RIGHT_MOTOR);
        printf("Looping...\nLeft:\t%d\nRight:\t%d\n", leftCounter, rightCounter); // For Debugging purposes
    }
}

void getToZone()
{
    //Turn towards scoring zone
    spinLeft(60, 900);

    //Skip line into the zone
    skipLine(FORWARD, 2);
}

void returnToLine()
{
    //skip to edge of linetracking line
    skipToEdge(BACKWARD, 1);

    while(isTracking())
        turnRight(100, 1);
}

void score()
{
    int i;
    for(i=0; i<4; i++)
    {
        trackToDist(3000); // Track line until distance

        getToZone(); // Get into scoring zone

        moveForward(100, 500); // Move forward in zone to ensure poms are in.

        // Return  
        returnToLine();

        // Clear motors for next rep.
        cmpc(LEFT_MOTOR);
        cmpc(RIGHT_MOTOR);
    }
}

