#include <Servo.h>
Servo ieo;
int trigPin = 9;
int echoPin = 8;
int tempo;
int distance;
int servoPin = 2;
int dt = 500;
int dt2 = 1500;

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

  if(distance <= 25){
   ieo.write(70);
  delay(dt2);
    ieo.write(0);
  }
  
  Serial.println("distancia");
}
