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

#include "camerafunc.h"
#include "cammath.h"

bool cameraEnabled = false;

// Specify config, this function doesn't do much, I just don't like using camera_open() and camera_load_config()
void setupCamera(const char* config)
{
    camera_open_black();
    if(camera_open_black() != 1) return;
    camera_load_config(config);
    cameraEnabled = true;
    while(cameraEnabled)
    {
        runCamera();
        if(camera_update() != 1) return;
    }
    camera_close();
}

// Main function of the camera. Use this either in score() or run().
void runCamera()
{
    if(!cameraEnabled) return;
    openClaw();
    if(isTrackable(0, 0) && calcDist(0, 0) <= 240)
    {
        closeClaw();
        while(!right_button())
            printf("ready to stop! please stop!\n");
    }
}