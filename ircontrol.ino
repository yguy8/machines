#include <IRremote.h>
int IrPin = 9;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 IrReceiver.begin(IrPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(IrReceiver.decode() == 0){

  }
  Serial.println(IrReceiver.decodedIRData.command);
  IrReceiver.resume();
}
