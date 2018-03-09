#include <kipr/botball.h>
#include <kipr/Camera.hpp>


class CameraFunction
{
public:
    CameraFunction();
    CameraFunction(int objectHeight, int cameraHeight): objectHeight(STD_OBJECT_HEIGHT_MM), cameraHeight(CAMERA_HEIGHT) {};
    CameraFunction(const char* config);

public:
    int x = get_object_bbox_width(m_channel, m_object);
    int y = get_object_bbox_height(m_channel, m_object);

private:
    void Run();

private:
    void calcDist();
    void calcDist(int object);

private:
    int m_object;
    int m_channel;

    int STD_OBJECT_HEIGHT_MM;
    int CAMERA_HEIGHT_MM;

};