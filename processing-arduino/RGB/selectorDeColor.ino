int pinR = 9;   // Rojo
int pinG = 10;  // Verde
int pinB = 11;  // Azul

void setup() {
  Serial.begin(9600);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String datos = Serial.readStringUntil('\n'); // recibe hasta salto de línea
    int coma1 = datos.indexOf(',');
    int coma2 = datos.lastIndexOf(',');

    if (coma1 > 0 && coma2 > coma1) {
      int r = datos.substring(0, coma1).toInt();
      int g = datos.substring(coma1 + 1, coma2).toInt();
      int b = datos.substring(coma2 + 1).toInt();

      // Aplica valores PWM
      analogWrite(pinR, r);
      analogWrite(pinG, g);
      analogWrite(pinB, b);
    }
  }
}
