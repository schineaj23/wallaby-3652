#include <stdbool.h>
#include <kipr/botball.h>

#define LINE_TRACKER 1

void init();

void shutDown();

bool isTracking();

void trackLine();

void correctPos();

void skipLine(int direction, int linesToSkip);

void getToLine();

void trackEdge();