#include <Servo.h>

Servo servoX;
Servo servoY;

const int pinJoyX = A0;       // Joystick eje X
const int pinJoyY = A1;       // Joystick eje Y
const int pinJoyButton = 2;   // Botón del joystick

const int pinLedAzul = 7;     // LED azul (movimiento en X)
const int pinLedVerde = 6;    // LED verde (movimiento en Y)
const int pinLedAmarillo = 8; // LED amarillo (disparo)
const int pinBuzzer = 9;      // Buzzer

void setup() {
  servoX.attach(3);   // Servo X en pin 3
  servoY.attach(5);   // Servo Y en pin 5

  pinMode(pinJoyButton, INPUT_PULLUP); 
  pinMode(pinLedAzul, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedAmarillo, OUTPUT);
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

  // Detectar movimiento en X (fuera del centro ±50)
  if (valX > 562 || valX < 462) {
    digitalWrite(pinLedAzul, HIGH);
  } else {
    digitalWrite(pinLedAzul, LOW);
  }

  // Detectar movimiento en Y (fuera del centro ±50)
  if (valY > 562 || valY < 462) {
    digitalWrite(pinLedVerde, HIGH);
  } else {
    digitalWrite(pinLedVerde, LOW);
  }

  // Si se presiona el pulsador → disparo sutil
  if (digitalRead(pinJoyButton) == LOW) {
    disparoSutil();
  }

  delay(15);
}

// ----------------------
// Función para disparo sutil (buzzer + LED amarillo)
// ----------------------
void disparoSutil() {
  int freq = 1800;          // Frecuencia media-alta (sonido seco)
  int duracion = 60;        // Duración corta (60 ms)

  tone(pinBuzzer, freq, duracion);   // Sonido breve
  digitalWrite(pinLedAmarillo, HIGH); // LED amarillo encendido

  delay(duracion);           // Esperar duración del disparo

  noTone(pinBuzzer);
  digitalWrite(pinLedAmarillo, LOW);  // Apagar LED
}
