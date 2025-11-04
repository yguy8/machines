int sensor;
//definición de lo spines
#define buzz 7
#define ledPinG 6
#define ledPinR 5
//declarando las salidas y entradas
void setup(){
  Serial.begin(9600);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  pinMode(buzz, OUTPUT);
}
//definiendo la lectura del sensor de agua
void loop(){
  sensor = analogRead(A0);
  //imprime el resultado en el monitor serial
  Serial.println(sensor);
  //tiempo de espera para imprir el resultado
  delay(1000);
//si la lectura del sensor es menor a 400 entonces el buzz y el led rojo están apagados y el led verde encendido 
  if (sensor < 400){
    digitalWrite(buzz, LOW);
    digitalWrite(ledPinG, HIGH);
    digitalWrite(ledPinR, LOW);
  }else{ //en caso contrario buzz y rojo encendido y verde apagado
    digitalWrite(buzz, HIGH);
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinR, HIGH);
  }
  //tiempo de espera para cambiar el resultado
  delay(1000);
}
