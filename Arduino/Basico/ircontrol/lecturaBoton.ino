#include <IRremote.hpp>

const int RECV_PIN = 2;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("Código RAW: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    Serial.print("Protocolo: ");
    Serial.println(IrReceiver.getProtocolString());

    IrReceiver.resume();
  }
}
