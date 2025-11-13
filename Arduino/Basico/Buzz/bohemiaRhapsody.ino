int Re4 = 293.665;
int Fa3 = 174.614;
int Sib3 = 233.082;
int Fa4 = 349.228;
int Sol4 = 391.995;
  
void setup() {
  pinMode(6, OUTPUT);
}

void loop () {
  tone(6, Re4);
  delay(500);
 tone(6, Fa3);
  delay(500);
 tone(6, Sib3);
   delay(500);
  tone(6, Re4);
  delay(500);
 tone(6, Sol4);
   delay(1000);
 tone(6, Fa4);
  delay(1000);
}
