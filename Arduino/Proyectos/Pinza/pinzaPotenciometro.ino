#include <Servo.h>

// Pines de servos
const int SERVO1_PIN = 3;
const int SERVO2_PIN = 5;
const int SERVO3_PIN = 6;

// Potenciómetro
const int POT_PIN = A0;

// Ángulos
const int ANG_MIN = 0;
const int ANG_MAX = 180;

Servo s1, s2, s3;

void setup() {
  s1.attach(SERVO1_PIN);
  s2.attach(SERVO2_PIN);
  s3.attach(SERVO3_PIN);

  moverServos(ANG_MIN); // posición inicial
}

void loop() {
  // Leer potenciómetro (0–1023)
  int valorPot = analogRead(POT_PIN);

  // Convertir a ángulo (0–180)
  int angulo = map(valorPot, 0, 1023, ANG_MIN, ANG_MAX);

  // Mover servos al ángulo
  moverServos(angulo);

  delay(20); // pequeña pausa para estabilidad
}

void moverServos(int ang) {
  s1.write(ang);
  s2.write(ang);
  s3.write(ang);
}
