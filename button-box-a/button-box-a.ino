#include <Joystick.h>


// So that index 0 refers to pin 10, etc.
const int indexToPinOffset = 10;


// //////////////////////////
// Individual Box Settings.
// Enable only one at a time.
// //////////////////////////

// Settings for Box 1
// const int DEVICE_ID = 0x03;
// const int JOY_OFFSET = 0;

// Settings for Box 2
const int DEVICE_ID = 0x04;
const int JOY_OFFSET = 4;


Joystick_ Joystick(DEVICE_ID, JOYSTICK_TYPE_GAMEPAD,
  8, 0,                  // Button Count, Hat Switch Count
  false, false, false,   // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering


void setup() {
  pinMode(10, INPUT_PULLUP); // JOY_0
  pinMode(11, INPUT_PULLUP); // JOY_1
  pinMode(12, INPUT_PULLUP); // JOY_2
  pinMode(13, INPUT_PULLUP); // JOY_3

  // Initialize Joystick Library.
  Joystick.begin();
}


// Last Button State
int lastButtonState[4] = {0, 0, 0, 0};


void loop() {
  for (int index = 0; index < 4; index++) {
    int currentButtonState = !digitalRead(index + indexToPinOffset);
    if (currentButtonState != lastButtonState[index]) {
      Joystick.setButton(index + JOY_OFFSET, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  delay(50);
}

