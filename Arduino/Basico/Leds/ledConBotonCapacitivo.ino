#define ledA 3
#define ledB 2
#define botonCap 4

void setup() {
  // put your setup code here, to run once:
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(botonCap, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(botonCap)== HIGH){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
  } else {
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
  }
  delay(50);
}
