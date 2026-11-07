def report(victimType):
    # Struct package to be sent to supervisor to report a wall token
    # First four bytes store robot's x coordinate
    # Second four bytes store robot's z coordinate
    # Last byte stores type of victim
    #     Letter victims: H, S, U
    #     Cognitive targets: F, P, C, O
    wheel_left.setVelocity(0)   # Stop for 1 second
    wheel_right.setVelocity(0)
    delay(1300)
    victimType = bytes(victimType, "utf-8")    # Convert victimType to character for struct.pack
    posX = int(gps.getValues()[0] * 100)    # Convert from m to cm
    posZ = int(gps.getValues()[2] * 100)
    message = struct.pack("i i c", posX, posZ, victimType)
    emitter.send(message)
    robot.step(timeStep)
    reported.append((posX, posZ))

def alreadyReported():
    # A token can only be scored once, and reporting it again is a misidentification
    posX = gps.getValues()[0] * 100
    posZ = gps.getValues()[2] * 100
    for x, z in reported:
        if abs(posX - x) < 12 and abs(posZ - z) < 12: # Closer than 1 tile (12 cm)
            return True
    return False
