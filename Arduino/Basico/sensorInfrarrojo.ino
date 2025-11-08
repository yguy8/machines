const int sensorPin = 9;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int valor = 0;
  valor = digitalRead(sensorPin);

  if(valor == HIGH){
    Serial.println("Zona despejada");
  }else{
    Serial.println("Obstaculo detectado");
  }
  delay(5000);
}
