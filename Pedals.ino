#include <Joystick.h>

// NOTE: This file is for use with Arduino Leonardo and  Arduino Micro only.
//       Arduino Micro only.
//
// To get this program to work you need MHeironimus GPLv3 joystick libary from
// https://github.com/MHeironimus/ArduinoJoystickLibrary version-1.0
//

// Variable
int gas = A5;
int brake = A3; 
int clutch = A4;

int gasValue = 0;
int gasValuebyte = 0;

int brakeValue = 0;
int brakeValuebyte1 = 0;
int brakeValuebyte2 = 0;

int clutchValue = 0;
int clutchValuebyte1 = 0;
int clutchValuebyte2 = 0;

Joystick_ Joystick;

// init joystick libary
void setup() {
  Joystick.begin();
  
  // setto il range per l'acceleratore 
  // (e' stato installato un fine corsa meccanico per ridurre la corsa del pedale quindi il max è ridotto di 5)
  Joystick.setThrottleRange(76, 345);
  // brake range
  Joystick.setYAxisRange(105, 1010);
  // clutch range
  Joystick.setZAxisRange(115, 670);
}

void loop() {
  
  // Gas
  gasValue = analogRead(gas);
  
  if (gasValue >= 1) {
  gasValuebyte = gasValue / 4 ;
   }
   else
   {
    gasValuebyte = 0 ;
   }
  Joystick.setThrottle(gasValue);
  delay(50); 

  // Brake
  brakeValue = analogRead(brake);
  
  if (brakeValue >= 1) {
    brakeValuebyte1 = brakeValue / 4;
    brakeValuebyte2 = brakeValuebyte1 - 127;
  
   }
   else
   {
    brakeValuebyte2 = -127;
   }
  Joystick.setYAxis(brakeValue);
  delay(50); 

  // Clutch
  clutchValue = analogRead(clutch);
  
  if (clutchValue >= 1) {
  clutchValuebyte1 = clutchValue / 4;
  clutchValuebyte2 = clutchValuebyte1 - 127;
  
   }
   else
   {
    clutchValuebyte2 = -127;
   }
   Joystick.setZAxis(clutchValue);
  delay(50); 
}
