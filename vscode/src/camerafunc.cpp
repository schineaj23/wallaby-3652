#include "camerafunc.hpp"

CameraFunction::CameraFunction(): STD_OBJECT_HEIGHT_MM(30), CAMERA_HEIGHT(0)
{
    
}

CameraFunction(const char* config): STD_OBJECT_HEIGHT_MM(30), CAMERA_HEIGHT(0)
{
    camera_load_config(config);

    
}