int SensorPin = A0;
int ledAdvertencia = 7;
int ledBuenEstado = 6;
int buzz = 3;

void setup(){
  Serial.begin(9600);
  pinMode(ledAdvertencia, OUTPUT);
  pinMode(ledBuenEstado, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop(){
  int humedad = analogRead(SensorPin);
  // Serial.println(humedad);
  // delay(1000);
  int nivel = 0;
  
  // Clasificamos el valor en niveles
  if (humedad < 300) {
    nivel = 0; // Muy mojado
  } else if (humedad < 600) {
    nivel = 1; // Húmedo ideal
  } else if (humedad < 800) {
    nivel = 2; // Seco moderado
  } else {
    nivel = 3; // Muy seco
  }

  switch (nivel){
    case 0: 
    digitalWrite(ledAdvertencia, 1);
    digitalWrite(ledBuenEstado, 0);
    digitalWrite(buzz, 1);
    break;
    case 1: 
    digitalWrite(ledAdvertencia, 0);
    digitalWrite(ledBuenEstado, 1);
    digitalWrite(buzz, 0);
    break;
    case 2: 
    digitalWrite(ledAdvertencia, 1);
    digitalWrite(ledBuenEstado, 0);
    digitalWrite(buzz, 1);
    delay(1000);
    digitalWrite(buzz, 1);
    delay(100);
    break;
    case 3: 
    digitalWrite(ledAdvertencia, 1);
    digitalWrite(ledBuenEstado, 0);
    digitalWrite(buzz, 1);
    break;
    default: 
    digitalWrite(ledAdvertencia, 1);
    digitalWrite(ledBuenEstado, 1);
    digitalWrite(buzz, 1);
    Serial.println("Algo anda mal :(");
    break;
  }


}
