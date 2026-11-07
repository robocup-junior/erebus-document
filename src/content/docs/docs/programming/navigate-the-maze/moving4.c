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

void delay(int ms) {
	float initTime = robot->getTime();	// Store starting time (in seconds)
	while (robot->step(timeStep) != -1) {
		if ((robot->getTime() - initTime) * 1000.0 > ms) { // If time elapsed (converted into ms) is greater than value passed in
			return;
		}
	}
}

int getColor() {
	const unsigned char* image = colorSensor->getImage();	// Grab color sensor camera's image view
	return colorSensor->imageGetGray(image, colorSensor->getWidth(), 0, 0);		// Return grayness of the only pixel (0-255)
}