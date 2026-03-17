/*
SerialProtocol module v0.1
This module fully manage the message incapsulation and construction.

1. Manage messages to send in the Serial Console -> sendRadar()
2. Manage error messages -> sendError()
3. Manage status message to transmit -> sendState()

*/

#ifndef SERIALPROTOCOL_H 
#define SERIALPROTOCOL_H

#include <Arduino.h>

class SerialProtocol {

  public:
    SerialProtocol();
    void begin();
    void sendProtoVersion();
    void sendRadar(double message);
    void sendError(char* error);
    void sendState(char* state);
    
};

#endif