
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ledDelay;
int directionLeft = 1;
int directionRight = -1;
int leftLED = 0;
int rightLED = 9;

unsigned long changeTime;
int potPin = 2;


void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPin[i], OUTPUT);
  } 
  changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potPin);
  if((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }  
}

void changeLED() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPin[i], LOW);
  }

  digitalWrite(ledPin[leftLED], HIGH);
  digitalWrite(ledPin[rightLED], HIGH);
  rightLED += directionRight;
  leftLED += directionLeft;
  
  if (rightLED == 9) {directionRight = -1;}
  if (rightLED == 5) {directionRight = 1;}
  if (leftLED == 0) {directionLeft = 1;}
  if (leftLED == 4) {directionLeft = -1;}
}
