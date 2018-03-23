#include "camerafunc.h"


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



// Main function of the camera. Use this either in score() or run().
void runCamera()
{
    if(!cameraEnabled)
        return;
         
    //TODO: Add code. xd         
}