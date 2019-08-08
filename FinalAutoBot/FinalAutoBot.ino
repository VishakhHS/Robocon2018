const int motor = 6;
const int dir = 7;
const int laser = 4;
//const int act = 8;
//const int led = 13;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
  // pinMode(13, OUTPUT);
  // pinMode(8, OUTPUT);
  // Serial.begin(9600);

  int x;


  do
  {
    x = digitalRead(4);
    digitalWrite(dir, LOW);
    analogWrite(motor, 250);

  } while (x != 1);

  // digitalWrite(act, LOW);
  analogWrite(motor, 0);
  digitalWrite(dir, HIGH);
  analogWrite(motor, 100);

  analogWrite(motor, 0);


}
//
int x;
void loop() {
  /*digitalWrite(13, HIGH);
    x = digitalRead(4);
    if (x = 1)
    {
    digitalWrite(act, HIGH);
    }
    else if (x = 0)
    {
    digitalWrite(act, LOW);
    }

  */

}
