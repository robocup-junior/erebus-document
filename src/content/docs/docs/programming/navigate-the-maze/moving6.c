void report(char victimType) {
    // Character array to be sent to the supervisor to report a wall token
    // First four bytes store robot's x coordinate
    // Second four bytes store robot's z coordinate
    // Last byte stores type of victim
    //     Letter victims: H, S, U
    //     Cognitive targets: F, P, C, O
    wheel_left->setVelocity(0);     // Stop for 1 second
	wheel_right->setVelocity(0);
    delay(1300);
    char message[9];
    int posX = gps->getValues()[0] * 100, posZ = gps->getValues()[2] * 100;
    memcpy(&message[0], &posX, 4);
    memcpy(&message[4], &posZ, 4);
    message[8] = victimType;
    emitter->send(message, 9);
    robot->step(timeStep);
    reported.push_back({posX, posZ});
}

bool alreadyReported() {
    // A token can only be scored once, and reporting it again is a misidentification
    double posX = gps->getValues()[0] * 100, posZ = gps->getValues()[2] * 100;
    for (int i = 0; i < reported.size(); i++)
        if (fabs(posX - reported[i][0]) < 12 && fabs(posZ - reported[i][1]) < 12) // Closer than 1 tile (12 cm)
            return true;
    return false;
}