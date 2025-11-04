int sensor;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //imprimir la humedad
  sensor = analogRead(A0);
  Serial.println(sensor);
}
