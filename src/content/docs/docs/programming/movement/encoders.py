from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

leftWheel = robot.getDevice("left wheel motor")
rightWheel = robot.getDevice("right wheel motor")
leftWheel.setPosition(float("inf"))
rightWheel.setPosition(float("inf"))

# Each wheel has a position sensor, which counts how far it has turned
leftEncoder = leftWheel.getPositionSensor()
rightEncoder = rightWheel.getPositionSensor()
leftEncoder.enable(timeStep)
rightEncoder.enable(timeStep)

robot.step(timeStep)  # Step once, so that the sensors have a value
start = leftEncoder.getValue()

leftWheel.setVelocity(5.0)
rightWheel.setVelocity(5.0)

while robot.step(timeStep) != -1:
    turned = leftEncoder.getValue() - start
    if turned > 10.0:  # Stop after 10 radians
        break

leftWheel.setVelocity(0)
rightWheel.setVelocity(0)
print("Left wheel:", round(leftEncoder.getValue() - start, 2), "rad")
