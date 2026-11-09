from controller import Robot
import struct

robot = Robot()
timeStep = int(robot.getBasicTimeStep())
maxVelocity = 6.28
lowBattery = 50  # Below this level (in %), replace the battery on the next contact tile

leftWheel = robot.getDevice("left wheel motor")
rightWheel = robot.getDevice("right wheel motor")
leftWheel.setPosition(float("inf"))
rightWheel.setPosition(float("inf"))

leftDist = robot.getDevice("leftDist")
frontDist = robot.getDevice("frontDist")
rightDist = robot.getDevice("rightDist")
colorSensor = robot.getDevice("color")
for sensor in [leftDist, frontDist, rightDist, colorSensor]:
    sensor.enable(timeStep)

emitter = robot.getDevice("emitter")
receiver = robot.getDevice("receiver")
receiver.enable(timeStep)

# region battery
battery = 100.0  # The last battery level received, in %
lastAsked = -1.0

def readBattery():
    # Asks for the game information once a second, and keeps the battery level up to date
    global battery, lastAsked
    if robot.getTime() - lastAsked >= 1:
        emitter.send(struct.pack("c", b"G"))
        lastAsked = robot.getTime()
    while receiver.getQueueLength() > 0:
        data = receiver.getBytes()
        if len(data) == 20:  # The game information
            battery = struct.unpack("c f i i f", data)[4]
        receiver.nextPacket()
# endregion

# region contact
def onContactTile():
    image = colorSensor.getImage()
    r = colorSensor.imageGetRed(image, 1, 0, 0)
    g = colorSensor.imageGetGreen(image, 1, 0, 0)
    b = colorSensor.imageGetBlue(image, 1, 0, 0)
    return r < 60 and g > 200 and b > 200  # Cyan

def drive(left, right, ms):
    # Keeps the same speeds for a number of milliseconds
    leftWheel.setVelocity(left)
    rightWheel.setVelocity(right)
    start = robot.getTime()
    while robot.step(timeStep) != -1 and (robot.getTime() - start) * 1000 < ms:
        readBattery()

def replaceBattery():
    # The colour sensor is at the front: drive on, so that the centre of the robot is on the tile
    drive(0.5 * maxVelocity, 0.5 * maxVelocity, 1000)
    print("Replacing the battery at", round(battery, 1), "%")
    leftWheel.setVelocity(0)
    rightWheel.setVelocity(0)
    start = robot.getTime()
    # Stay still until the battery is full, which takes 5 seconds
    while robot.step(timeStep) != -1 and battery < 100 and robot.getTime() - start < 8:
        readBattery()
    print("Battery:", round(battery, 1), "%")
# endregion

# region loop
while robot.step(timeStep) != -1:
    readBattery()
    if onContactTile() and battery < lowBattery:
        replaceBattery()

    speeds = [maxVelocity, maxVelocity]
    if frontDist.getValue() < 0.05:    # Wall in front: spin
        speeds = [0.6 * maxVelocity, -0.6 * maxVelocity]
    elif leftDist.getValue() < 0.05:   # Wall on the left: turn right
        speeds = [0.6 * maxVelocity, -0.2 * maxVelocity]
    elif rightDist.getValue() < 0.05:  # Wall on the right: turn left
        speeds = [-0.2 * maxVelocity, 0.6 * maxVelocity]
    leftWheel.setVelocity(speeds[0])
    rightWheel.setVelocity(speeds[1])
# endregion
