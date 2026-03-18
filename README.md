# Sweepy_Arduino_Ultrasonic_Radar
A simple high frequencies radar, Arduino based. The project uses a high-frequency HC-SR04 module to transmit a signal and receive the echo, thereby measuring the distance to the obstacle. 

### Components
- Arduino Uno
- HCSR-04
- 470 µF Capacitor (16VDC)

### A range of modules are available to extend the functionality:
RadarSensor.cpp & RadarSensor.h = Manage HC-SR04 module signal, trigger and echo.<br>
RadarState.cpp & RadarState.h = Change the radar status (To implement).<br>
RadarSweep.cpp & RadarSweep.h = Move the radar to a new angle for the next scan.<br>
SerialProtocol.cpp & SerialProtocol.h = Initialize and manage the communication protocol.<br>

### How to use
Main sketch to upload in Arduino is <b>"sweepy.ino"</b>. Once uploaded, it will works only with all modules .cpp and .h provided.

<img width="600" src="https://github.com/user-attachments/assets/91c99a1a-a229-4111-b6ea-94999716b7c5">

## Console output
<img width="689" height="353" alt="image" src="https://github.com/user-attachments/assets/73000e1e-3a9a-4825-a693-2f0aa86fbe7b" />

## Communication Protocol

Version: <S|PROTO;1.0>

<b><S|</b> = Type of message <br>
<b>PROTO;</b> = Communication protocol <br>
<b>1.0></b> = Version

Type of messages:

S = State <br>
R = Read <br>
E = Error <br>
C = Command (To improve) <br>
P = Parameter (To improve) <br>
