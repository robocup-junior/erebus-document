#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>

using namespace webots;

int main() {	
    Robot *robot = new Robot(); // Create robot object
    int timeStep = (int)robot->getBasicTimeStep();  // timeStep = number of milliseconds between world updates

    Motor *leftMotor = robot->getMotor("wheel1 motor");    // Motor initialization
    Motor *rightMotor = robot->getMotor("wheel2 motor");
    leftMotor->setPosition(INFINITY);
    rightMotor->setPosition(INFINITY);

    PositionSensor *leftEncoders = leftMotor->getPositionSensor();     // Encoder initialization
    PositionSensor *rightEncoders = rightMotor->getPositionSensor();
    leftEncoders->enable(timeStep);
    rightEncoders->enable(timeStep);

    leftMotor->setVelocity(5.0);
    rightMotor->setVelocity(5.0);

    while (robot->step(timeStep) != -1) {
        if (leftEncoders->getValue() > 20.0) // If left motor has spun more than 20 radians
            break;
    };

    leftMotor->setVelocity(0.0);
    rightMotor->setVelocity(0.0);
    
    delete robot;
    return 0;
}