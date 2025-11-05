int ledA = 9;
int ledB = 8;
int ledV = 7;

void setup(){
  Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledV, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){
    int opcion = Serial.parseInt();

    if(opcion == 1){
      primerBaile();
    }else if (opcion == 2){
      segundoBaile();
    }else{
      Serial.println("No hubo baile que bailar");
    }
  }
  delay(1000);
}

void primerBaile(){
  int leds[] = {ledA, ledB, ledV};

//   for(int i = 0; i < 3; i++){
//     digitalWrite(leds[i], HIGH);
//     delay(200);
//     digitalWrite(leds[i], LOW);
//   }
//   for(int i = 0; i < 3; i++){
//     digitalWrite(leds[i], HIGH);
//   }
//     delay(300);
//   for(int i = 0; i < 3; i++){
//     digitalWrite(leds[i], LOW);
//   }
//     delay(300);
// }

  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
  }
  for (int i = 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
  }

  //Estrobo loco
  for (int j = 0; j < 10; j++) {
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledV, HIGH);
    delay(50);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledV, LOW);
    delay(50);
  }

  //Aleatorio total
  for (int i = 0; i < 10; i++) {
    int r = random(0, 3);
    digitalWrite(leds[r], HIGH);
    delay(80);
    digitalWrite(leds[r], LOW);
  }

  //Todos juntos con ritmo invertido
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(150);
  for (int i = 2; i >= 0; i--) {
    digitalWrite(leds[i], LOW);
    delay(100);
  }

  delay(300);
}
void segundoBaile(){
  int leds[] = {ledA, ledB, ledV};
  // Rebote: ida
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }

  // Rebote: vuelta
  for (int i = 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }

  // Estrobo: parpadeo rápido
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(leds[i], HIGH);
    }
  delay(80);
    for (int i = 0; i < 3; i++) {
      digitalWrite(leds[i], LOW);
    }
    delay(80);
  }

  delay(300); // Pausa entre coreografías
  
}
