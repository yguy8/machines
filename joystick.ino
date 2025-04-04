//para leer los valores en x y y del joystick


int xPin = A0;
int yPin = A1;
int buttonPin = 7;
int buttonVal;
int buzzPin = 8;
int xVal;
int yVal;
int dt = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonVal = digitalRead(buttonPin);
  Serial.print("valor de x =  ");
    Serial.print(xVal);
  Serial.print("  valor de y = ");
    Serial.print(yVal);
  Serial.print(" valor de boton  = ");
    Serial.println(buttonVal);
    delay(dt);
}
