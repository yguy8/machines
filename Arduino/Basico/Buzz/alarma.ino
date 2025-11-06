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
  for (int i = 0; i < 10; i++) { // Repetir 10 veces
    tone(buzzer, 1000, 200); // Beep agudo
    setColor(i % 6);         // Cambiar color RGB
    delay(200);
    noTone(buzzer);
    setColor(-1);            // Apagar LED
    delay(200);
  }

  delay(3000); // Espera antes de repetir la alarma
}

// Función para cambiar color del LED RGB
void setColor(int colorIndex) {
  switch (colorIndex) {
    case 0: analogWrite(redPin, 255); analogWrite(greenPin, 0);   analogWrite(bluePin, 0);   break; // Rojo
    case 1: analogWrite(redPin, 0);   analogWrite(greenPin, 255); analogWrite(bluePin, 0);   break; // Verde
    case 2: analogWrite(redPin, 0);   analogWrite(greenPin, 0);   analogWrite(bluePin, 255); break; // Azul
    case 3: analogWrite(redPin, 255); analogWrite(greenPin, 255); analogWrite(bluePin, 0);   break; // Amarillo
    case 4: analogWrite(redPin, 0);   analogWrite(greenPin, 255); analogWrite(bluePin, 255); break; // Cian
    case 5: analogWrite(redPin, 255); analogWrite(greenPin, 0);   analogWrite(bluePin, 255); break; // Magenta
    default: analogWrite(redPin, 0);  analogWrite(greenPin, 0);   analogWrite(bluePin, 0);   break; // Apagar
  }
}
