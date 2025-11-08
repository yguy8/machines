const int sensorPin = 9;   // Pin del sensor
int buzz = 8;              // Pin del buzzer
int ledPin = 7;            // Pin del LED rojo

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valor = digitalRead(sensorPin);

  if (valor == HIGH) {
    // Estado normal: todo apagado
    digitalWrite(ledPin, LOW);
    noTone(buzz);
  } else {
    // Movimiento detectado: activar sirena
    sirena();
  }
}

// Función que genera el efecto de sirena mientras haya vibración
void sirena() {
  // Subida de frecuencia
  for (int freq = 500; freq <= 1000; freq += 50) {
    tone(buzz, freq);
    digitalWrite(ledPin, HIGH);
    delay(30);
    digitalWrite(ledPin, LOW);
    delay(30);

    // Si el sensor deja de detectar, salir inmediatamente
    if (digitalRead(sensorPin) == HIGH) {
      noTone(buzz);
      digitalWrite(ledPin, LOW);
      return;
    }
  }

  // Bajada de frecuencia
  for (int freq = 1000; freq >= 200; freq -= 50) {
    tone(buzz, freq);
    digitalWrite(ledPin, HIGH);
    delay(30);
    digitalWrite(ledPin, LOW);
    delay(30);

    // Si el sensor deja de detectar, salir inmediatamente
    if (digitalRead(sensorPin) == HIGH) {
      noTone(buzz);
      digitalWrite(ledPin, LOW);
      return;
    }
  }
}
