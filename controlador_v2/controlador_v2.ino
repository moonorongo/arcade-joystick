#include <Gamepad.h>

// Joy 1
Gamepad gb;

// Joy2
// Gamepad gb(false,2);

  
void setup() {
  setupJoy();
  setupXtras();
}


void loop() {
  loopJoy();
  loopXtras();

  gb.sendUpdate();
}
