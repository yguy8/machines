int SensorPin = A0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int humedad = analogRead(SensorPin);
  Serial.println(humedad);
  delay(1000);
}
