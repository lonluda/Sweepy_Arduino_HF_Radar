/*
RadarSensor module v0.1
This module fully manage the HC - SR04 sensor. Exactly it handle:

1. Sensor pin init
2. Generate the trigger for signal emit
3. Measure ECHO return time
4. Calculate distance
5. Manage timeout

*/

#ifndef RADARSENSOR_H 
#define RADARSENSOR_H

#include <Arduino.h>

class RadarSensor {

  public:
    RadarSensor();
    void begin();
    bool getMeasure(double& distanceCm);

  private:
    int _trigPin;
    int _echoPin;
    static const int _MAX_DISTANCE_CM;
    unsigned long duration;
    void _sendTrigger();
    long _waitEcho();

};

#endif