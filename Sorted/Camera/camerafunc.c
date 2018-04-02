#include "camerafunc.h"
#include "cammath.h"

char* g_config = "NULL";

// Specify config, this function doesn't do much, I just don't like using camera_open() and camera_load_config()
bool setupCamera(const char* config)
{
    if(g_config != "NULL") return false;
    camera_open_black();
    if(camera_open_black() != 1) return false;
    camera_load_config(config);
    g_config = config;
    return true;
}

void updateCamera()
{
    if(!setupCamera(g_config)) return;
    while(cameraEnabled)
    {
        runCamera(config);
        if(camera_update() != 1) return;
    }
    camera_close();
}

// Main function of the camera. Use this either in score() or run().
void runCamera()
{
    if(!setupCamera(g_config)) return;

    openClaw();
    if(isTrackable(0, 0) && calcDist(0, 0) <= 240)
    {
        closeClaw();
        while(!right_button())
            printf("ready to stop! please stop!\n");
    }
}