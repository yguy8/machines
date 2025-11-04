//para cambiar colores


int rPin = 5;
int gPin = 6;
int bPin = 7;

void setup() {
  // put your setup code here, to run once:
pinMode(rPin, OUTPUT);
pinMode(gPin, OUTPUT);
pinMode(bPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(rPin, 255);
  analogWrite(gPin, 120);
  analogWrite(bPin, 90);
}
