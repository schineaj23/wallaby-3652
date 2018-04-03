#include "cammath.h"
#include "draw.h"
#include <kipr/camera.h>
#include <kipr/geom.h>

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


short idk_the_name(int color)
{
    int h = get_camera_height();
    int w = get_camera_width();
    char *image = get_camera_frame();
    short[][] pos;
    int x, y;
    for(x=0;x<h;x++)
        for(y=0;y<w;y++)
        {
            point2 p2;
            p2.x = x; p2.y = y;
            pixel p = get_camera_pixel(p2);
            int color = p2.g;
            pos[x][y] = &image + sizeof(image) + (h*x + y);
        }
}
