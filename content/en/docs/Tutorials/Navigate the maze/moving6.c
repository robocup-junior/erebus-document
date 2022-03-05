void report(char victimType) {
    // Character array to be sent to the supervisor to report victim/hazard
    // First four bytes store robot's x coordinate
    // Second four bytes store robot's z coordinate
    // Last byte stores type of victim
    //     Victims: H, S, U, T
    //     Hazards: F, P, C, O
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
}