#include <Joystick.h>

Joystick_ gb;

  
void setup() {
  setupJoy();
  setupXtras();
}


void loop() {
  loopJoy();
  loopXtras();

  gb.sendUpdate();
}
