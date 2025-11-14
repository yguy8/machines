int ledAzul = 4;
int dt = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(ledAzul, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  int valor = analogRead(A3);
  Serial.print("Valor: ");
  Serial.println(valor);

  if(valor < 300){
    digitalWrite(ledAzul, HIGH);
    Serial.print("Lluvia fuerte led encendido");
    delay(dt);
  }else{
    digitalWrite(ledAzul, LOW);
    delay(dt);
  }
}
