#include <kipr/botball.h>
#include <stdlib.h>
#include <stdbool.h>


#include "chassis.h"
#include "util.h"
#include "score.h"
#include "servos.h"

void setupCamera(const char* config);

void run();

void calcDist(void);
void calcDist(int object);