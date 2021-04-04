from controller import Robot

timeStep = 32            # Set the time step for the simulation
max_velocity = 6.28      # Set a maximum velocity time constant

robot = Robot()

wheel_left = robot.getMotor("left wheel motor")   # Create an object to control the left wheel
wheel_right = robot.getMotor("right wheel motor") # Create an object to control the right wheel

leftSensors = []      # Create an empty list to store the left sensor values
rightSensors = []     # Create an empty list to store the right sensor values
frontSensors = []     # Create an empty list to store the front sensor values
