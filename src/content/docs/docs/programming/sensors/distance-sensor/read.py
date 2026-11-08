from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

frontDist = robot.getDevice("frontDist")  # Get the sensor by name
frontDist.enable(timeStep)                 # Enable it

while robot.step(timeStep) != -1:
    print("Front:", round(frontDist.getValue(), 3), "m")
