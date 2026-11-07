from controller import Robot, Lidar

robot = Robot()

lidar = robot.getDevice("lidar")

timestep = int(robot.getBasicTimeStep())

lidar.enable(timestep)
lidar.enablePointCloud(); # Enable the point cloud computation

while robot.step(timestep) != -1:
    
    lidarPoints = lidar.getPointCloud(); # Get the point cloud

    # Print out the x, y, z, and layer information for the first point in the point cloud    
    print("x: " + str(lidarPoints[0].x) + " y: " + str(lidarPoints[0].y) + " z: " + str(lidarPoints[0].z) + " layer: " + str(lidarPoints[0].layer_id))
        