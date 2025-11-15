// integra un buzz y parpadean todos los leds al finalizar
//display de 7 segmentos 4 digitos
//pines de conexión
// arriba 10, 9, 8, 11, 12, 2
//abajo 6, 5, 4, 3, 7, 13
#include "SevSeg.h"
SevSeg sevseg;

// Variables globales
int Contador = 10; // 10 segundos para pruebas
unsigned long tiempoAnterior = 0; 
const unsigned long intervalo = 1000; // 1 segundo

// Pin del buzzer
const int buzzerPin = A0; // puedes usar otro pin digital

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_ANODE; 

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(50);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  sevseg.refreshDisplay();

  // Convertir segundos a formato MMSS
  int minutos = Contador / 60;
  int segundos = Contador % 60;
  int mostrar = minutos * 100 + segundos; 

  sevseg.setNumber(mostrar);

  // sistema de conteo cada segundo
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    if (Contador > 0) {
      Contador--; // cuenta regresiva cambiar a ++ para progresiva

      // Pitido corto cada segundo
      tone(buzzerPin, 1700, 100); 

    } else {
      // Alarma final: pitido y parpadeo simultáneos
      while (true) {
        // Encender todos los segmentos
        byte allOn[] = {0xFF, 0xFF, 0xFF, 0xFF}; 
        sevseg.setSegments(allOn);
        tone(buzzerPin, 2500); // tono continuo mientras está encendido
        for (int j = 0; j < 300; j++) { // mantener encendido ~300ms
          sevseg.refreshDisplay();
          delay(1);
        }

        // Apagar todos los segmentos y buzzer
        sevseg.blank();
        noTone(buzzerPin);
        for (int j = 0; j < 300; j++) { // mantener apagado ~300ms
          sevseg.refreshDisplay();
          delay(1);
        }
      }
    }
  }
}
