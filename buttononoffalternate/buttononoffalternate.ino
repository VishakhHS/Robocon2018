
const int button = 2;     
const int Motor =  9;  
const int direct = 10;    

int buttonState = 0;   
int count=0;
int a=2;
int b=0;     

void setup() {
 
  pinMode(Motor, OUTPUT);
  pinMode(button, INPUT);
  pinMode(direct, OUTPUT);
  Serial.begin(9600);

}

void loop() {
 
  
  buttonState = digitalRead(button);
 
  {
    
   
   
    if(buttonState==HIGH)
    {
      count++;
      Serial.println(count);
    delay(10);
       
     b=count%a;
  if (b==0)
  {
    
    analogWrite(Motor, 255);
    digitalWrite(direct, HIGH);
    //delay(1000);
    Serial.print("a");
    
  } 
  else if(b==1)
  {
    
    analogWrite(Motor, 255);
    digitalWrite(direct, LOW);
    //delay(1000);
    Serial.print("b");
  }
  }
    }
  
    


    
}
