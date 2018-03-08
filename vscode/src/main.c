#include <kipr/botball.h>
#include "util.h"
#include "servos.h"
#include "chassis.h"

int main()
{
    init();
    
    run();
    
    shutDown();
    return 0;
}
