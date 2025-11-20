// Pines para cada LED
int ledRojo = 2;
int ledVerde = 3;
int ledAzul = 4;
int ledAmarillo = 5;
int ledBlanco = 6;

void setup() {
  Serial.begin(9600); // Comunicación con Processing
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledBlanco, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();

    // Apagar todos primero
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledBlanco, LOW);

    // Encender según comando
    if (comando == 'R') digitalWrite(ledRojo, HIGH);
    if (comando == 'G') digitalWrite(ledVerde, HIGH);
    if (comando == 'B') digitalWrite(ledAzul, HIGH);
    if (comando == 'Y') digitalWrite(ledAmarillo, HIGH);
    if (comando == 'W') digitalWrite(ledBlanco, HIGH);
  }
}
