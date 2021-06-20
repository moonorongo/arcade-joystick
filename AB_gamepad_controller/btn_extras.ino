#define XTRA_PIN A8

#define XTRA_1P 182     // 1k
#define XTRA_2P 91      // 2k2
#define XTRA_COIN 43    // 4k7

#define BTN_HOT 7

int xtra_value;
bool btn_1p;
bool btn_2p;
bool btn_coin;

void setupXtras() {
  pinMode(BTN_HOT, INPUT_PULLUP);   
}

void loopXtras() {
  xtra_value = analogRead(XTRA_PIN);
  
  btn_1p = false;
  btn_2p = false;
  btn_coin = false;

  if(isInRange(xtra_value, XTRA_1P)) {
    btn_1p = true;
  }

  if(isInRange(xtra_value, XTRA_2P)) {
    btn_2p = true;
  }
   
  if(isInRange(xtra_value, XTRA_COIN)) {
    btn_coin = true;
  }

  gb.setButtonState(6, btn_1p);
  gb.setButtonState(7, btn_2p);
  gb.setButtonState(8, btn_coin);
    
  gb.setButtonState(9, !digitalRead(BTN_HOT));  
}
