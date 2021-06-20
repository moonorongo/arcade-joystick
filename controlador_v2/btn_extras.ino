#define XTRA_PIN A6
#define BTN_COIN 5
#define BTN_HOT 2
#define DELAY_PRESSED 400
#define DELAY_UNPRESSED 700

int xtra_value;
bool btn_1p;
bool btn_2p;
bool btn_coin;
int btn_coin_status; // 0: not press; 1: pressed; 2: after_pressed
unsigned long currentMillis;

void setupXtras() {
  pinMode(BTN_HOT, INPUT_PULLUP);
  pinMode(BTN_COIN, INPUT_PULLUP);
  
  currentMillis = millis();
  btn_coin_status = 0; // 0: pressed
}

void loopXtras() {
  xtra_value = analogRead(XTRA_PIN);

  btn_1p = false;
  btn_2p = false;
  btn_coin = false;

  if(xtra_value > 540) {
    btn_1p = true;
  }

  if(xtra_value < 480) {
    btn_2p = true;
  }

  switch(btn_coin_status) {
    case 0 : if(!digitalRead(BTN_COIN)) {
          btn_coin_status = 1;
          currentMillis = millis();
          btn_coin = true;
        }
        break;
        
    case 1 : if(millis() > currentMillis + DELAY_PRESSED) {
          btn_coin_status = 2;
          btn_coin = false;
          currentMillis = millis();
        }  
        break;

    case 2 : if(millis() > currentMillis + DELAY_UNPRESSED) {
          btn_coin_status = 0;
        }
        break;
  }
 
  gb.setButtonState(6, btn_1p);
  gb.setButtonState(7, btn_2p);
  gb.setButtonState(8, btn_coin);  
  gb.setButtonState(9, !digitalRead(BTN_HOT));  
}
