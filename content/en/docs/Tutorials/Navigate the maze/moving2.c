//Inside of main
leftDist = robot->getDistanceSensor("leftDist");    // Grab robot's left distance sensor
leftDist->enable(timeStep);     // Enable the distance sensor

frontDist = robot->getDistanceSensor("frontDist");
frontDist->enable(timeStep);

rightDist = robot->getDistanceSensor("rightDist");
rightDist->enable(timeStep);

cam = robot->getCamera("camera");
cam->enable(timeStep);

colorSensor = robot->getCamera("color");
colorSensor->enable(timeStep);

emitter = robot->getEmitter("emitter");     // Emitter doesn't need enable

gps = robot->getGPS("gps");
gps->enable(timeStep);