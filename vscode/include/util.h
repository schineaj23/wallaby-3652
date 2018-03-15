#include <stdbool.h>
#include <kipr/botball.h>

#define LIGHT_SENSOR 0
#define LINE_TRACKER 1

void init();

void shutDown();

bool isTracking();

void trackLine();

void correctPos();

void skipLine(int direction, int linesToSkip);

void skipToEdge(int direction, int linesToSkip);

void stopAtEdge(int direction);

void getToLine();

void trackEdge();

void run();