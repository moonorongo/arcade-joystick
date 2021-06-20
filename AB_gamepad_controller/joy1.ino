#define JOY1_PIN A3

#define UP 182        // 1k
#define RIGHT 90      // 2k2
#define DOWN 43       // 4k7
#define LEFT 20       // 10k
#define UP_RIGHT 245
#define UP_LEFT 197
#define DOWN_RIGHT 128
#define DOWN_LEFT 64

#define BTN_1 20
#define BTN_2 19
#define BTN_3 18
#define BTN_4 15
#define BTN_5 14
#define BTN_6 16

int joy1_value;
bool downSet1;
bool upSet1;
bool leftSet1;
bool rightSet1;

void setupJoy1() {
  pinMode(BTN_1, INPUT_PULLUP); 
  pinMode(BTN_2, INPUT_PULLUP); 
  pinMode(BTN_3, INPUT_PULLUP); 
  pinMode(BTN_4, INPUT_PULLUP); 
  pinMode(BTN_5, INPUT_PULLUP); 
  pinMode(BTN_6, INPUT_PULLUP); 
  
}

void loopJoy1() {
  joy1_value = analogRead(JOY1_PIN);
  
  downSet1 = false;
  upSet1 = false;
  leftSet1 = false;
  rightSet1 = false;  

  if(isInRange(joy1_value, UP)) {
    upSet1 = true;
  }
  
  if(isInRange(joy1_value, RIGHT)) {
    rightSet1 = true;
  } 

  if(isInRange(joy1_value, DOWN)) {
    downSet1 = true;
  }
   
  if(isInRange(joy1_value, LEFT)) {
    leftSet1 = true;
  }
  
  if(isInRange(joy1_value, UP_RIGHT)) {
    upSet1 = true;
    rightSet1 = true;    
  } 

  if(isInRange(joy1_value, UP_LEFT)) {
    upSet1 = true;
    leftSet1 = true;
  } 
  
  if(isInRange(joy1_value, DOWN_RIGHT)) {
    downSet1 = true;
    rightSet1 = true;
  } 

  if(isInRange(joy1_value, DOWN_LEFT)) {
    downSet1 = true;
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
