int sensor;
const int powerpin = 8;
const int redLed = 2;
const int greenLed = 3;
const int thresh = 500;

void setup(){
  Serial.begin(9600);
  pinMode(powerpin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop(){
  digitalWrite(powerpin, HIGH);
  delay(10);
  sensor = analogRead(A0;
  digitalWrite(powerpin, LOW);
  Serial.println(sensor);

  if(sensor > thresh){
    //green on red off
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  }else{
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
    delay(delayTime);
}
