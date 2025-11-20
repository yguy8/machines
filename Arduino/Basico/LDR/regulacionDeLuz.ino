int valorLDR = A0;
int pinLED = 9;

int valor;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  valor = analogRead(valorLDR);
  Serial.println(valor);

  // Ajusta este umbral según tu sensor y ambiente
  if (valor > 500) {  
    digitalWrite(pinLED, HIGH);   // Apaga el LED si hay luz
  } else {
    digitalWrite(pinLED, LOW);  // Enciende el LED si está oscuro
  }

  delay(100);
}
