#include <cstring>

...

char message[9]; // Here we use a 9 byte array, since sizeof(int + int + char) = 9

const double* position = gps->getValues(); // Get the current gps position of the robot
int x = (int)(position[0] * 100); // Get the x and z coordinates, multiplying by 100 to convert from meters to cm 
int z = (int)(position[2] * 100); // We will use these coordinates as an estimate for the victim's position

int victim_pos[2] = {x, z};

memcpy(message, victim_pos, sizeof(victim_pos)); // Copy the victim position into the message array
message[8] = 'H'; // 'H' reports a harmed victim (the symbol on the wall is Φ)

emitter->send(message, sizeof(message)); // Send out the message array. Note that the 2nd parameter must be the size of the message