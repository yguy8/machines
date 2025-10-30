int pir = 2;
int ledVerde = 3; 
int ledRojo = 4;
int buzz = 5;
int estado = 0;

void setup(){
  pinMode(pir, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(buzz, OUTPUT);
  delay(20000);
}
void loop(){
  estado = digitalRead(pir);
  if(estado == HIGH){
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzz, HIGH);
    delay(4000);
  }else{
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(buzz, LOW);
  }
}
