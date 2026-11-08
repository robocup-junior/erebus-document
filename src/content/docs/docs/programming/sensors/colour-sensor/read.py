from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

colorSensor = robot.getDevice("color")
colorSensor.enable(timeStep)

while robot.step(timeStep) != -1:
    image = colorSensor.getImage()  # A single pixel
    r = colorSensor.imageGetRed(image, 1, 0, 0)
    g = colorSensor.imageGetGreen(image, 1, 0, 0)
    b = colorSensor.imageGetBlue(image, 1, 0, 0)
    print("r:", r, "g:", g, "b:", b)
