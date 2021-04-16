frontSensors[0] = robot->getDistanceSensor("ps7");
frontSensors[0]->enable(timeStep);
frontSensors[1] = robot->getDistanceSensor("ps0");
frontSensors[1]->enable(timeStep);

rightSensors[0] = robot->getDistanceSensor("ps1");
rightSensors[0]->enable(timeStep);
rightSensors[1] = robot->getDistanceSensor("ps2");
rightSensors[1]->enable(timeStep);

leftSensors[0] = robot->getDistanceSensor("ps5");
leftSensors[0]->enable(timeStep);
leftSensors[1] = robot->getDistanceSensor("ps6");
leftSensors[1]->enable(timeStep);