#include <kipr/botball.h>
#include "util.h"
#include "servos.h"
#include "chassis.h"
#include "score.h"
#include "camerafunc.h"
#include "cameramath.h"
#include "draw.h"

// Main function of the base.
int main()
{
    init();
    
    run();
    
    shutDown();
    return 0;
}
