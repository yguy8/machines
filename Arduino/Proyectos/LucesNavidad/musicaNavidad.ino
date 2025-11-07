// Pines
int buzzer = 8;
int leds[] = {2, 3, 4, 5, 6, 7}; // Puedes usar más LEDs si quieres

// Notas musicales (frecuencia en Hz)
int melody[] = {
  659, 659, 659, 659, 659, 659, 659, 784, 523, 587, 659
};

// Duración de cada nota (en milisegundos)
int noteDurations[] = {
  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 600
};

void setup() {
  pinMode(buzzer, OUTPUT);
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 11; i++) {
    tone(buzzer, melody[i], noteDurations[i]);

    // Efecto de luces bailarinas
    digitalWrite(leds[i % 6], HIGH);
    delay(noteDurations[i]);
    digitalWrite(leds[i % 6], LOW);

    delay(50); // Pausa entre notas
  }

  delay(1000); // Pausa entre repeticiones
}
