volatile int contador = 0;
int sensor = 3;

void setup() {
  pinMode(3, INPUT);
  Serial.begin(9600);
  attachInterrupt(1, interrupcion, RISING);
}

void loop() {
  delay(1000);
  Serial.print("Revoluciones por segundo: ");
  Serial.println(contador);
}

void interrupcion(){
    contador++;
}
