#include <iostream>
#include <webots/Robot.hpp>
#include <webots/Emitter.hpp>

using namespace webots;

int main() {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  Emitter *emitter = robot->getEmitter("emitter");

  robot->step(timeStep);
  std::cout << "Ending the game" << std::endl;
  // Ends the game. Send it on the starting tile, after identifying a token, to get the exit bonus.
  // The game stops your program right after this message.
  char message = 'E';
  emitter->send(&message, 1);
  robot->step(timeStep);

  delete robot;
  return 0;
}
