#define Led 3
#define TTP223B 4

void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
  pinMode(TTP223B, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(TTP223B)== HIGH){
    digitalWrite(Led, HIGH);
  } else {
    digitalWrite(Led, LOW);
  }
  delay(50);
}
