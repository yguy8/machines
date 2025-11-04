int ledPin = 12; // declaramos el led en el pin 12 del arduino
int sensorPin=11; // declaramos el sensor PIR en el pin 11
int buzz = 10;
int val = 0; //variable para asignar la lectura del sensor PIR

void setup()
{
pinMode(ledPin, OUTPUT); 
pinMode(sensorPin, INPUT);
pinMode(buzz, OUTPUT);
Serial.begin(9600);
for(int i = 0; i < 30; i++) //Utilizamos un for para calibrar el sensor 
{
delay(1000);
}
delay(50);
}
void loop()
{
val = digitalRead(sensorPin); //Lee el valor de la variable (val)
if (val == HIGH) //Si detecta que hay movimiento manda activar el led que hay conectado en el pin 12 del arduino
{
digitalWrite(ledPin, HIGH);
digitalWrite(buzz, HIGH);
}
else //Si la condición anterior no se cumple manda apagar el led
{
digitalWrite(ledPin, LOW);
digitalWrite(buzz, LOW);
}
}
