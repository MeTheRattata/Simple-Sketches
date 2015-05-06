int ledPins[] = {2,3,4,5,6,7,8,9}; //pin numbers of the 8 LEDs used
int decNum = 128; //Decimal number to be displayed with the 8 LEDs. maximum is 255
void setup() {
  for(int pin = 0; pin < 8; pin++)
    pinMode(ledPins[pin], OUTPUT);
}

void loop() {
   int num = 128;
   int subtrahend = 128; //subtrahend = the number being subtracted
   int pin = 0;
  if(decNum > 255 || decNum < 0)
    errorFlash();
  else
    while(num > 0){
      if((num - subtrahend) > 0){
        num -= subtrahend;
        digitalWrite(ledPins[pin], HIGH)
      }
      subtrahend = subtrahend / 2;
      pin++;
    }
}

void errorFlash(){
  for(int pin = 0; pin < 8; pin++)
    digitalWrite(ledPins[pin], HIGH);
  for(int pin = 0; pin < 8; pin++)
    digitalWrite(ledPins[pin], LOW);
}
