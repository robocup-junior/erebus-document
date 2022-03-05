int main() {
    while (robot->step(timeStep) != -1) {
		speeds[0] = max_velocity;
		speeds[1] = max_velocity;

		// Check left and right sensor to avoid walls
		//for sensor on the left, either
		if (leftDist->getValue() < 0.05)
			turn_right();      // We see a wall on the left, so turn right away from the wall

		if (rightDist->getValue() < 0.05)		// for sensor on the right too
			turn_left();

		// for front sensor
		if (frontDist->getValue() < 0.05)
			spin();

		// if on black, turn away
		if (getColor() < 80) {
			spin();
			leftMotor->setVelocity(speeds[0]);
			rightMotor->setVelocity(speeds[1]);
			delay(600);
		}

		// if sees victim, report it
		if (checkVic((void*)cam->getImage()))
			report('T'); // Cannot determine type of victim, so always try 'T' for now

		leftMotor->setVelocity(speeds[0]);		// Send the speed values we have choosen to the robot
		rightMotor->setVelocity(speeds[1]);
	};
}