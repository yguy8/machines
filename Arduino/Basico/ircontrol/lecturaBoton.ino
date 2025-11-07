#include <IRremote.hpp>

const int RECV_PIN = 2;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

const uint32_t COLOR_BUTTON = 0xAD52FF00; // Código del botón IR

int colorIndex = 0;

// Lista de colores RGB
const int colors[][3] = {
  {255, 0, 0},     // Rojo
  {0, 255, 0},     // Verde
  {0, 0, 255},     // Azul
  {255, 255, 0},   // Amarillo
  {0, 255, 255},   // Cian
  {255, 0, 255},   // Magenta
  {255, 255, 255}, // Blanco
  {128, 0, 128},   // Púrpura
  {255, 165, 0},   // Naranja
  {0, 0, 0}        // Apagado
};

const int numColors = sizeof(colors) / sizeof(colors[0]);

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  setColor(0); // Inicia con el primer color
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t receivedCode = IrReceiver.decodedIRData.decodedRawData;

    Serial.print("Código recibido: 0x");
    Serial.println(receivedCode, HEX);

    if (IrReceiver.decodedIRData.protocol == NEC && receivedCode == COLOR_BUTTON) {
      colorIndex = (colorIndex + 1) % numColors; // Avanza al siguiente color
      setColor(colorIndex);
    }

    IrReceiver.resume();
  }
}

void setColor(int index) {
  analogWrite(RED_PIN, colors[index][0]);
  analogWrite(GREEN_PIN, colors[index][1]);
  analogWrite(BLUE_PIN, colors[index][2]);

  Serial.print("Color cambiado a índice ");
  Serial.println(index);
}
