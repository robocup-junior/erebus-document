def report(victimType):
    # Struct package to be sent to supervisor to report victim/hazard
    # First four bytes store robot's x coordinate
    # Second four bytes store robot's z coordinate
    # Last byte stores type of victim
    #     Victims: H, S, U, T
    #     Hazards: F, P, C, O
    wheel_left.setVelocity(0)   # Stop for 1 second
    wheel_right.setVelocity(0)
    delay(1300)
    victimType = bytes(victimType, "utf-8")    # Convert victimType to character for struct.pack
    posX = int(gps.getValues()[0] * 100)    # Convert from cm to m
    posZ = int(gps.getValues()[2] * 100)
    message = struct.pack("i i c", posX, posZ, victimType)
    emitter.send(message)
    robot.step(timeStep)