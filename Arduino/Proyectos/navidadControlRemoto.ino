#include <IRremote.hpp>

const int RECV_PIN = 2;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int BUZZER_PIN = 8;

int mode = 0;
unsigned long lastBlink = 0;
bool ledState = false;
unsigned long lastNoteTime = 0;
int noteIndex = 0;

const int colors[][3] = {
  {255, 0, 0},     // Rojo
  {0, 255, 0},     // Verde
  {0, 0, 255},     // Azul
  {255, 255, 0},   // Amarillo
  {0, 255, 255},   // Cian
  {255, 0, 255},   // Magenta
  {255, 255, 255}, // Blanco
  {128, 0, 128},   // Púrpura
  {255, 165, 0}    // Naranja
};

const int numColors = sizeof(colors) / sizeof(colors[0]);

int melody[] = {
  659, 659, 659, 659, 659, 659, 659, 784, 523, 587, 659,
  698, 698, 698, 698, 698, 659, 659, 659, 659, 587, 587, 659, 587, 784
};

int durations[] = {
  200, 200, 400, 200, 200, 400, 200, 200, 200, 200, 400,
  200, 200, 400, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 400
};

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  setColor(0);
}

void loop() {
  // Reproduce música en bucle
  playLoopedMelody();

  // Detecta cualquier señal IR
  if (IrReceiver.decode()) {
    mode = (mode + 1) % numColors; // Cambia modo de baile
    Serial.print("Modo de baile cambiado a: ");
    Serial.println(mode);
    IrReceiver.resume();
  }

  // Ejecuta el modo de baile actual
  animateLights(mode);
}

void setColorRGB(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void setColor(int index) {
  setColorRGB(colors[index][0], colors[index][1], colors[index][2]);
}

void animateLights(int index) {
  unsigned long now = millis();
  int speed = 300 + (index * 50); // velocidad variable según modo

  if (now - lastBlink > speed) {
    ledState = !ledState;
    if (ledState) {
      setColor(index);
    } else {
      setColorRGB(0, 0, 0);
    }
    lastBlink = now;
  }
}

void playLoopedMelody() {
  unsigned long now = millis();
  if (noteIndex >= sizeof(melody) / sizeof(int)) {
    noteIndex = 0; // reinicia la canción
  }

  if (now - lastNoteTime > durations[noteIndex] * 1.3) {
    tone(BUZZER_PIN, melody[noteIndex], durations[noteIndex]);
    lastNoteTime = now;
    noteIndex++;
  }
}
