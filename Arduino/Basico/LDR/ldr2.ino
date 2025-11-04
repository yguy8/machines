//alerta de oscuridad con leds

int gPin = 8;
int rPin = 9;
int lightPin = A2;
int lightVal;
int dt = 100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(gPin, OUTPUT);
  pinMode(rPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);

  if (lightVal< 700){
    digitalWrite(gPin, 1);
    digitalWrite(rPin, 0);
  }
  if (lightVal> 700){
    digitalWrite(gPin, 0);
    digitalWrite(rPin, 1);
  }
}

