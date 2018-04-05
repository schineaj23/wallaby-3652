///////////////////////////////////////////////////////////////////////////////////////
//
//     _____           _        _     _        _____       _           _   _          
//    |  __ \         | |      (_)   | |      |  __ \     | |         | | (_)         
//    | |__) |_ _ _ __| | _____ _  __| | ___  | |__) |___ | |__   ___ | |_ _  ___ ___ 
//    |  ___/ _` | '__| |/ / __| |/ _` |/ _ \ |  _  // _ \| '_ \ / _ \| __| |/ __/ __|
//    | |  | (_| | |  |   <\__ \ | (_| |  __/ | | \ \ (_) | |_) | (_) | |_| | (__\__ \
//    |_|   \__,_|_|  |_|\_\___/_|\__,_|\___| |_|  \_\___/|_.__/ \___/ \__|_|\___|___/
//
///////////////////////////////////////////////////////////////////////////////////////

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

short findPixel(int b_color)
{
    short color;
    int h = get_camera_height();
    int w = get_camera_width();
    char *image = get_camera_frame();
    short[][] pos;
    int x, y;
    for(x=0;x<w;x++)
        for(y=0;y<h;y++)
        {
            point2 p2;
            p2.x = x; p2.y = y;
            pixel p = get_camera_pixel(p2);
            switch(b_color) {
                case 1: color = p.r; break;
                case 2: color = p.g; break;
                case 3: color = p.b; break;
                default: color = -1;   
            }
            if(color >= 127) {
                short *ret;
                ret = pos;
                return ret;
            }
            pos[x][y] = &image + sizeof(image) + (h*x + y);

            return image;
        }
    return NULL;
}

char* edgeFilter(char *image)
{
    
}