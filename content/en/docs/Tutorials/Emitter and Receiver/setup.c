#include <iostream>

#include <webots/Robot.hpp>
#include <webots/Receiver.hpp> // Include Receiver.hpp and Emitter.hpp
#include <webots/Emitter.hpp>
#include <webots/GPS.hpp> // Include GPS.hpp to read the robot's position

using namespace webots;
using namespace std;

int main(int argc, char **argv) {

  Robot *robot = new Robot();
  
  Emitter* emitter = robot->getEmitter("emitter"); // Retrieve the receiver and emitter by device name
  Receiver* receiver = robot->getReceiver("receiver");
  GPS* gps = robot->getGPS("gps"); // Retrieve the gps by device name

  int timeStep = (int)robot->getBasicTimeStep();
  
  gps->enable(timeStep); // Enable the gps
  receiver->enable(timeStep); // Enable the receiver. Note that the emitter does not need to be enabled.
  
  while (robot->step(timeStep) != -1) {
    
  }
  
  delete robot;
  return 0;
}