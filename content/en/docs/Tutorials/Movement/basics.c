#include <webots/Motor.hpp>
...

//Inside main:
Motor *leftMotor = robot->getMotor("left wheel motor");    //Step 1
Motor *rightMotor = robot->getMotor("right wheel motor");

leftMotor->setPosition(INFINITY);   //Step 2
rightMotor->setPosition(INFINITY);

leftMotor->setVelocity(5.0);    //Step 3
rightMotor->setVelocity(5.0);