#include <kipr/botball.h>

class CameraFunction
{
public:
    CameraFunction();
    CameraFunction(int objectHeight, int cameraHeight): objectHeight(STD_OBJECT_HEIGHT_MM), cameraHeight(CAMERA_HEIGHT) {};
    CameraFunction(const char* config);

public:
    int x = { return get_object_bbox_width(channel, object) }; 
    int y = { return get_object_bbox_height(channel, object) };

private:
    Run();

private:
    void calcDist();
    void calcDist(int object);

private:
     const int STD_OBJECT_HEIGHT_MM;
     const int CAMERA_HEIGHT_MM;

};