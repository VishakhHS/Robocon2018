const int motor = 9;
const int dir = 10;
const int laser = 4;
const int act = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, INPUT);
  pinMode(8, OUTPUT);

  Serial.begin(9600);
  
   int x = 0;
 //  while(1)
   //{
 


   //}
}
int x;
void loop() {
  // put your main code here, to run repeatedly:
     x = digitalRead(4);
    
 
 /* do
  {

    x = digitalRead(4);

    digitalWrite(dir, LOW);
    analogWrite(motor, 150);
  }
  while (x != 0) ;
*/

if(x!=0)
{
 digitalWrite(act, HIGH);

  


   }
   else
   {
    digitalWrite(act, LOW);
    /*analogWrite(motor, 0);
  digitalWrite(dir, HIGH);
  analogWrite(motor, 20);
  delay(199);
  analogWrite(motor, 0);
  Serial.println("Stop");
  */
   }

}
