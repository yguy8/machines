int dt = 5000;
int pin7 = 7;
int pin2 = 2;

void setup(){
    pinMode(pin7, INPUT);
    Serial.begin(9600);
    pinMode(pin2, OUTPUT);
    digitalWrite(pin2, HIGH);
}
 
void loop(){
    if (digitalRead(pin7)){
        Serial.println("El sensor ha cambiado de posición");
        delay(dt);
    }else{
        Serial.println("El sensor está en vertical");
        delay(dt);
    }
}
