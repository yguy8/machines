#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  analogReadResolution(12);//0 -4095
  pinMode(32, OUTPUT);
  digitalWrite(32, LOW);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  float analogValue = analogRead(36);
  volt = analogValue*3.3/4095;
  
}
*/
void onLedChange()  {
  // Add your code here to act upon Led change
  digitalWrite(32, led);
}
