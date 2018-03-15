#include "camerafunc.h"

#define STD_OBJECT_HEIGHT_MM 30
#define CAMERA_HEIGHT_MM 100

#define x 'x'
#define y 'y'
#define z 'z'

bool cameraEnabled = false;

// Setup Camera, defacto "constructor" of the camera "class".
// Specify config, this function doesn't do much, I just don't like using camera_open() and camera_load_config()
void setupCamera(const char* config)
{
    camera_open_black();
    
    if(camera_open_black() != 1)
        return;

    camera_load_config(config);
    
    cameraEnabled = true;

    while(cameraEnabled)
        run();
}

// Get dimensions of an object. This is a messy function at the time.
// Will fix, but comes in handy when doing algorithims.
int getDimensions(char axis, int channel, int object)
{
    switch(axis)
    {
     case 'x':
            return get_object_bbox_width(channel, object);
            break;
        case 'y':
            return get_object_bbox_height(channel, object);
            break;
        default:
            break;
    } 
    return 0;
}


// Calculate Distance to an object using focal height and length algorithim. Default Function.
int calcDist()
{
    return (STD_OBJECT_HEIGHT_MM * get_camera_height()) / (getDimensions(y, 0, 0));
}

// Calculate Distance to an object using focal height and length algorithim.
// Couldn't overload in C, so use this when you want to choose the object and channel of your liking.
int calcDistEx(int channel, int object) // change channel, change object
{
    return (STD_OBJECT_HEIGHT_MM * get_camera_height()) / (getDimensions(y, channel, object));
}

// Main function of the camera. Use this either in score() or run().
void runCamera()
{
    if(!cameraEnabled)
        return;
         
    //TODO: Add code. xd         
}