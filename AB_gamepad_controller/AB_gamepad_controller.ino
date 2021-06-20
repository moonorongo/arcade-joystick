#include <Gamepad.h>

#define THRESHOLD 5

Gamepad gb;

  
boolean isInRange(int value, byte joy_position) {
  return (value >= (joy_position - THRESHOLD)) && (value <= (joy_position + THRESHOLD));  
}

void setup() {
  setupJoy1();
  setupJoy2();
  setupXtras();
}


void loop() {
  loopJoy1();
  loopJoy2();
  loopXtras();

  gb.sendUpdate();
}
