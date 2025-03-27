int buzzPin = 8;
int number;
String msg1 = "Por favor introduce tu número";
int dt = 500;
void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println();
 Serial.println(msg1);
 while (Serial.available() == 0) {

 }
 number = Serial.parseInt();
 if (number > 10){
  digitalWrite(buzzPin, HIGH);
   delay(dt);
   digitalWrite(buzzPin, LOW);
 }

}
