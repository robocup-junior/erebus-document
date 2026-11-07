from controller import Robot, Receiver, Emitter # Import Receiver and Emitter

robot = Robot()

receiver = robot.getDevice("receiver") # Retrieve the receiver and emitter by device name
emitter = robot.getDevice("emitter")
gps = robot.getDevice("gps") # Retrieve the gps by device name

timestep = int(robot.getBasicTimeStep())

gps.enable(timestep) # Enable the gps
receiver.enable(timestep) # Enable the receiver. Note that the emitter does not need to call enable()

while robot.step(timestep) != -1:
    pass