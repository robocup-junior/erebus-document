#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Camera.hpp>
#include <webots/Emitter.hpp>
#include <webots/GPS.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace webots;
using namespace cv;
using namespace std;

Robot *robot = new Robot();

int timeStep = (int)robot->getBasicTimeStep();      // Set the time step for the simulation
float max_velocity = 6.27;                          // Set a maximum velocity time constant

Motor *leftMotor = robot->getMotor("wheel1 motor");     // Create an object to control the left wheel
Motor *rightMotor = robot->getMotor("wheel2 motor");   // Create an object to control the right wheel

DistanceSensor *leftDist, *frontDist, *rightDist; // Objects for left, front, and right distance sensor

Camera *cam; // Create an object to control the camera
Camera *colorSensor; // Color sensor is a 1 pixel camera

Emitter *emitter; // Used to send messages to supervisor (report victims/hazards)
GPS *gps;

// [left wheel speed, right wheel speed]
float speeds[2] = { max_velocity, max_velocity };