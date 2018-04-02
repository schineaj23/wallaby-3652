#include <stdbool.h>
#include <kipr/botball.h>
#include <math.h>
#include "util.h"
#include "chassis.h"
#include "score.h"

#define NOT_TRACKING() analog(LINE_TRACKER) < 1000
#define TRACKING() analog(LINE_TRACKER) > 1000
#define FORWARD 0
#define BACKWARD 1


void init() 
{
    wait_for_light(LIGHT_SENSOR);
    
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

void run()
{
    getToLine();
    score();
}

void getToLine()
{
    // Add your code here.
}