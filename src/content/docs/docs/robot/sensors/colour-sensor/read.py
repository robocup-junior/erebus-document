from controller import Robot

robot = Robot()
timestep = int(robot.getBasicTimeStep())

colorSensor = robot.getDevice("colour_sensor")
colorSensor.enable(timestep)

while robot.step(timestep) != -1:
    image = colorSensor.getImage()
    r = colorSensor.imageGetRed(image, 1, 0, 0)
    g = colorSensor.imageGetGreen(image, 1, 0, 0)
    b = colorSensor.imageGetBlue(image, 1, 0, 0)
    print(r, g, b)
