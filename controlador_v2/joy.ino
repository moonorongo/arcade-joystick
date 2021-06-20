#define JOY_H_PIN A3
#define JOY_V_PIN A2

#define BTN_1 18
#define BTN_2 15
#define BTN_3 14
#define BTN_4 16
#define BTN_5 10
#define BTN_6 7

int joy_h_value;
int joy_v_value;

bool downSet1;
bool upSet1;
bool leftSet1;
bool rightSet1;

void setupJoy() {
  pinMode(BTN_1, INPUT_PULLUP); 
  pinMode(BTN_2, INPUT_PULLUP); 
  pinMode(BTN_3, INPUT_PULLUP); 
  pinMode(BTN_4, INPUT_PULLUP); 
  pinMode(BTN_5, INPUT_PULLUP); 
  pinMode(BTN_6, INPUT_PULLUP); 
}

void loopJoy() {
  joy_h_value = analogRead(JOY_H_PIN);
  joy_v_value = analogRead(JOY_V_PIN);

  downSet1 = false;
  upSet1 = false;
  leftSet1 = false;
  rightSet1 = false;  

  if(joy_v_value < 256) {
    upSet1 = true;
  }

  if(joy_v_value > 768) {
    downSet1 = true;
  }

  if(joy_h_value > 768) {
    rightSet1 = true;
  } 
   
  if(joy_h_value < 256) {
    leftSet1 = true;
  }
 
  gb.setLeftYaxis(upSet1 ? -127 : downSet1 ? 127 : 0); 
  gb.setLeftXaxis(leftSet1 ? -127 : rightSet1 ? 127 : 0);  

  gb.setButtonState(0, !digitalRead(BTN_1));
  gb.setButtonState(1, !digitalRead(BTN_2));
  gb.setButtonState(2, !digitalRead(BTN_3));
  gb.setButtonState(3, !digitalRead(BTN_4));
  gb.setButtonState(4, !digitalRead(BTN_5));
  gb.setButtonState(5, !digitalRead(BTN_6));
  
}
