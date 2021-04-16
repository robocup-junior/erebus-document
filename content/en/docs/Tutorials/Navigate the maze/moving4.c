void turn_right() {
    // set left wheel speed
    speeds[0] = 0.6 * max_velocity;
    // set right wheel speed
    speeds[1] = -0.2 * max_velocity;
}

void turn_left() {
    // set left wheel speed
    speeds[0] = -0.2 * max_velocity;
    // set right wheel speed
    speeds[1] = 0.6 * max_velocity;
}

void spin() {
    // set left wheel speed
    speeds[0] = 0.6 * max_velocity;
    // set right wheel speed
    speeds[1] = -0.6 * max_velocity;
}