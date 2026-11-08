from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

lidar = robot.getDevice("lidar")
lidar.enable(timeStep)
n = lidar.getHorizontalResolution()  # Number of points in each layer
print("Points per layer:", n, "Layers:", lidar.getNumberOfLayers())

while robot.step(timeStep) != -1:
    distances = lidar.getLayerRangeImage(0)  # One layer, in meters, clockwise from the front
    front = distances[0]
    right = distances[n // 4]
    back = distances[n // 2]
    left = distances[3 * n // 4]
    print("front:", round(front, 3), "right:", round(right, 3), "back:", round(back, 3), "left:", round(left, 3))
