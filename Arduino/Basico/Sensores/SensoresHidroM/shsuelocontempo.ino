int sensor;
const int pinDeEncendido = 0;
const int tiempoDeEspera = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(pinDeEncendido, OUTPUT);
}

void loop() {
  //imprimir la humedad
  digitalWrite(pinDeEncendido, HIGH);
  delay(10);
  sensor = analogRead(A0);
  digitalWrite(pinDeEncendido)
  Serial.println(sensor);
  delay(tiempoDeEspera);
}
