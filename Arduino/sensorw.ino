//indica con un led y zumbador la alerta de nivel de agua
const int analogInPin = A0;
int sensorValue = 0;

int ledG = 2;
int ledY = 3;
int ledR = 4;
int buzz = 5;

void setup() {
  // declare pin  to be an output:
  pinMode(ledG,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(2);
  if(sensorValue>=150){
    digitalWrite(ledG,HIGH);
    digitalWrite(ledY,LOW);
    digitalWrite(ledR,LOW);
    digitalWrite(buzz,LOW);
    delay(100);
    }
  else if(sensorValue>=251){
   digitalWrite(ledY,HIGH);
   digitalWrite(ledG,LOW);
    digitalWrite(ledR,LOW);
    digitalWrite(buzz,LOW);
   delay(100);
    }  
  else if(sensorValue>=450){
    digitalWrite(ledR,HIGH);
    digitalWrite(ledY,LOW);
    digitalWrite(ledG,LOW);
    digitalWrite(buzz,HIGH);
    }
  else{
    digitalWrite(ledG,LOW);
    digitalWrite(ledY,LOW);
    digitalWrite(ledR,LOW);
    digitalWrite(buzz,LOW);
    delay(100);
    }
}
