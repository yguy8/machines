#include <LiquidCrystal.h>
#include <Servo.h>
// servo y joystick
Servo cj;
int Y = A0;
int myServo = 6;
// sensor
int trigPin = 10;
int echoPin = 9;
long duracion;
int distancia;
int ultimaDistancia = 0;
// de la LCD
int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  // servo
  cj.attach(myServo);
  //sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  //LCD 
  lcd.begin(16, 2);
}

void loop() {
  //servo  y joystick 
  int position_Y = analogRead(Y);
  int angulo = map(position_Y, 0, 1023, 0, 180);
  cj.write(angulo);
  delay(10);
  //sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion * 0.034) / 2;
  Serial.println(distancia);
  // LCD
  if (distancia != ultimaDistancia) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distancia: ");
    lcd.setCursor(0, 1);
    lcd.print(distancia);
    lcd.print(" cm");
    ultimaDistancia = distancia;
  }
  delay(500);
}
