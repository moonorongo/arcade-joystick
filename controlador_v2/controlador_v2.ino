#include <Gamepad.h>

Gamepad gb;

  
void setup() {
  setupJoy();
  setupXtras();
}


void loop() {
  loopJoy();
  loopXtras();

  gb.sendUpdate();
}
