#ifndef RADARSWEEP_H 
#define RADARSWEEP_H

#include <Arduino.h>
#include <Servo.h>

class RadarSweep {

  public:
  RadarSweep();
  void begin();
  void center();
  void startPosition();

  private:
  Servo _servo;
  const int START_ANGLE = 2;
  int _servoPin;

};

#endif