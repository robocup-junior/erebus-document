from controller import Robot

robot = Robot()
timeStep = int(robot.getBasicTimeStep())

# Keep the sensors in a dictionary, to use them by name
sensors = {}
for name in ["leftDist", "frontDist", "rightDist"]:
    sensors[name] = robot.getDevice(name)
    sensors[name].enable(timeStep)

WALL = 0.07  # Closer than 7 cm counts as a wall next to the robot

while robot.step(timeStep) != -1:
    walls = [name for name, sensor in sensors.items() if sensor.getValue() < WALL]
    print("Walls:", walls)
