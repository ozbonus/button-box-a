#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  8, 0,                  // Button Count, Hat Switch Count
  false, false, false,   // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering


void setup() {
  pinMode(2, INPUT_PULLUP); // JOY_0
  pinMode(3, INPUT_PULLUP); // JOY_1
  pinMode(4, INPUT_PULLUP); // JOY_2
  pinMode(5, INPUT_PULLUP); // JOY_3
  // Secondary Box
  pinMode(6, INPUT_PULLUP); // JOY_4
  pinMode(7, INPUT_PULLUP); // JOY_5
  pinMode(8, INPUT_PULLUP); // JOY_6
  pinMode(9, INPUT_PULLUP); // JOY_7

  // Initialize Joystick Library.
  Joystick.begin();
}


// Last Button State
int lastButtonState[8] = {0, 0, 0, 0, 0, 0, 0, 0};


// So that index 0 refers to pin 2, etc.
const int indexToPinOffset = 2;


void loop() {
  for (int index = 0; index < 8; index++) {
    int currentButtonState = !digitalRead(index + indexToPinOffset);
    if (currentButtonState != lastButtonState[index]) {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  delay(50);
}

