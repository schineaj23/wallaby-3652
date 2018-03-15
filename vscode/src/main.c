#include <kipr/botball.h>
#include "util.h"
#include "servos.h"
#include "chassis.h"

// You really don't NEED to touch these functions.
// What you do with this base is your business.
int main()
{
    init();
    
    run();
    
    shutDown();
    return 0;
}
