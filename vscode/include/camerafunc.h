#include <kipr/botball.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chassis.h"
#include "util.h"
#include "score.h"
#include "servos.h"

void setupCamera(const char* config);

void runCamera();

int calcDist();
int calcDistEx(int channel, int object);