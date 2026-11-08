from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

# Get the devices of the starter robot by name
leftWheel = robot.getDevice("left wheel motor")
rightWheel = robot.getDevice("right wheel motor")
frontDist = robot.getDevice("frontDist")

# Sensors must be enabled before use
frontDist.enable(timeStep)

# Let the wheels turn without limit, and start driving forward
leftWheel.setPosition(float("inf"))
rightWheel.setPosition(float("inf"))
leftWheel.setVelocity(3.0)
rightWheel.setVelocity(3.0)

# The main loop: each step, the simulation advances by timeStep milliseconds
while robot.step(timeStep) != -1:
    distance = frontDist.getValue()
    print("Distance to the wall in front:", round(distance, 3), "m")

    if distance < 0.05:  # Closer than 5 cm: stop
        leftWheel.setVelocity(0)
        rightWheel.setVelocity(0)
        print("Wall reached!")
        break
