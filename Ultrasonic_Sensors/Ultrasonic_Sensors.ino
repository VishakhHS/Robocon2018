const int trigpin=9;
const int echopin=10;

long duration;
int distance;

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
  
  // put your main code here, to run repeatedly:

}
