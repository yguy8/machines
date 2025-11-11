#include <Servo.h>

// Pines de potenciómetros
const int pot1 = A0;   // Potenciómetro 1
const int pot2 = A1;   // Potenciómetro 2

// Pines de servos
const int servoPin1 = 9;   // Servo 1
const int servoPin2 = 10;  // Servo 2

// Pin del láser
const int laserPin = 5;

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  pinMode(laserPin, OUTPUT);

  // Encender láser siempre
  digitalWrite(laserPin, HIGH);
}

void loop() {
  // Leer valores de los potenciómetros
  int val1 = analogRead(pot1);
  int val2 = analogRead(pot2);

  // Mapear valores a ángulos de servo
  int angle1 = map(val1, 0, 1023, 0, 180);
  int angle2 = map(val2, 0, 1023, 0, 180);

  // Mover servos
  servo1.write(angle1);
  servo2.write(angle2);

  delay(15); // Suavizar movimiento
}
