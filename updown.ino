int buttonPin = 4;
int ledPin = 2;
int buttonRead;
int dt = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9660);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonRead = digitalRead(buttonPin);
  Serial.println(buttonRead);
  delay(dt);

  if (buttonRead = 0) {
    digitalWrite(ledPin, 1);
  } else {
    digitalWrite(ledPin, 0);
  }

