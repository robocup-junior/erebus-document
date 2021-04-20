from controller import Robot, Receiver, Emitter # Import Receiver and Emitter

robot = Robot()

receiver = robot.getDevice("receiver") # Retrieve the receiver and emitter by device name
emitter = robot.getDevice("emitter")

timestep = int(robot.getBasicTimeStep())

receiver.enable(timestep) # Enable the receiver. Note that the emitter does not need to call enable()

while robot.step(timestep) != -1:
    pass