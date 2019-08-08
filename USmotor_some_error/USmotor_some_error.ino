int i = 100;
void setup()
{

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(10, HIGH);
  delayMicroseconds(5);

  digitalWrite(10, LOW);
  delayMicroseconds(5);

  digitalWrite(10, HIGH);
  delayMicroseconds(5);

  uint8_t x;
  x = analogRead(A0);
  Serial.println(x);
  delay(10);
}
