String myName;
String msg1 = "Escribe tu nombre";
String msg2 = "Hola, ";
String msg3 = ". Bienvenido a el mejor curso de Arduino";

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
//put your main code here, to run repeatedly:
Serial.println();
Serial.println(msg1);
while (Serial.available() == 0){

}

myName = Serial.readString();
Serial.print(msg2);
Serial.print(myName);
Serial.println(msg3);

}
