#include <kipr/botball.h>
#include "chassis.h"
#include "util.h"
#include "servos.h"

class Score
{
public:
    Score();
    virtual ~Score();

public:
    run();

protected:
    void getToZone();
    void returnToLine();

};

class ScoreUtilites : protected Score
{
public:
    ScoreUtilites();
    virtual ~ScoreUtilities();
private:
    // TODO: Add in private globals that I used.
};