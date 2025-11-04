int rPin = 5;
int gPin = 6;
int bPin = 7;

void setup()  {
// put your setup code here, to run once:
pinMode(rPin, OUTPUT);
pinMode(gPin, OUTPUT);
pinMode(bPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rPin, LOW);
  digitalWrite(gPin, HIGH);
  digitalWrite(bPin, HIGH);
}
