#include <kipr/botball.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chassis.h"
#include "util.h"
#include "score.h"
#include "servos.h"


double calcDist(int channel, int object);

int getDimensions(char axis, int object, int channel);

void setCameraHeight(int h);

void setObjectHeight(int h);

double getCameraHeight();

double getObjectHeight();

double distTicks(int dist);

bool isTrackable(int channel, int object);