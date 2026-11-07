#Create objects for all robot sensors
leftDist = robot.getDevice("leftDist")      # Get robot's left distance sensor
leftDist.enable(timeStep)     # Enable left distance sensor

frontDist = robot.getDevice("frontDist")
frontDist.enable(timeStep)

rightDist = robot.getDevice("rightDist")
rightDist.enable(timeStep)

cam = robot.getDevice("camera")
cam.enable(timeStep)

colorSensor = robot.getDevice("color")
colorSensor.enable(timeStep)

emitter = robot.getDevice("emitter")    # Emitter doesn't need enable

gps = robot.getDevice("gps")
gps.enable(timeStep)