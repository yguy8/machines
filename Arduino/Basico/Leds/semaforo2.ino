int tiempoCruce = 5000;
unsigned long tiempoCambio = 0;
int rojo = 10;
int amarillo = 9;
int verde = 8;
int boton = 6;
int azul = 3;
int blanco = 2;


void setup(){
  // semaforo coches
  pinMode(rojo, OUTPUT);  // rojo
  pinMode(amarillo, OUTPUT);   // amarillo
  pinMode(verde, OUTPUT);   // verde
  // semáforo peatones
  pinMode(azul, OUTPUT);   // rojo
  pinMode(blanco, OUTPUT);   // verde
  pinMode(boton, INPUT);    // pulsador, cambio de color
  digitalWrite(verde, HIGH);    // iniciamos con el verde encendido, coche
  digitalWrite(rojo, HIGH);    // iniciamos con el rojo encendido, peatón
}

void loop() {
 int estado = digitalRead(boton);
 if (estado == LOW && (millis() - tiempoCambio) > 5000 ){
  cambioLuz();
 }
}

void cambioLuz() {
  digitalWrite(verde,LOW);    // verde apagado, coche
  digitalWrite(amarillo, HIGH);  // amarillo encendido, coche
  delay(2000);
  
  digitalWrite(amarillo, LOW);   // amarillo apagado, coche
  digitalWrite(rojo, HIGH); // rojo encendido, coche
  delay(1000);
  
  digitalWrite(azul, LOW);   // azul apagado, peatón
  digitalWrite(blanco, HIGH);  // blanco encendido, peatón
  delay(tiempoCruce);
  // parpadeo de la luz blanca del peatón
  for (int x=0; x < 10; x++) {
    digitalWrite(blanco, HIGH);
    delay(250);
    digitalWrite(blanco, LOW);
    delay(250);
  }
  
  digitalWrite(azul, HIGH);    // azul encendido, peatón
  delay(500);
  
  digitalWrite(rojo, LOW);    // rojo apagado, coche
  digitalWrite(verde, HIGH);    // verde encendido, coche
  tiempoCambio = millis();
}
