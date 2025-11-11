#include <Servo.h>

Servo servoX;
Servo servoY;

const int pinJoyX = A0;
const int pinJoyY = A1;
const int pinJoyButton = 2;

const int pinLed = 8;
const int pinBuzzer = 9;

void setup() {
  servoX.attach(3);   // Servo X en pin 3
  servoY.attach(5);   // Servo Y en pin 5

  pinMode(pinJoyButton, INPUT_PULLUP); 
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  // Posición inicial
  servoX.write(85);
  servoY.write(85);
}

void loop() {
  // Leer joystick
  int valX = analogRead(pinJoyX);
  int valY = analogRead(pinJoyY);

  // Mapear valores (0–1023 → 0–170)
  int angX = map(valX, 0, 1023, 0, 170);
  int angY = map(valY, 0, 1023, 0, 170);

  // Mover servos
  servoX.write(angX);
  servoY.write(angY);

  // Si se presiona el pulsador → ejecutar patrón rápido
  if (digitalRead(pinJoyButton) == LOW) {
    ejecutarPatronRapido();
  }
}

// ----------------------
// Función para patrón rápido de sonido + LED
// ----------------------
void ejecutarPatronRapido() {
  for (int i = 0; i < 20; i++) {
    int delayTime = 250 - i * 10;   // De 250 ms a 50 ms
    if (delayTime < 50) delayTime = 50;

    int freq = 1200 + i * 80;       // Tono sube rápido: 1200 → 2800 Hz

    // Encender LED + tono
    tone(pinBuzzer, freq, 50);      // Pip corto (50 ms)
    digitalWrite(pinLed, HIGH);

    delay(50);                      // Duración pip + LED
    noTone(pinBuzzer);
    digitalWrite(pinLed, LOW);

    delay(delayTime - 50);          // Pausa antes del siguiente pip
  }
}
