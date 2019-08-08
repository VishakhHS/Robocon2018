const int D = 10;
const int M = 9;
void setup() {
  pinMode(D, OUTPUT);
  pinMode(M, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(M, 255);
    digitalWrite(D, HIGH);
    delay(1000);
}
