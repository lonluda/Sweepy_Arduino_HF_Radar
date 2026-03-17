#include "RadarSensor.h"
#include "RadarState.h"
#include "RadarSweep.h"
#include "SerialProtocol.h"

RadarSensor radarSensor;
RadarState radarState;
RadarSweep radarSweep;
SerialProtocol serialProtocol;

const unsigned long MEASURE_INTERVAL_MS = 100;
unsigned long lastTrigger = 0;

void setup() {

  // Modules initializations 
  serialProtocol.begin(); // Init serial communication protocol
  radarSensor.begin();    // Init ultrasonic sensor
  radarSweep.begin();     // Init servo position to 90°

  // Proto message trasmission
  serialProtocol.sendProtoVersion();

}

void loop() {

  // assign the actual running time
  unsigned long now = millis();

  // check if passed enough time until last execution
  if(now - lastTrigger >= MEASURE_INTERVAL_MS){
    lastTrigger = now;

    double distanceCm;

    // Get the measured value
    bool isValidMeasure = radarSensor.getMeasure(distanceCm);
    
    if(isValidMeasure){
      // Sent the value to serialProtocol
      serialProtocol.sendRadar(distanceCm);
    }else{
      serialProtocol.sendError("No echo");
    }


  }

}