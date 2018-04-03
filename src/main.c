#include <kipr/botball.h>
#include "util.h"
#include "servos.h"
#include "chassis.h"
#include "score.h"
#include "camerafunc.h"
#include "cammath.h"
#include "draw.h"

int main()
{
    init();
    
	run();
    
    shutDown();
    return 0;
}
