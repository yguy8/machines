//display de 7 segmentos y 4 digitos
//pines de conexión
// arriba 10, 9, 8, 11, 12, 2
//abajo 6, 5, 4, 3, 7, 13
#include "SevSeg.h"
SevSeg sevseg;

// Variables globales
int Contador = 600; // 10 minutos en segundos
unsigned long tiempoAnterior = 0; 
const unsigned long intervalo = 1000; // 1 segundo

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

  // Convertir segundos a formato MMSS
  int minutos = Contador / 60;
  int segundos = Contador % 60;
  int mostrar = minutos * 100 + segundos; // ejemplo: 4:59 → 459

  sevseg.setNumber(mostrar);

  // sistema de conteo cada segundo
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    if (Contador > 0) {
      Contador--; // cuenta regresiva
    }
  }
}
