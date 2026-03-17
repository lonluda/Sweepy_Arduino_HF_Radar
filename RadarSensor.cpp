/*
RadarSensor module v0.1
This module fully manage the HC - SR04 sensor. Exactly it handle:

1. Sensor pin init -> begin()
2. Generate the trigger for signal emit -> emit()
3. Measure ECHO return time -> 
4. Calculate distance -> calculate()
5. Manage timeout -> timeout()

*/

#include "RadarSensor.h"

const int RadarSensor::_MAX_DISTANCE_CM = 400;

RadarSensor::RadarSensor() {
    _trigPin = 9;
    _echoPin = 10;
}

void RadarSensor::begin() {
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

void RadarSensor::_sendTrigger() {
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
}

long RadarSensor::_waitEcho() {
  duration = pulseIn(_echoPin, HIGH, 30000);
  return duration;
}

bool RadarSensor::getMeasure(double& distanceCm) {

  _sendTrigger();  // Send the trigger input to sensor
  duration = _waitEcho();   // Wait echo return 
  
  if (duration == 0){
    return false; // timeout, no echo 
  }

  double distance = (duration*.0343)/2;   // Calculate the distance 

  if (distance > _MAX_DISTANCE_CM){
    return false; // out of range
  }
  
  distanceCm = distance;
  return true;
}

