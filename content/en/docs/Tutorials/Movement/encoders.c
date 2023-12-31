#include <webots/PositionSensor.hpp>
...

//Inside main:
PositionSensor *leftEncoders = wheel_left->getPositionSensor();     //Step 1
PositionSensor *rightEncoders = wheel_right->getPositionSensor();

leftEncoders->enable(timeStep);    //Step 2
rightEncoders->enable(timeStep);

printf("Left motor has spun %f radians", leftEncoders->getValue());     //Step 3
printf("Right motor has spun %f radians", rightEncoders->getValue());