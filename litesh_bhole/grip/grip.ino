void setup() {
  // put your setup code here, to run once:

pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

}

void loop() {
analogWrite(9,30);
digitalWrite(10,LOW);
delay(200);

analogWrite(9,30);
digitalWrite(10,HIGH);
delay(300);
analogWrite(9,0);
digitalWrite(10,HIGH);
delay(1000);


  
  // put your main code here, to run repeatedly:

}
