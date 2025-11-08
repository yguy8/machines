const int sensorPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int valor = 0;
  valor = digitalRead(sensorPin);

  if(valor == HIGH){
    Serial.println("Estado normal");
  }else{
    Serial.println("Movimiento detectado");
  }
  delay(500);
}
