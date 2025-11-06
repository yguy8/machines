// Pines
int buzzer = 8;
int redPin = 3;
int greenPin = 5;
int bluePin = 6;

// Notas musicales
#define NOTE_E5 659
#define NOTE_G5 784
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_F5 698

// Melodía de Jingle Bells (simplificada)
int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5
};

int durations[] = {
  300, 300, 600,
  300, 300, 600,
  300, 300, 300, 300, 600,
  300, 300, 300, 300,
  300, 300, 300, 300, 300,
  300, 300, 300, 300, 300, 600
};

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
    tone(buzzer, melody[i], durations[i]);

    // Cambiar color RGB al ritmo con 12 combinaciones
    setColor(i % 12);
    delay(durations[i]);
    setColor(-1); // Apagar RGB

    delay(50); // Pausa entre notas
  }

  delay(1000); // Pausa antes de repetir
}

// Función para cambiar color del LED RGB
void setColor(int colorIndex) {
  switch (colorIndex) {
    case 0:  analogWrite(redPin, 255); analogWrite(greenPin, 0);   analogWrite(bluePin, 0);   break; // Rojo
    case 1:  analogWrite(redPin, 0);   analogWrite(greenPin, 255); analogWrite(bluePin, 0);   break; // Verde
    case 2:  analogWrite(redPin, 0);   analogWrite(greenPin, 0);   analogWrite(bluePin, 255); break; // Azul
    case 3:  analogWrite(redPin, 255); analogWrite(greenPin, 255); analogWrite(bluePin, 0);   break; // Amarillo
    case 4:  analogWrite(redPin, 0);   analogWrite(greenPin, 255); analogWrite(bluePin, 255); break; // Cian
    case 5:  analogWrite(redPin, 255); analogWrite(greenPin, 0);   analogWrite(bluePin, 255); break; // Magenta
    case 6:  analogWrite(redPin, 255); analogWrite(greenPin, 128); analogWrite(bluePin, 0);   break; // Naranja
    case 7:  analogWrite(redPin, 255); analogWrite(greenPin, 0);   analogWrite(bluePin, 128); break; // Rosa
    case 8:  analogWrite(redPin, 128); analogWrite(greenPin, 0);   analogWrite(bluePin, 255); break; // Violeta
    case 9:  analogWrite(redPin, 0);   analogWrite(greenPin, 128); analogWrite(bluePin, 255); break; // Turquesa
    case 10: analogWrite(redPin, 255); analogWrite(greenPin, 255); analogWrite(bluePin, 255); break; // Blanco
    case 11: analogWrite(redPin, 128); analogWrite(greenPin, 255); analogWrite(bluePin, 0);   break; // Lima
    default: analogWrite(redPin, 0);   analogWrite(greenPin, 0);   analogWrite(bluePin, 0);   break; // Apagar
  }
}
