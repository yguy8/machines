const int sensorPin = 9;
int buzz = 8;
int ledPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valor = 0;
  valor = digitalRead(sensorPin);

  if(valor == HIGH){
    //Serial.println("Zona despejada");
    digitalWrite(ledPin, 0);
    digitalWrite(buzz, 0);
  }else{
    //Serial.println("Obstaculo detectado");
    digitalWrite(ledPin, 1);
    digitalWrite(buzz, 1);
  }
  //delay(500);
}
