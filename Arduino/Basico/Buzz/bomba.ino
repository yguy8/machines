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
  // Alarma que acelera: pip más rápido y LED parpadeando sincronizado
  for (int i = 0; i < 20; i++) {
    int delayTime = 500 - i * 20;           // Disminuye de 500 ms a 100 ms
    if (delayTime < 100) delayTime = 100;

    int brightness = map(i, 0, 19, 50, 255); // Aumenta brillo de 50 a 255

    // Encender buzzer y LED al mismo tiempo
    tone(buzzer, 1000, 100);                
    analogWrite(redPin, brightness);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

    delay(100); // Duración del pip y del destello

    // Apagar buzzer y LED
    noTone(buzzer);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

    delay(delayTime - 100); // Esperar hasta el siguiente pip
  }

  // Explosión final: parpadeo blanco sincronizado con sonido
  for (int j = 0; j < 5; j++) {
    tone(buzzer, 3000, 100);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    delay(100);
    noTone(buzzer);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(100);
  }

  delay(3000); // Espera antes de repetir
}
