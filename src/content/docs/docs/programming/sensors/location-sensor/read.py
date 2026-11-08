from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

gps = robot.getDevice("gps")
gps.enable(timeStep)

while robot.step(timeStep) != -1:
    x, y, z = gps.getValues()  # In meters. X and Z are horizontal, Y is vertical.
    print("x:", round(x, 3), "z:", round(z, 3))
