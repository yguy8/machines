#include <Servo.h>

Servo myservo;  // Objeto Servo
int potPin = A0;  // Pin analógico conectado al potenciómetro
int pos = 0;     // Variable para almacenar la posición del servo

void setup() {
  myservo.attach(9);  // Conecta el servo al pin 9
}

void loop() {
  pos = analogRead(potPin);  // Lee el valor del potenciómetro (0-1023)
  pos = map(pos, 0, 1023, 0, 170);  // Mapea el valor a un rango de ángulo (0-180)
  myservo.write(pos);  // Mueve el servo a la posición deseada
  delay(15);  // Pequeña pausa
}
