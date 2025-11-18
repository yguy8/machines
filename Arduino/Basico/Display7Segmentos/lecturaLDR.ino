#include "SevSeg.h"
SevSeg sevseg;

// Pin del buzzer
const int buzzerPin = A0;   // salida digital
const int ldrPin = A1;      // entrada analógica para la LDR

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_ANODE; 

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(50);

  pinMode(buzzerPin, OUTPUT); // buzzer como salida
}

void loop() {
  sevseg.refreshDisplay();

  // Leer valor de la LDR
  int valorLuz = analogRead(ldrPin); // 0-1023             entre más cerca del 0 es hay más luz

  // Mostrar el valor en el display
  sevseg.setNumber(valorLuz);

  // Si está oscuro (umbral ajustable)
  if (valorLuz < 200) { 
    tone(buzzerPin, 2000, 200); // pitido de 200ms
  } else {
    noTone(buzzerPin);
  }
}
