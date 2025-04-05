#include <Servo.h>

Servo ioe;

int Y = 0;
int X = 1;
int P = 2;

void setup() {
  ioe.attach(2);
}
void loop() {

  int position_Y = analogRead(Y);
  int angulo = map(position_Y, 0, 1023, 0, 180);
  ioe.write(angulo);

  /*int position_X = analogRead(X);
  int angulo = map(position_X, 0, 1023, 0, 180);
  ioe.write(angulo);*/

    /*int position_P = analogRead(P);
  int angulo = map(position_P, 0, 1023, 0, 180);
  ioe.write(angulo);*/

    delay(10);
}
