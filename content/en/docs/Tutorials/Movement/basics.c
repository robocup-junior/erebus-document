#include <webots/Motor.hpp>
...

//Inside main:
Motor *wheel_left = robot->getMotor("wheel1 motor");    //Step 1
Motor *wheel_right = robot->getMotor("wheel2 motor");

wheel_left->setPosition(INFINITY);   //Step 2
wheel_right->setPosition(INFINITY);

wheel_left->setVelocity(5.0);    //Step 3
wheel_right->setVelocity(5.0);