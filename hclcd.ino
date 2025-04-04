int trigPin = 9; 
int echoPin = 8;
int buzzPin = 11;
int ledPinG = 13;
int dt = 500;

long duration;
int distance;
int safetyDistance;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzPin, OUTPUT);
pinMode(ledPinG, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  //limpia el trigPin 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //selecciona el trigPin por 10 microsegundos
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// lee el echoPin
duration = pulseIn(echoPin, HIGH);
//calcula la distancia
distance = duration*0.034/2;

safetyDistance = distance;
if(safetyDistance > 15){
  digitalWrite(buzzPin, HIGH);
  digitalWrite(ledPinG, LOW);
}
if(safetyDistance < 15){
  digitalWrite(buzzPin, LOW);
  digitalWrite(ledPinG, HIGH);
  
}
delay(dt);
//monitor info de como corre el programa 
Serial.print("Distancia: ");
Serial.println(distance);
}

