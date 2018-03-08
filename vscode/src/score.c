#include "score.h"

#define FORWARD 0
#define BACKWARD 1

void trackToDist(int distance)
{
    cmpc(LEFT_MOTOR);
    cmpc(RIGHT_MOTOR);
    
    int leftCounter = gmpc(LEFT_MOTOR);
    int rightCounter = gmpc(RIGHT_MOTOR);
    
    while(leftCounter <= distance) 
    {
        if(isTracking())
            veerLeft(100, 30, 1);
        else
            veerRight(100, 30, 1);
        
        leftCounter = gmpc(LEFT_MOTOR);
        rightCounter = gmpc(RIGHT_MOTOR);
        printf("Looping...\nLeft:\t%d\nRight:\t%d\n", leftCounter, rightCounter);
    }
}

void score()
{
    trackToDist(3000);	

    closeClaw();

    //Turn towards scoring zone
    spinLeft(60, 900);

    //Skip line into the zone
    skipLine(FORWARD, 2);

    //move forward into the zone
    moveForward(100, 500);

    openClaw();

    //skip line out of zone
    skipLine(BACKWARD, 2);

    while(!isTracking())
        spinRight(100, 1);

    //move towards line until starts trackin
    //clear motor counters
        
    cmpc(LEFT_MOTOR);
    cmpc(RIGHT_MOTOR);
}

