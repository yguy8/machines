const int echo=10;
const int trig=9;
int LED1=7;
int LED2=6;
int LED3=5;
int LED4=4;

int duration=0;
int distance=0;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  Serial.begin(9600);

}

void loop() {

digitalWrite(trig,HIGH);
delay(1000);
digitalWrite(trig,LOW);
digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);

duration=pulseIn(echo,HIGH);
distance= (duration/2)/28.5;

if (distance<10){
  digitalWrite(LED1,HIGH);
}
else if (distance>=10 && distance <=20){
  digitalWrite(LED2,HIGH);
}
else if (distance>20 && distance <30){
  digitalWrite(LED3,HIGH);
}
else{
  digitalWrite(LED4,HIGH);
}

Serial.println(distance);
}
