#include <kipr/botball.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chassis.h"
#include "util.h"
#include "score.h"
#include "servos.h"

double calcDist(int channel, int object);

double distTicks(int dist);

bool isTrackable(int channel, int object);