char message[9]; // Here we use a 9 byte array, since sizeof(int + int + char) = 9
sprintf(message, "%d%d%c", 0, 0, 'H'); // Format the array with the data X-Pos = 0 cm, Z-Pos = 0 cm, victim type = harmed 
    
emitter->send(message, sizeof(message)); // Send out the message array. Note that the 2nd parameter must be the size of the message