#include <stdbool.h>
#include "util.h"
#include "chassis.h"
#include "score.h"

#define NOT_TRACKING() analog(LINE_TRACKER) < 800
#define TRACKING() analog(LINE_TRACKER) > 800
#define FORWARD 0
#define BACKWARD 1


// This is kind of like the constructor of the program. 
// Add any code that you want before program starts
// e.g reset motors, etc.
void init() 
{
    enable_servos();
}

//Destructor
void shutDown() 
{
    disable_servos();
    ao();
}

// Check if is tracking
// Usually used in the skipLine() and correctPos() functions
// Can be used in custom functions though.
bool isTracking() 
{
    if(TRACKING())
        return true;

    return false;
}

// Skip line. Very useful, use this instead of while conditionals
// Parameters: direction-> FORWARD = 0, BACKWARD = 1 Pretty sure these are defined in util.h,
// So you don't have to use the direction as if magic numbers
// 2nd Parameter: linesToSkip -> How many lines you want to skip.
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

            printf("no longer tracking, line #%d has been skipped\n",i);
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

// This is your edge Tracking function.
// It tracks the right edg.
// You can change this by swapping the veerLeft and Right functions
void correctPos() 
{
    while(isTracking())
        veerLeft(75, 30, 1);

    while(!isTracking())
        veerRight(75, 30, 1);
}

void trackLine()
{
    // TODO: Add general code here for linetracking, not for specific score function
}


// Main Function, call this instead of in main.c helps keep code organized.
void run()
{
    getToLine();
    
    score();
}

// Function used for getting to the line we want to track.
// You can change this if you want. It should be to suit your needs.
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
