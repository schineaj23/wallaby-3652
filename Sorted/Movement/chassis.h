#include <kipr/botball.h>

#define LEFT_MOTOR 1
#define RIGHT_MOTOR 0

#define FORWARD 0
#define BACKWARD 1

void moveForward(int speed, int time);

void moveBackward(int speed, int time);

void spinLeft(int speed, int time);

void spinRight(int speed, int time);

void veerRight(int speed, int veerOffset, int time);

void veerLeft(int speed, int veerOffset, int time);

void turnLeft(int speed, int time);

void turnRight(int speed, int time);

void skipLine(int direction, int linesToSkip);

void skipToEdge(int direction, int linesToSkip);

void stopAtEdge(int direction);

void trackEdge();

void trackToDist(int distance);
