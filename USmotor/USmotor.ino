const int trigpin=9;
const int echopin=10;
const int motor=11;
const int dir=12;
 int  a=20;
 int  b=2;



long duration;
int distance;
int i;

void setup() {
    
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
 
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration=pulseIn(echopin, HIGH);

  distance=duration*0.034/2;

  Serial.print("Distance:");
  Serial.println(distance);

 /* if(distance<=a)
  {
   
     
     analogWrite(11, 60);
     digitalWrite(12, HIGH);
    
    if(distance==a-b)
    {
      analogWrite(11, 60);
      digitalWrite(12, HIGH);
      
    }
    else if(distance==a-2b)
    {
      analogWrite(11, 50);
      digitalWrite(12, HIGH);
      
    }    
    else if(distance==a-3b)
    {
      analogWrite(11, 30);
      digitalWrite(12, HIGH);
      
    }    
    else if(distance==a-4b)
    {
      analogWrite(11, 10);
      digitalWrite(12, HIGH);
      
    }
    else if(distance == (a-5b))
    {
      analogWrite(11, 0);
      digitalWrite(12, HIGH);
      
    }
    Serial.println("STOP");
  }
  else
  {
    analogWrite(motor, 80);
    digitalWrite(dir, HIGH);
    Serial.println("BEGIN");
  }
  // put your main code here, to run repeatedly:
*/
}
