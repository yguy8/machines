#include <Servo.h>  //libreria del servo

int servoPin = 9;
int servoPos = 85;
int lightPin = A1;
int lightVal;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  pinMode(lightPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  myServo.write(servoPos);
}
