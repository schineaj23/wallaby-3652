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
    if(!readyScore())
        return;

    closeClaw();

    spinLeft(100, 1000);

    while(!isTracking())
        moveForward(100, 1);

    moveForward(100, 500);

    openClaw();

    while(!isTracking())
        moveBackward(100, 1);

    spinRight(100, 1000);

    while(!isTracking())
        moveForward(100, 1);
    
    trackLine();
    
   	cmpc(LEFT_MOTOR);
    cmpc(RIGHT_MOTOR);
}
