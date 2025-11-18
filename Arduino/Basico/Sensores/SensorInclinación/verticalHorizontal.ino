int dt = 5000;
int pin7 = 7;
int pin2 = 2;
int ledAzul = 5;   //HORIZONTAL
int ledAmarillo = 6; //VERTICAL


void setup(){
    pinMode(pin7, INPUT);
    Serial.begin(9600);
    pinMode(pin2, OUTPUT);
    digitalWrite(pin2, HIGH);

    pinMode(ledAzul, OUTPUT);
    pinMode(ledAmarillo, OUTPUT);
}
 
void loop(){
    if (digitalRead(pin7)){
        //Serial.println("El sensor ha cambiado de posición");
        digitalWrite(ledAmarillo, HIGH);
        digitalWrite(ledAzul, LOW);
        //delay(dt);
    }else{
        //Serial.println("El sensor está en vertical");
        digitalWrite(ledAmarillo, LOW);
        digitalWrite(ledAzul, HIGH);
        //delay(dt);
    }
}
