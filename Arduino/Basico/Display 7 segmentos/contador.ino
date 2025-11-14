#include "SevSeg.h"
SevSeg sevseg;

void setup() {
    byte numDigits = 1;
    byte digitPins[] = {2}; // pin común del dígito
    byte segmentPins[] = {6,5,2,3,4,7,8,9}; // A,B,C,D,E,F,G,DP
//pines de arriba  de izquierda a derecha 8, 7, GND, 6, 5
//pines de abajo de izquierda a derecha 4, 3, GND, 2, 9
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(50);
}

void loop() {
    for (int i = 0; i < 10; i++) {
        sevseg.setNumber(i);
        unsigned long start = millis();
        while (millis() - start < 1000) {
            sevseg.refreshDisplay(); // refrescar constantemente
        }
    }
}
