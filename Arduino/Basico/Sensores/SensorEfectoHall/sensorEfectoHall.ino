const int hallPin = A0;     // Pin analógico A0
const int buzzerPin = 8;    // Pin del buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);       // Para monitorear el valor leído
}

void loop() {
  int hallValue = analogRead(hallPin);
  Serial.println(hallValue); // Opcional: ver valores en el monitor serial

  // El KY-003 entrega valores bajos (~0) cuando detecta campo magnético
  if (hallValue < 100) { // Ajusta el umbral si es necesario
    digitalWrite(buzzerPin, HIGH); // Enciende buzzer
  } else {
    digitalWrite(buzzerPin, LOW);  // Apaga buzzer
  }
}
