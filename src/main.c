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

#include <kipr/botball.h>
#include "util.h"
#include "servos.h"
#include "chassis.h"
#include "score.h"
#include "camerafunc.h"
#include "cammath.h"
#include "draw.h"

// You really don't NEED to touch these functions.
// What you do with this base is your business.
int main()
{
    init();
    
	camera_open();
    while(right_button() != 1)
    {
        printf("amt of objects: %d\t", get_object_count(0));
        printf("dist: %f\t", calcDist(0,0));
        printf("confidence: %f\n", get_object_confidence(0, 0));
        if(calcDist(0, 0) <= 230)
            printf("in range!\n");
        
        camera_update();
    }
    
    shutDown();
    return 0;
}
