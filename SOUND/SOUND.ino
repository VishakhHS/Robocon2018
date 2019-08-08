long duration;
float distance;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  pinMode(7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(9,LOW);
delayMicroseconds(2);
digitalWrite(9,HIGH);
delayMicroseconds(10);
digitalWrite(9,LOW);
duration=pulseIn(10,HIGH);
distance=duration*0.034/2;
if(distance<=10)
{
  digitalWrite(7,HIGH);
  
}
else
{
   digitalWrite(7,LOW);
}
Serial.print("Distacnce:");
Serial.print(distance);
Serial.println("\tcm");
delay(100);
}
