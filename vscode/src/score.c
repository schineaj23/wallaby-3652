#include "score.h"
#include "camerafunc.h"

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

        printf("Looping...\n[Left Counter]:\t%d\n[Right Counter]:\t%d\n", leftCounter, rightCounter); // For Debugging purposes
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

void scoreCrate() // NOTE: This code has not been tested.
{
    /*
    	Assuming that the robot is already on the line and at the middle area.
    */
    
    while(!isTracking()) // Getting the robot to skip over the tracking line 
        turnLeft(100, 1);
    
    while(isTracking())
        turnLeft(100, 1);
     
    // Robot now has skipped tracking line, and now is on line towards the crate.
    
    trackToDist(800);
        
    setupCamera("crate"); 

    /*	
    	entire camera functions are called in this
    	tbh idk why we NEED to use the camera but pretty cool :)
    	anyway, this code should see if the crate is in range to be grabbed, then grab it
   	*/
    
    
 	while(isTracking()) // Turn around towards the scoring zone.
        spinRight(100, 1);
    
    trackToDist(800); // Track until we hit the line we skipped.
    
    skipLine(FORWARD, 2); // Skip the tracking line and the scoring zone line, into the zone.
    
    returnToLine(); // Return to the line as usual, then go to the next scoring zone.
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
        if(i==1) 
        {
            scoreCrate(); // When in the middle of the field
            continue;
        }
        
        trackToDist(3500);	

        //get to scoring zone
        getToZone();

        //Skip line into the zone
        skipLine(FORWARD, 1);

        //move forward into the zone
        moveForward(100, 500);

        returnToLine();
    }
}
