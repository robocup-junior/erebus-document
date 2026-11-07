#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Camera.hpp>
#include <webots/Emitter.hpp>
#include <webots/GPS.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <array>
#include <cmath>

using namespace webots;
using namespace cv;
using namespace std;

Robot *robot = new Robot();

int timeStep = (int)robot->getBasicTimeStep();      // Set the time step for the simulation
float max_velocity = 6.27;                          // Set a maximum velocity time constant

Motor *wheel_left = robot->getMotor("left wheel motor");     // Create an object to control the left wheel
Motor *wheel_right = robot->getMotor("right wheel motor");   // Create an object to control the right wheel

DistanceSensor *leftDist, *frontDist, *rightDist; // Objects for left, front, and right distance sensor

Camera *cam; // Create an object to control the camera
Camera *colorSensor; // Color sensor is a 1 pixel camera

Emitter *emitter; // Used to send messages to supervisor (report wall tokens)
GPS *gps;

// [left wheel speed, right wheel speed]
float speeds[2] = { max_velocity, max_velocity };

vector<array<int, 2>> reported; // Positions where the robot has already reported a token

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

bool checkVic(void *img) {
    Rect boundRect;
    float contArea, ratio;
    vector<vector<Point>> contours;
    Mat frame(cam->getHeight(), cam->getWidth(), CV_8UC4, img); // Create frame using camera image

    cvtColor(frame, frame, COLOR_BGRA2GRAY); // Grayscale image
    threshold(frame, frame, 200, 255, THRESH_BINARY); // Threshold image (200-255 -> white; 0-200 -> black)
    findContours(frame, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // Find all bright shapes
    for (int i = 0; i < contours.size(); i++) {
        boundRect = boundingRect(contours[i]); // Find position and size of shape
        // Shapes touching the edge of the image are not tokens: they are usually the floor
        if (boundRect.x == 0 || boundRect.y == 0 ||
            boundRect.x + boundRect.width == frame.cols || boundRect.y + boundRect.height == frame.rows)
            continue;
        contArea = fabs(contourArea(Mat(contours[i]))); // Area covered by the shape
        ratio = (float)boundRect.width / boundRect.height; // Calculate width to height ratio
        //if the contour area and width to height ratio are within certain ranges
        if (contArea > 40 && ratio > 0.65 && ratio < 1.5)
            return true;
    }
    return false;
}

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

int main() {

	leftDist = robot->getDistanceSensor("leftDist");    // Grab robot's left distance sensor
	leftDist->enable(timeStep);     // Enable the distance sensor

	frontDist = robot->getDistanceSensor("frontDist");
	frontDist->enable(timeStep);

	rightDist = robot->getDistanceSensor("rightDist");
	rightDist->enable(timeStep);

	cam = robot->getCamera("camera");
	cam->enable(timeStep);

	colorSensor = robot->getCamera("color");
	colorSensor->enable(timeStep);

	emitter = robot->getEmitter("emitter");     // Emitter doesn't need enable

	gps = robot->getGPS("gps");
	gps->enable(timeStep);

	wheel_left->setPosition(INFINITY);
	wheel_right->setPosition(INFINITY);

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
			wheel_left->setVelocity(speeds[0]);
			wheel_right->setVelocity(speeds[1]);
			delay(600);
		}

		// if close to a wall in front and sees a victim, report it
		if (frontDist->getValue() < 0.07 && !alreadyReported() && checkVic((void*)cam->getImage()))
			report('H'); // Cannot determine the type of the victim, so always guess 'H' for now

		wheel_left->setVelocity(speeds[0]);              // Send the speed values we have choosen to the robot
		wheel_right->setVelocity(speeds[1]);
	};
}