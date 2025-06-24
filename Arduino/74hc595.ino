int latchPin = 8;
int clockPin = 13;
int dataPin = 12;
byte myByte = 0b01010101;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte);
  digitalWrite(latchPin, 1);
}

