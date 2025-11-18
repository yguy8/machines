//modulo sensor de inclinación sw-520
const int sensor = 2;
const int ledPin = 13;
const int buzzer = 10;

int sensorState = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(sensor, INPUT);
}

void loop() {
  sensorState = digitalRead(sensor);

  if(sensorState == HIGH){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, LOW);
  }else {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, LOW);
  }
}
