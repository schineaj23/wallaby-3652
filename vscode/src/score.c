#include "score.h"

#define TURN_COUNT 2500

bool readyScore()
{    
    int leftCounter = gmpc(LEFT_MOTOR);
    int rightCounter = gmpc(RIGHT_MOTOR);
   
    if(leftCounter == TURN_COUNT && rightCounter == TURN_COUNT)
    {
        return true;
    }
    return false;
}


void score()
{

    //While it isn't ready to score, wait 1Msec
    while(!readyScore())
        msleep(1);

    closeClaw();

    //Turn towards scoring zone
    spinLeft(100, 1000);

    //Skip line into the zone
    skipLine(FORWARD, 1);

    //move forward into the zone
    moveForward(100, 500);

    openClaw();

    //skip line out of zone
    skipLine(BACKWARD, 1);

    //turn towards line
    spinRight(100, 1000);

    //move towards line until starts tracking
    while(!isTracking())
        moveForward(100, 1);
    
    //go back to executing trackLine() function
    trackLine();
    
    //clear motor counters
   	cmpc(LEFT_MOTOR);
    cmpc(RIGHT_MOTOR);
}
