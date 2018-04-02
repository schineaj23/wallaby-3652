#include "chassis.h"

void moveForward(int speed, int time)
{
    motor(LEFT_MOTOR, speed*0.85); // TODO: Fix wheel veering problem.
    motor(RIGHT_MOTOR, speed);
	msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void moveBackward(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-0.85);
    motor(RIGHT_MOTOR, speed*-1);
	msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void spinLeft(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-1);
    motor(RIGHT_MOTOR, speed);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void spinRight(int speed, int time)
{
    motor(LEFT_MOTOR, speed);
    motor(RIGHT_MOTOR, speed*-1);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}


void veerRight(int speed, int veerOffset, int time)
{
    motor(LEFT_MOTOR, speed*0.85);
    motor(RIGHT_MOTOR, speed-veerOffset);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void veerLeft(int speed, int veerOffset, int time)
{
    motor(RIGHT_MOTOR, speed);
    motor(LEFT_MOTOR, speed-veerOffset*0.85);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void turnLeft(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-0.85);
    msleep(time);
   	motor(LEFT_MOTOR, 0);
}

void turnRight(int speed, int time)
{
    motor(RIGHT_MOTOR, speed*-1);
    msleep(time);
    motor(RIGHT_MOTOR, 0);
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

void skipToEdge(int direction, int linesToSkip) 
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
        else
        {
            while(!isTracking())
                moveBackward(100, 1);
            while(isTracking())
                moveBackward(100, 1);
        }     
    }
    stopAtEdge(direction);
}

// Stop at the next edge, very applyable.
// Use this instead of while loops
void stopAtEdge(int direction)
{
    if(isTracking())  { // Checks if currently tracking
      while(isTracking())
        direction == FORWARD ? moveForward(100, 1) : moveBackward(100,1); }
    else {
        while(!isTracking())
            direction == FORWARD ? moveForward(100, 1) : moveBackward(100,1); }
}

// Edge tracking.
void trackEdge() 
{
    while(isTracking())
        veerRight(75, 30, 1);

    while(!isTracking())
        veerLeft(75, 30, 1);
}

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
    }
}

