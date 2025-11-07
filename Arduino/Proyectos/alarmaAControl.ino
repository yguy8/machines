#include <IRremote.hpp>

const int RECV_PIN = 2;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int BUZZER_PIN = 8;

bool alarmaActiva = false;
unsigned long lastBlink = 0;
bool ledState = false;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  apagarRGB();
  noTone(BUZZER_PIN);
}

void loop() {
  // Detecta cualquier señal IR
  if (IrReceiver.decode()) {
    alarmaActiva = !alarmaActiva;

    if (alarmaActiva) {
      Serial.println("🔔 Alarma ACTIVADA");
    } else {
      Serial.println("🔕 Alarma DESACTIVADA");
      apagarRGB();
      noTone(BUZZER_PIN);
    }

    IrReceiver.resume();
    delay(300); // Evita rebotes
  }

  // Si la alarma está activa, parpadea en rojo y suena el buzzer
  if (alarmaActiva) {
    tone(BUZZER_PIN, 1000); // Sonido constante
    parpadeoRojo();
  }
}

void parpadeoRojo() {
  unsigned long now = millis();
  if (now - lastBlink > 300) {
    ledState = !ledState;
    if (ledState) {
      analogWrite(RED_PIN, 255);
      analogWrite(GREEN_PIN, 0);
      analogWrite(BLUE_PIN, 0);
    } else {
      apagarRGB();
    }
    lastBlink = now;
  }
}

void apagarRGB() {
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
}
