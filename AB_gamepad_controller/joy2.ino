#define JOY2_PIN A7

#define UP2 182
#define RIGHT2 92
#define DOWN2 44
#define LEFT2 20
#define UP_RIGHT2 246
#define UP_LEFT2 197
#define DOWN_RIGHT2 129
#define DOWN_LEFT2 64

#define BTN_12 1
#define BTN_22 0
#define BTN_32 2
#define BTN_42 3
#define BTN_52 4
#define BTN_62 5

int joy2_value;
bool downSet2;
bool upSet2;
bool leftSet2;
bool rightSet2;

void setupJoy2() {
  pinMode(BTN_12, INPUT_PULLUP); 
  pinMode(BTN_22, INPUT_PULLUP); 
  pinMode(BTN_32, INPUT_PULLUP); 
  pinMode(BTN_42, INPUT_PULLUP); 
  pinMode(BTN_52, INPUT_PULLUP); 
  pinMode(BTN_62, INPUT_PULLUP); 
}

void loopJoy2() {
  joy2_value = analogRead(JOY2_PIN);
  
  downSet2 = false;
  upSet2 = false;
  leftSet2 = false;
  rightSet2 = false;  

  if(isInRange(joy2_value, UP2)) {
    upSet2 = true;
  }
  
  if(isInRange(joy2_value, RIGHT2)) {
    rightSet2 = true;
  } 

  if(isInRange(joy2_value, DOWN2)) {
    downSet2 = true;
  }
   
  if(isInRange(joy2_value, LEFT2)) {
    leftSet2 = true;
  }
  
  if(isInRange(joy2_value, UP_RIGHT2)) {
    upSet2 = true;
    rightSet2 = true;    
  } 

  if(isInRange(joy2_value, UP_LEFT2)) {
    upSet2 = true;
    leftSet2 = true;
  } 
  
  if(isInRange(joy2_value, DOWN_RIGHT2)) {
    downSet2 = true;
    rightSet2 = true;
  } 

  if(isInRange(joy2_value, DOWN_LEFT2)) {
    downSet2 = true;
    leftSet2 = true;
  }
  
  gb.setRightYaxis(upSet2 ? -127 : downSet2 ? 127 : 0); 
  gb.setRightXaxis(leftSet2 ? -127 : rightSet2 ? 127 : 0);  

  gb.setButtonState(10, !digitalRead(BTN_12));
  gb.setButtonState(11, !digitalRead(BTN_22));
  gb.setButtonState(12, !digitalRead(BTN_32));
  gb.setButtonState(13, !digitalRead(BTN_42));
  gb.setButtonState(14, !digitalRead(BTN_52));
  gb.setButtonState(15, !digitalRead(BTN_62));


  
}
