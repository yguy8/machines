import processing.serial.*;

Serial puerto;
String dato;

void setup(){
  String nombrePuerto = Serial.list()[0];
  puerto = new Serial(this, nombrePuerto, 9600);
}

void draw(){
  if(puerto.available() > 0){
    dato = puerto.readStringUntil('\n');
  }
  println("Dato recibido: " + dato);
}
