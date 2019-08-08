const int LED=13;
const int SENSOR=53;
int valor;

int irRead(int readPin, int triggerPin);
void setup() {
  pinMode(SENSOR,INPUT);
  pinMode(LED,OUTPUT);
 
  // put your setup code here, to run once:

}

void loop() {

valor=digitalRead(SENSOR);
digitalWrite(LED,!valor);
delay(500);

  
  // put your main code here, to run repeatedly:

}
