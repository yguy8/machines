// Pines
int buzzer = 8;
int redPin = 3;
int greenPin = 5;
int bluePin = 6;
int ldrPin = A0;     // Entrada analógica para la LDR
int laserPin = 7;    // Pin digital para controlar el láser

int laserThreshold = 500; // Ajusta este valor según tu entorno

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(laserPin, OUTPUT);

  digitalWrite(laserPin, HIGH); // Encender el láser al iniciar
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  if (ldrValue < laserThreshold) {
    digitalWrite(laserPin, LOW); // Apagar láser durante la alarma (opcional)
    activarAlarma();
    digitalWrite(laserPin, HIGH); // Volver a encender después
  }
}

// Función de alarma con pip acelerado, colores cálidos y pitido final largo
void activarAlarma() {
  for (int i = 0; i < 20; i++) {
    int delayTime = 500 - i * 20;
    if (delayTime < 100) delayTime = 100;

    int freq = 1000 + i * 50;
    int colorIndex = i % 4;

    tone(buzzer, freq, 100);
    setWarmColor(colorIndex);

    delay(100);
    noTone(buzzer);
    setWarmColor(-1);

    delay(delayTime - 100);
  }

  delay(1000);

  tone(buzzer, 3500);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
  delay(1500);
  noTone(buzzer);
  setWarmColor(-1);

  delay(5000);
}

// Colores cálidos sincronizados
void setWarmColor(int index) {
  switch (index) {
    case 0: analogWrite(redPin, 255); analogWrite(greenPin, 50);  analogWrite(bluePin, 0);   break; // Rojo intenso
    case 1: analogWrite(redPin, 255); analogWrite(greenPin, 150); analogWrite(bluePin, 0);   break; // Naranja
    case 2: analogWrite(redPin, 255); analogWrite(greenPin, 255); analogWrite(bluePin, 0);   break; // Amarillo
    case 3: analogWrite(redPin, 255); analogWrite(greenPin, 100); analogWrite(bluePin, 100); break; // Rosa cálido
    default: analogWrite(redPin, 0);  analogWrite(greenPin, 0);   analogWrite(bluePin, 0);   break; // Apagar
  }
}
