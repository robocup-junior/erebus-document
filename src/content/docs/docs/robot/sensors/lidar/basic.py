from controller import Robot, Lidar # Step 1: Import Lidar

robot = Robot()

lidar = robot.getDevice("lidar") # Step 2: Retrieve the sensor, named "lidar", from the robot. Note that the sensor name may differ between robots.

timestep = int(robot.getBasicTimeStep())

lidar.enable(timestep) # Step 3: Enable the sensor, using the timestep as the update rate

while robot.step(timestep) != -1:
    
    rangeImage = lidar.getRangeImage(); # Step 4: Retrieve the range image
    
    # Print the first 10 values of the range image.
    # The range image stores the distances from left to right, from first to last layer
    for i in range(10):
        print(str(rangeImage[i]) + " ", end='')
        
    print('')