#include <Joystick.h>

/*
  Pedal Board Controller for Arduino Leonardo / Micro
  ---------------------------------------------------
  Uses MHeironimus' Arduino Joystick Library (GPLv3)
  https://github.com/MHeironimus/ArduinoJoystickLibrary

  Reads three analog pedals (throttle, brake, clutch)
  and maps them to joystick axes.
*/

// === Pin Configuration ===
constexpr int PIN_GAS    = A5;
constexpr int PIN_BRAKE  = A3;
constexpr int PIN_CLUTCH = A4;

// === Joystick Object ===
Joystick_ Joystick;

// === Setup ===
void setup() {
  Joystick.begin();

  // Define custom analog input ranges
  // (calibrated manually to match mechanical limits)
  Joystick.setThrottleRange(76, 345);  // gas (reduced max due to physical stop)
  Joystick.setYAxisRange(105, 1010);   // brake
  Joystick.setZAxisRange(115, 670);    // clutch
}

// === Helper Function ===
int readPedal(int pin) {
  int value = analogRead(pin);
  return value < 1 ? 0 : value;
}

// === Main Loop ===
void loop() {
  // Read and send gas pedal value
  int gasValue = readPedal(PIN_GAS);
  Joystick.setThrottle(gasValue);
  delay(50);

  // Read and send brake pedal value
  int brakeValue = readPedal(PIN_BRAKE);
  Joystick.setYAxis(brakeValue);
  delay(50);

  // Read and send clutch pedal value
  int clutchValue = readPedal(PIN_CLUTCH);
  Joystick.setZAxis(clutchValue);
  delay(50);
}
