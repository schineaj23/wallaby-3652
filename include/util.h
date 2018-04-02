#include <stdbool.h>
#include <kipr/botball.h>

#define LIGHT_SENSOR 0
#define LINE_TRACKER 1

void init();

void shutDown();

bool isTracking();

void run();