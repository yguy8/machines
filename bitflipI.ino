//a la izquierda circular shift

int latchPin = 8;
int clockPin = 13;
int dataPin = 12;
byte myByte = 0b00010111;
int dt = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

//128 64 32 16 8 4 2 1 
//BINARIOS DECIMALES 
//1010000 160 0101000 80 0010100 40 0001010 10 0000101 5




void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte);
  digitalWrite(latchPin, 1);
  Serial.println(myByte, BIN);
  delay(dt);
  myByte = myByte/128 + myByte*2;
}

