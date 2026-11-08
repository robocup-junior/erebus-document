from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

lidar = robot.getDevice("lidar")
lidar.enable(timeStep)
lidar.enablePointCloud()  # Computing the point cloud takes extra time

while robot.step(timeStep) != -1:
    points = lidar.getPointCloud()
    point = points[0]  # Positions relative to the lidar, in meters
    print("x:", round(point.x, 3), "y:", round(point.y, 3), "z:", round(point.z, 3), "layer:", point.layer)
