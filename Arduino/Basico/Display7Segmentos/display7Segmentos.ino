//pines de arriba  de izquierda a derecha 8, 7, GND, 6, 5
//pines de abajo de izquierda a derecha 4, 3, GND, 2, 9

#include "SevSeg.h"
SevSeg sevseg; 

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
        sevseg.setNumber(4);  // número que queremos que represente
        sevseg.refreshDisplay();        
}
