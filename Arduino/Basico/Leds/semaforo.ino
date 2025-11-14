// Semáforo sencillo en Arduino
int tiempoEspera = 5000;
int rojo = 10;
int amarillo = 9;
int verde = 8;

void setup(){
  pinMode(rojo, OUTPUT);   
  pinMode(amarillo, OUTPUT);   
  pinMode(verde, OUTPUT);    
}

void loop() {
  digitalWrite(rojo, HIGH);     // rojo encendido
  delay(tiempoEspera);

  digitalWrite(verde, HIGH);      // verde encendido
  digitalWrite(rojo, LOW);      // rojo apagado
  delay(tiempoEspera);

  digitalWrite(amarillo, HIGH);      // amarillo encendido
  digitalWrite(verde, LOW);       // verde apagado
  delay(1000);

  digitalWrite(amarillo, LOW);       // amarillo apagado
}
