//cuenta progresiva del 0-9999
#include "SevSeg.h"
SevSeg sevseg;
// es de ánodo común el que estoy usando 
//pines de conexión
// arriba 10, 9, 8, 11, 12, 2
//abajo 6, 5, 4, 3, 7, 13
// Variables globales
int Contador = 0;     
unsigned long tiempoAnterior = 0; 
const unsigned long intervalo = 100; // 1 segundo

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_ANODE; 

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(50); // brillo más bajo para distinguir mejor
}

void loop() {
  sevseg.refreshDisplay();
  sevseg.setNumber(Contador);

  // sistema de conteo cada segundo
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    Contador++;
  }
}

