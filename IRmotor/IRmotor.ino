int i=0;
const int M=9;
const int D=10;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  pinMode(M,OUTPUT);
  pinMode(D,OUTPUT);
  
  Serial.begin(9600);
  
}
int x;
void loop() {
  
  // put your main code here, to run repeatedly:
  x=digitalRead(2);
  Serial.println(x);
  if(x==1)
  {
    analogWrite(M, 0);
    digitalWrite(D,HIGH);
    digitalWrite(13,1);
    }

    if(x==0)
    {
      analogWrite(M, 255);
      digitalWrite(D,HIGH);
      digitalWrite(13,0);  
    }
}
