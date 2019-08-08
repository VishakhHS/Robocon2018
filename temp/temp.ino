const byte temp_pin=A3;
void setup() {
  // put your setup code here, to run once:
pinMode(A3,INPUT);
Serial.begin(9600);
}
int value=0;
int temp=0;

void loop() {
  // put your main code here, to run repeatedly:
value=analogRead(A3);
temp=(5.0*value*100.0)/1024;
Serial.println(temp);
delay(1000);

}
