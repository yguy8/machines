#include <IRremote.hpp>

const int RECV_PIN = 2;
const int WHITE_LED = 6;
const int RED_LED = 9;
const int BUZZER_PIN = 8;
const int LASER_PIN = 7;
const int LDR_PIN = A0;

const String CONTRASENA = "rana123";
const int UMBRAL_LUZ = 614; // Ajusta este valor según tus lecturas

bool sistemaActivo = false;
bool intrusoDetectado = false;

unsigned long tiempoAnterior = 0;
const unsigned long intervalo = 50;
int frecuencia = 1000;
int direccion = 1;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LASER_PIN, OUTPUT);
  digitalWrite(LASER_PIN, HIGH);
  apagarLuces();
  noTone(BUZZER_PIN);
  Serial.println("Sistema listo. Esperando activación...");
}

void loop() {
  // Activar sistema o apagar sirena con control remoto
  if (IrReceiver.decode()) {
    if (!sistemaActivo) {
      sistemaActivo = true;
      Serial.println("🔒 Sistema en modo alerta");
      digitalWrite(WHITE_LED, HIGH);
    } else if (intrusoDetectado) {
      desactivarSirena("🔓 Sirena desactivada por control remoto");
    }

    IrReceiver.resume();
    delay(1300);
  }

  // Verifica si el haz láser fue interrumpido
  if (sistemaActivo && !intrusoDetectado) {
    int luz = analogRead(LDR_PIN);
    Serial.print("LDR: ");
    Serial.println(luz); // Diagnóstico en tiempo real

    if (luz < UMBRAL_LUZ) {
      intrusoDetectado = true;
      Serial.println("🚨 INTRUSO DETECTADO");
      digitalWrite(WHITE_LED, LOW);
    }
  }

  // Si hay intruso, activa sirena
  if (intrusoDetectado) {
    actualizarSirena();
  }

  // Verifica si se envió la contraseña correcta
  if (Serial.available()) {
    String entrada = Serial.readStringUntil('\n');
    entrada.trim();
    if (entrada == CONTRASENA && intrusoDetectado) {
      desactivarSirena("✅ Sirena desactivada por contraseña");
    } else {
      Serial.println("❌ Contraseña incorrecta o no hay sirena activa.");
    }
  }
}

void actualizarSirena() {
  unsigned long ahora = millis();
  if (ahora - tiempoAnterior >= intervalo) {
    tiempoAnterior = ahora;

    frecuencia += direccion * 50;
    if (frecuencia >= 2500 || frecuencia <= 1000) {
      direccion *= -1;
    }

    tone(BUZZER_PIN, frecuencia);

    if (direccion > 0) {
      digitalWrite(RED_LED, HIGH);
    } else {
      digitalWrite(RED_LED, LOW);
    }
  }
}

void desactivarSirena(String mensaje) {
  intrusoDetectado = false;
  Serial.println(mensaje);
  noTone(BUZZER_PIN);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, HIGH);
}

void apagarLuces() {
  digitalWrite(WHITE_LED, LOW);
  digitalWrite(RED_LED, LOW);
}

