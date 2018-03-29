#include <stdlib.h>
#include <stdbool.h>
#include <kipr/botball.h>

// making drawing functions cause bored :c

// TODO: Add better solution
// Than macros for axes
#define x_axis 'x'
#define y_axis 'y'
#define z_axis 'z'

static float STD_SIZE = 30;

static bool drawEnabled = false;

static void initDraw(int w, int h)
{
    graphics_open(w, h);

    drawEnabled = true;
}

static void disableDraw()
{
    graphics_clear();
    graphics_close();
    drawEnabled = false;
}

static void checkEnabled()
{
    if(!drawEnabled) return;
}

static void setTextSize(float size)
{
    size = STD_SIZE;
}

static float getTextSize()
{
    return STD_SIZE;
}


static void drawCircle(int x, int y, int radius, int r, int g, int b)
{
    checkEnabled();
    graphics_circle_fill(x, y, radius, r, g, b);
}

static void drawTrig(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b)
{
    checkEnabled();
    graphics_triangle_fill(x1, y1, x2, y2, x3, y3, r, g, b);
}

static void drawRect(int x1, int y1, int x2, int y2, int r, int g, int b)
{
    checkEnabled();
    graphics_rectangle_fill(x1, y1, x2, y2, r, g, b);
}

static void drawColor(int r, int g, int b)
{
    checkEnabled();
    graphics_fill(r, g, b);
}

void draw();

static void render()
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
