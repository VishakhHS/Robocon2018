int i = 0;

const int De = 10;
const int Me = 9;
const int Da = 12;
const int Ma = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(De, OUTPUT);
  pinMode(Me, OUTPUT);
  pinMode(Da, OUTPUT);
  pinMode(Ma, OUTPUT);
  Serial.begin(9600);

  for(i=0;i<1;i++ )
  {
   
    analogWrite(Me,100);
    digitalWrite(De,LOW);
    analogWrite(Ma,100);
    digitalWrite(Da,LOW);
    
    
    delay(3000);
    Serial.println(i);
  }
 
  analogWrite(Ma,0);
  analogWrite(Me,0);
}

void loop() {
  // put your main code here, to run repeatedly:
   

}
