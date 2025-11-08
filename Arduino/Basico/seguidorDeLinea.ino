int sensorPin = 4;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  //salida digital 
  if(digitalRead(sensorPin) == HIGH){
    Serial.println("Va en la dirección correcta");
  }else{
    Serial.println("Salio fuera de la linea negra");
  }
  delay(50);

  //salida pin análogo
  // cuando no es la linea negra el valor es aprox 25 y cuando hay algo negro sube de entre 300-800
  
  //int valorAnalogo = analogRead(0);
  //Serial.print("El valor análogo es: ");
  //Serial.println(valorAnalogo);
  //delay(200);
}
