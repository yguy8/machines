//prueba para los controles de los servos para el movimiento del robot

#include <Servo.h>

// Definir pines de los potenciómetros
const int pot1 = A0;   // Primer potenciómetro en pin analógico A0
const int pot2 = A1;   // Segundo potenciómetro en pin analógico A1

// Definir pines de los servos
const int servoPin1 = 9;   // Primer servo en pin digital 9
const int servoPin2 = 10;  // Segundo servo en pin digital 10

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(servoPin1); // Conectar servo 1
  servo2.attach(servoPin2); // Conectar servo 2
}

void loop() {
  // Leer valores de los potenciómetros (0–1023)
  int val1 = analogRead(pot1);
  int val2 = analogRead(pot2);

  // Mapear valores a ángulos de servo (0–180 grados)
  int angle1 = map(val1, 0, 1023, 0, 170);
  int angle2 = map(val2, 0, 1023, 0, 170);

  // Mover servos
  servo1.write(angle1);
  servo2.write(angle2);

  delay(15); // Pequeña pausa para suavizar el movimiento
}
