const int m1=13;
const int dir1=12;
char z;
void setup() {

  
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  z=Serial.read();
  Serial.println(z);
  analogWrite(m1, z);
  digitalWrite(dir1, HIGH);


  
  // put your main code here, to run repeatedly:

}
