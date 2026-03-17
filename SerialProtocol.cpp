/*
SerialProtocol module v0.1
This module fully manage the message incapsulation and construction.

1. Manage messages to send in the Serial Console -> sendRadar()
2. Manage error messages -> sendError()
3. Manage status message to transmit -> sendState()

*/

#include "HardwareSerial.h"
#include "SerialProtocol.h"

SerialProtocol::SerialProtocol(){
  
}

void SerialProtocol::SerialProtocol::begin() {
  Serial.begin(9600);
}

void SerialProtocol::sendProtoVersion(){
  Serial.println("<S|PROTO;1.0>");
}

void SerialProtocol::sendRadar(double message){

  if (message){
    Serial.print("<R|");
    Serial.print(message, 2);
    Serial.println(">");
  }

}

void SerialProtocol::sendError(char* error){

  if (error){
    Serial.print("<E|");
    Serial.print(error);
    Serial.println(">");
  }

}

void SerialProtocol::sendState(char* state){

}

