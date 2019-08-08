int i = 0;
//const int LED = 11;
const int D = 10;
const int M = 9;

void setup() {
  //pinMode(LED, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(M, OUTPUT);
  // put your setup code here, to run once:
for (int i = 0; i < 255; i++)
  {
    //analogWrite(LED, i);
    //analogWrite(LED1, i);
    analogWrite(M, i);
    digitalWrite(D, HIGH);
   
    delay(5);

  }

  for (int i = 255; i > 0; i--)
  {
    //analogWrite(LED, i);
    //analogWrite(LED1, i);
    analogWrite(M, i);
    digitalWrite(D, HIGH);
    delay(5);
  }
    delay(100);
  for (int i = 0; i < 255; i++)
  {
    //analogWrite(LED, i);
    //analogWrite(LED1, i);
    analogWrite(M, i);
    digitalWrite(D, LOW);
    delay(5);

  }
  for (int i = 255; i > 0; i--)
  {
    //analogWrite(LED, i);
    //analogWrite(LED1, i);
    analogWrite(M, i);
    digitalWrite(D, LOW);
    delay(5);
  }
  delay(100);



}


void loop() {
  







  

  // put your main code here, to run repeatedly:

}
