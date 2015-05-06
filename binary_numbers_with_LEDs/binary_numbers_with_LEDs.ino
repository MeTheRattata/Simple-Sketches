int ledPins[] = {2,3,4,5,6,7,8,9}; //pin numbers of the 8 LEDs used
int decNum = 128; //Decimal number to be displayed with the 8 LEDs. maximum is 255
void setup() {
  for(int pin = 0; pin < 8; pin++)
    pinMode(ledPins[pin], OUTPUT);
}

void loop() {
   int num = decNum;
   int subtrahend = 128; //subtrahend = the number being subtracted
   int pin = 0;
  if(decNum > 256 || decNum < 0)
    errorFlash();
  else{
    for(int i = 0; i < 8; i++){
      if(num - subtrahend >= (num - 1) / 2){
        num -= subtrahend;
        subtrahend /= 2;
        digitalWrite(ledPins[i], HIGH);
      }
      else
        digitalWrite(ledPins[i], LOW);
    }
    if(num == 1)
      digitalWrite(ledPins[7], HIGH);
  }
}

void errorFlash(){
  for(int pin = 0; pin < 8; pin++){
    digitalWrite(ledPins[pin], HIGH);
    delay(300);
  }
  for(int pin = 0; pin < 8; pin++){
    digitalWrite(ledPins[pin], LOW);
    delay(300);
  }
}
