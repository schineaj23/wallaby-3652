#include "camerafunc.h"
#include <kipr/geom.h>

#define STD_OBJECT_HEIGHT_MM 30
#define CAMERA_HEIGHT_MM 100

#define x 'x'
#define y 'y'
#define z 'z'

void setupCamera(const char* config)
{
    camera_open_black();

    camera_load_config(config);

    while(1 == 1)
        run();
}

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


//owo overloaded functions

int calcDist(void) //Default
{
    return (STD_OBJECT_HEIGHT_MM * get_camera_height()) / (getDimensions(y, 0, 0));
}

int calcDist(int channel, int object) // change channel, change object
{
    return (STD_OBJECT_HEIGHT_MM * get_camera_height()) / (getDimensions(y, channel, object));
}


void run()
{
    while(!cameraEnabled)
        return;

    //TODO: Add code. xd         
}