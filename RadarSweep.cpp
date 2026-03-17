#include "RadarSweep.h"

RadarSweep::RadarSweep(){
  _servoPin = 3;
}

void RadarSweep::begin(){
  _servo.attach(_servoPin);

  _servo.write(90);     // Center Servo
  delay(500);           // Servo stabilization 

  //_servo.write(2);     // Bring Servo to starting position
  //delay(500);           // Servo stabilization 
}

