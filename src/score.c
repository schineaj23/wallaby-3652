#include "score.h"
#include "camerafunc.h"

#define FORWARD 0
#define BACKWARD 1

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
    // Add your code here.
}

//Main scoring function. 
void score()
{
    // Add your code here.
}
