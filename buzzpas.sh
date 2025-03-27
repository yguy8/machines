int buzzPin = 4;
int dt = 10000;
void setup()  {    # put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  # put your main code here, to run repeatedly:
 digitalWrite(buzzPin, HIGH);
 delayMicroseconds(dt);
 digitalWrite(buzzPin, LOW);
 delayMicroseconds(dt);
}
