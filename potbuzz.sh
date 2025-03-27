int buzzPin = 8;
int potVal;
int potPin = A5;

void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 potVal = analogRead(potPin);
 Serial.println(potVal);

 if (potVal > 1000){
  digitalWrite(buzzPin, HIGH);
 }
 if (potVal < 1000){
  digitalWrite(buzzPin, LOW);
 }
}
