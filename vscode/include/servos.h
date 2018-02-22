#include <kipr/botball.h>

#define SERVO_CLAW_MOTOR 1
#define SERVO_ARM_MOTOR 0

void openClaw();

void closeClaw();

void wave(int amt);

void armUp(int pos, int time);

void armDown(int pos, int time);