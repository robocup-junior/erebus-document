char message[2]; // Use an array of size 2 to avoid overflow warning
sprintf(message, "%c", 'E'); // Send the letter 'E' to signify exit
    
emitter->send(message, 1);