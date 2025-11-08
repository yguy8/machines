int sensorPin = 4;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  if(digitalRead(sensorPin) == HIGH){
    Serial.println("Va en la dirección correcta");
  }else{
    Serial.println("Salio fuera de la linea negra");
  }
  delay(50);
}
