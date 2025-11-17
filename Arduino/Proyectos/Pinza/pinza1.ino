#include <Servo.h>

const int SERVO1_PIN = 3;
const int SERVO2_PIN = 5;
const int SERVO3_PIN = 6;
const int SENSOR_PIN = 2;  // salida del módulo IR

const int ANG_ABIERTO = 170;
const int ANG_CERRADO = 30;

Servo s1, s2, s3;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  s1.attach(SERVO1_PIN);
  s2.attach(SERVO2_PIN);
  s3.attach(SERVO3_PIN);

  moverServos(ANG_CERRADO); // posición inicial
}

void loop() {
  int estado = digitalRead(SENSOR_PIN);

  if (estado == LOW) { // objeto detectado
    moverServos(ANG_ABIERTO);
  } else {             // sin objeto
    moverServos(ANG_CERRADO);
  }

  delay(50); // pequeño retardo para estabilidad
}

void moverServos(int ang) {
  s1.write(ang);
  s2.write(ang);
  s3.write(ang);
}
