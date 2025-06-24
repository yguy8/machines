//leer valor de la fotoresistencia 


int lightPin = A2;
int lightVal;
int dt = 100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);
}

