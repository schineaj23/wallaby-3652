#include <stdlib.h>
#include <stdbool.h>
#include <cstring>

#include <kipr/botball.h>
#include <kipr/graphics.h>
#include <kipr/graphics_characters.h>

#define STD_SIZE setTextSize(30)

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

float setTextSize(float size)
{
    return size;
}

typedef struct Vector // Simple vector if wanting to work with more drawing logic
{
    int x, y;
};


// Drawing functions.
// These can be used standalone, but then they can't be updated.
// Just use draw(). These really don't have effect without.

void drawString(char* pText, int x, int y, int r, int g, int b)
{
    checkEnabled();
    graphics_printString(pText, x, y, r, g, b, STD_SIZE);
}

void drawNum(float num, int x, int y, int r, int g, int b)
{
    checkEnabled();   
    graphics_printString(to_string(num).c_str(), x, y, r, g, b, STD_SIZE)
}

void drawCircle(int x, int y, int radius, int r, int g, int b)
{
    checkEnabled();
    graphics_circle_fill(x, y, radius, r, g, b);
}

void drawTrig(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b)
{
    checkEnabled();
    graphics_triangle_fill	(x1, y1, x2, y2, x3, y3, int r, int g, int b);
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
    initDraw();

    while(drawEnabled)
    {
        graphics_clear();

        draw();

        graphics_update();
    }

    disableDraw();

}