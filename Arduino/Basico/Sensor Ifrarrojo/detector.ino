#include "SevSeg.h"
SevSeg sevseg;

// Pines
const int sensorPin = A1;   // sensor infrarrojo (puedes usar A1 como digital)
const int buzzerPin = A0;   // buzzer

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_ANODE; 

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(50);

  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  sevseg.refreshDisplay();

  int valor = digitalRead(sensorPin);

  if (valor == HIGH) {
    // Zona despejada → mostrar 1111
    sevseg.setNumber(1111);
    noTone(buzzerPin);
  } else {
    // Obstáculo detectado → mostrar 8080 y sonar buzzer
    sevseg.setNumber(8080);
    tone(buzzerPin, 2000, 200); // pitido de 200ms
  }

  delay(200); // pequeña pausa para estabilidad
}
