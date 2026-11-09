from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

colorSensor = robot.getDevice("color")
colorSensor.enable(timeStep)
leftWheel = robot.getDevice("left wheel motor")
rightWheel = robot.getDevice("right wheel motor")
leftWheel.setPosition(float("inf"))
rightWheel.setPosition(float("inf"))

def floorType(r, g, b):
    # Tune these ranges for your own robot and worlds
    brightness = (r + g + b) / 3
    if brightness < 80:
        return "hole"
    if r > 200 and g > 170 and b < 150:
        return "swamp"
    if r < 60 and g > 200 and b > 200:
        return "contact tile"
    if b > 220 and g < 130:
        return "purple passage" if r > 150 else "blue passage"
    if r > 220 and g < 130 and b < 130:
        return "red passage"
    if g > 220 and r < 100 and b < 100:
        return "green passage"
    return "floor"

leftWheel.setVelocity(3.0)
rightWheel.setVelocity(3.0)
last = None

while robot.step(timeStep) != -1:
    image = colorSensor.getImage()
    floor = floorType(colorSensor.imageGetRed(image, 1, 0, 0),
                      colorSensor.imageGetGreen(image, 1, 0, 0),
                      colorSensor.imageGetBlue(image, 1, 0, 0))
    if floor != last:
        print("Floor:", floor)
        last = floor
    if floor == "hole":  # Stop before falling in
        leftWheel.setVelocity(0)
        rightWheel.setVelocity(0)
        break
