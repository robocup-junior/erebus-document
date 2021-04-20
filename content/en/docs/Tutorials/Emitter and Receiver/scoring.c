#include <cstring>

...

char message[9]; // Here we use a 9 byte array, since sizeof(int + int + char) = 9

int pos[] = {0 , 0}; // The estimated position of the victim is 0 cm, 0 cm
memcpy(message, pos, sizeof(pos)); // Copy the position into the message array
message[8] = 'H'; // The victim type is harmed

emitter->send(message, sizeof(message)); // Send out the message array. Note that the 2nd parameter must be the size of the message