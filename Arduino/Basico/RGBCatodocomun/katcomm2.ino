//para cambiar colores
int rPin = 5;
int gPin = 6;
int bPin = 7;

void setup() {
pinMode(rPin, OUTPUT);
pinMode(gPin, OUTPUT);
pinMode(bPin, OUTPUT);
}

void loop() {
  analogWrite(rPin, 255);
  analogWrite(gPin, 120);
  analogWrite(bPin, 90);
}
