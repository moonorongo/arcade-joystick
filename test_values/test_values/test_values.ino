#define JOY_H_PIN A9

int joy1_value;


void setup() {
  Serial.begin(9600);

}

void loop() {
  joy1_value = analogRead(JOY_H_PIN);
  Serial.println(joy1_value);
  
  delay(100);

}
