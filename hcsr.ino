int trigPin = 12;
int echoPin = 11;
int pingTravelTime;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 pingTravelTime = pulseIn(echoPin, HIGH);
 delay(25);
 digitalWrite(trigPin, LOW);
 Serial.println(pingTravelTime);

}
