#include <Servo.h>

Servo ioe;

int Y = 0;

void setup() {
  ioe.attach(2);
}
void loop() {
  int position_Y = analogRead(Y);
  int angulo = map(position_Y, 0, 1023, 0, 180);
  ioe.write(angulo);
  delay(10);
}
