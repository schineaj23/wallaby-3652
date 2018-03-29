#include "cammath.h"
#include "draw.h"

// Defaults for crates.
const double OBJECT_HEIGHT_MM = 101.6;
const double CAMERA_HEIGHT_MM = 185;

double calcDist(int channel, int object)
{
    if(isTrackable(channel, object)) 
        return ((double)get_object_bbox_height(channel, object) / ((double)get_camera_height()))*508;
    
   	return -1;
}

double distTicks(int dist)
{
    return dist*159;
}

bool isTrackable(int channel, int object)
{
    if(get_object_confidence(channel, object) >= 0.5) return true;
    return false;
}

