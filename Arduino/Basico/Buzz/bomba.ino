// Pines
int buzzer = 8;
int redPin = 3;
int greenPin = 5;
int bluePin = 6;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Alarma que acelera: pip más rápido y colores cálidos sincronizados
  for (int i = 0; i < 20; i++) {
    int delayTime = 500 - i * 20;           // De 500 ms a 100 ms
    if (delayTime < 100) delayTime = 100;

    int freq = 1000 + i * 50;               // Tono sube: 1000 → 2000 Hz
    int colorIndex = i % 4;                 // 4 colores cálidos

    tone(buzzer, freq, 100);                // Pip corto
    setWarmColor(colorIndex);               // Color cálido sincronizado

    delay(100);                             // Duración del pip y color
    noTone(buzzer);
    setWarmColor(-1);                       // Apagar LED

    delay(delayTime - 100);                 // Espera hasta el siguiente pip
  }

  // Silencio tenso antes del pitido final
  delay(1000);

  // Pitido final largo y destello blanco
  tone(buzzer, 3500);                       // Pitido sostenido
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
  delay(1500);
  noTone(buzzer);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);

  delay(5000); // Espera antes de repetir
}

// Función para colores cálidos sincronizados con el pip
void setWarmColor(int index) {
  switch (index) {
    case 0: analogWrite(redPin, 255); analogWrite(greenPin, 50);  analogWrite(bluePin, 0);   break; // Rojo intenso
    case 1: analogWrite(redPin, 255); analogWrite(greenPin, 150); analogWrite(bluePin, 0);   break; // Naranja
    case 2: analogWrite(redPin, 255); analogWrite(greenPin, 255); analogWrite(bluePin, 0);   break; // Amarillo
    case 3: analogWrite(redPin, 255); analogWrite(greenPin, 100); analogWrite(bluePin, 100); break; // Rosa cálido
    default: analogWrite(redPin, 0);   analogWrite(greenPin, 0);   analogWrite(bluePin, 0);   break; // Apagar
  }
}
