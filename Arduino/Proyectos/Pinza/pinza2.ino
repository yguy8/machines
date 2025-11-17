#include <Servo.h>

// Pines de servos
const int SERVO1_PIN = 3;
const int SERVO2_PIN = 5;
const int SERVO3_PIN = 6;

// Sensor IR
const int SENSOR_PIN = 2;

// LED y buzzer
const int LED_PIN = 8;
const int BUZZER_PIN = 9;

// Ángulos
const int ANG_ABIERTO = 170;
const int ANG_CERRADO = 30;

Servo s1, s2, s3;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  s1.attach(SERVO1_PIN);
  s2.attach(SERVO2_PIN);
  s3.attach(SERVO3_PIN);

  moverServos(ANG_CERRADO); // posición inicial
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  int estado = digitalRead(SENSOR_PIN);

  if (estado == LOW) { // objeto detectado
    moverServos(ANG_ABIERTO);
    digitalWrite(LED_PIN, HIGH);   // enciende LED azul
    digitalWrite(BUZZER_PIN, HIGH); // activa buzzer
    delay(500);                     // pitido de 0.5 s
    digitalWrite(BUZZER_PIN, LOW);  // apaga buzzer
  } else { // sin objeto
    moverServos(ANG_CERRADO);
    digitalWrite(LED_PIN, LOW);     // apaga LED
    digitalWrite(BUZZER_PIN, LOW);  // asegura buzzer apagado
  }

  delay(50);
}

void moverServos(int ang) {
  s1.write(ang);
  s2.write(ang);
  s3.write(ang);
}
