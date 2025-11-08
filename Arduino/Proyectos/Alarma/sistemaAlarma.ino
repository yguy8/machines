#include <IRremote.hpp>

const int RECV_PIN = 2;
const int BLUE_LED = 6;   // LED azul (indicador principal)
const int RED_LED = 9;
const int BUZZER_PIN = 8;
const int LASER_PIN = 7;
const int LDR_PIN = A0;

const String CONTRASENA = "rana123";
const int UMBRAL_LUZ = 200; // Ajusta este valor según tus lecturas

bool sistemaActivo = false;
bool intrusoDetectado = false;

unsigned long tiempoAnterior = 0;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LASER_PIN, OUTPUT);

  // Láser APAGADO al inicio; solo se enciende al activar el sistema
  digitalWrite(LASER_PIN, LOW);

  apagarLuces();
  noTone(BUZZER_PIN);
  Serial.println("Sistema listo. Esperando activación...");
}

void loop() {
  // Activar sistema o apagar sirena con control remoto
  if (IrReceiver.decode()) {
    if (!sistemaActivo) {
      activarSistema();
    } else if (intrusoDetectado) {
      desactivarSirena("Sirena desactivada por control remoto");
      // El sistema sigue activo, no se apaga el láser
    }
    IrReceiver.resume();
    delay(1300);
  }

  // Verifica si el haz láser fue interrumpido (solo si está activo y sin intruso)
  if (sistemaActivo && !intrusoDetectado) {
    int luz = analogRead(LDR_PIN);
    Serial.print("LDR: ");
    Serial.println(luz);

    // Con láser directo esperas bajo (≈25); intrusión cuando sube por encima del umbral
    if (luz > UMBRAL_LUZ) {
      intrusoDetectado = true;
      Serial.println("INTRUSO DETECTADO");
      digitalWrite(BLUE_LED, LOW);
    }
  }

  // Si hay intruso, activa sirena
  if (intrusoDetectado) {
    actualizarSirena();
  }

  // Activación/desactivación por contraseña
  if (Serial.available()) {
    String entrada = Serial.readStringUntil('\n');
    entrada.trim();

    if (entrada == CONTRASENA) {
      if (!sistemaActivo) {
        // Armar el sistema por contraseña (pitidos + destellos y luz azul fija)
        activarSistema();
      } else if (intrusoDetectado) {
        // Si hay sirena activa, se desactiva
        desactivarSirena("Sirena desactivada por contraseña");
        // El sistema queda armado; láser permanece encendido
      } else {
        Serial.println("Sistema ya activo y sin sirena.");
      }
    } else {
      Serial.println("Contraseña incorrecta.");
    }
  }
}

void activarSistema() {
  sistemaActivo = true;
  Serial.println("Sistema en modo alerta");

  // Enciende el láser al activar
  digitalWrite(LASER_PIN, HIGH);

  // Secuencia de activación: 3 pitidos + 3 destellos azul
  activarAlarmaAviso();

  // Al terminar la secuencia, LED azul queda encendido fijo
  digitalWrite(BLUE_LED, HIGH);

  // Diagnóstico inicial de LDR para que ajustes umbral si hace falta
  int luzInicial = analogRead(LDR_PIN);
  Serial.print("LDR (activado): ");
  Serial.println(luzInicial);
}

void activarAlarmaAviso() {
  for (int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, 1500);          // Pitido
    digitalWrite(BLUE_LED, HIGH);    // LED azul encendido
    delay(200);                      // Duración
    noTone(BUZZER_PIN);
    digitalWrite(BLUE_LED, LOW);     // LED azul apagado
    delay(200);                      // Pausa entre pitidos
  }
}

void actualizarSirena() {
  unsigned long ahora = millis();
  if (ahora - tiempoAnterior >= 300) {
    tiempoAnterior = ahora;

    static bool tonoAlto = false;
    tonoAlto = !tonoAlto;

    int frecuencia = tonoAlto ? 500 : 100; // Alterna tonos
    tone(BUZZER_PIN, frecuencia);

    digitalWrite(RED_LED, tonoAlto ? HIGH : LOW);
  }
}

void desactivarSirena(String mensaje) {
  intrusoDetectado = false;
  Serial.println(mensaje);
  noTone(BUZZER_PIN);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);   // Azul encendido: sistema sigue armado
  // Láser permanece encendido porque el sistema está activo
}

void apagarLuces() {
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);
}
