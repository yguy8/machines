#include "SevSeg.h"
SevSeg sevseg;

// Variables globales
int Contador = 0;     // inicio
int espera =0;        // contador espera
int esperamax =1000;  // define la velocidad

void setup(){
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}
void loop(){
  sevseg.refreshDisplay();
  sevseg.setNumber(Contador, -1);
  // sistema para aumentar el contador y crear un sistema de velocidad
  espera = espera +1;
  if (espera == esperamax){
    espera =0;
    Contador = Contador + 1;
  }
}
