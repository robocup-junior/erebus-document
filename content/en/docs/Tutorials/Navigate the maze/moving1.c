#include <webots/Robot.hpp>
using namespace webots;
...

//Inside main:
Robot *robot = new Robot();

int timeStep = (int)robot->getBasicTimeStep();      // Set the time step for the simulation
float max_velocity = 6.28;                          // Set a maximum velocity time constant

Motor *wheel_left = robot->getMotor("left wheel motor");     // Create an object to control the left wheel
Motor *wheel_right = robot->getMotor("right wheel motor");   // Create an object to control the right wheel

DistanceSensor *leftSensors[2];     // Create an empty array to store the left sensor values
DistanceSensor *rightSensors[2];     // Create an empty array to store the right sensor values
DistanceSensor *frontSensors[2];     // Create an empty array to store the front sensor values