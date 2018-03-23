#include <stdlib.h>
#include <stdbool.h>

#include <kipr/botball.h>
#include <kipr/graphics.h>
#include <kipr/graphics_characters.h>

//Global variables in headers! Whee!
float STD_SIZE 30;

bool drawEnabled = false;

void initDraw(int w, int h)
{
    graphics_open(w, h);

    drawEnabled = true;
}

void disableDraw()
{
    graphics_clear();
    graphics_close();

    drawEnabled = false;
}

void checkEnabled()
{
    if(!drawEnabled)
        return;
}

void setTextSize(float size)
{
    size = STD_SIZE;
}

float getTextSize()
{
    return STD_SIZE;
}

typedef struct Vector2D // Simple vector if wanting to work with more drawing logic
{
    int x, y;
} Vector;

typedef struct Vector3D // Vector for 3D space
{
    int x, y, z;
} Vector3;

Vector3 vectorNormalize(Vector3 vec) // idk why I put this in tbh
{
    return sqrt(vec.x*vec.x + vec.y*vec.y)
}

// Drawing functions.
// These can be used standalone, but then they can't be updated.
// Just call them in draw(). These really don't have effect without.

void drawString(char* pText, int x, int y, int r, int g, int b)
{
    checkEnabled();
    graphics_printString(pText, x, y, r, g, b, getTextSize());
}

void drawNum(float num, int x, int y, int r, int g, int b)
{
    checkEnabled();   
    graphics_printFloat(num, 32, x, y, r, g, b, getTextSize()); // I mean it shouldn't be higher than 32 right?
}

void drawCircle(int x, int y, int radius, int r, int g, int b)
{
    checkEnabled();
    graphics_circle_fill(x, y, radius, r, g, b);
}

void drawTrig(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b)
{
    checkEnabled();
    graphics_triangle_fill(x1, y1, x2, y2, x3, y3, r, g, b);
}

void drawRect(int x1, int y1, int x2, int y2, int r, int g, int b)
{
    checkEnabled();
    graphics_rectangle_fill(x1, y1, x2, y2, r, g, b);
}

void drawColor(int r, int g, int b)
{
    checkEnabled();
    graphics_fill(r, g, b);
}

void render()
{
    initDraw(800, 600);

    while(drawEnabled)
    {
        graphics_clear();

        draw();

        graphics_update();
    }

    disableDraw();

}
