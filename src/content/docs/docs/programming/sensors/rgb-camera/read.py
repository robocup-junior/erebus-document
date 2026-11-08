from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

camera = robot.getDevice("camera")
camera.enable(timeStep)
width = camera.getWidth()
height = camera.getHeight()
print("The camera has", width, "x", height, "pixels")

while robot.step(timeStep) != -1:
    image = camera.getImage()
    # The colour of the pixel in the center of the image
    r = camera.imageGetRed(image, width, width // 2, height // 2)
    g = camera.imageGetGreen(image, width, width // 2, height // 2)
    b = camera.imageGetBlue(image, width, width // 2, height // 2)
    print("Center:", r, g, b)
