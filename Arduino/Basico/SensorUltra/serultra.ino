#include <Servo.h>
Servo ieo;
int trigPin = 9;
int echoPin = 8;
int tempo;
int distance;
int servoPin = 4;
int dt = 500;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  ieo.attach(servoPin);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, 1);
  delay(dt);
  digitalWrite(trigPin, 0);
  tempo=pulseIn(echoPin, 1);
  distance=tempo/58.2;
  delay(dt);

  if(distance <= 20){
   ieo.write(170);
  }
  if(distance > 20){
    ieo.write(0);
  }
  Serial.println("distancia");
}
