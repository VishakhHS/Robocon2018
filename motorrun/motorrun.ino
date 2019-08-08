
const int D = 10;
const int M = 9;

void setup() {

  pinMode(D, OUTPUT);
  pinMode(M, OUTPUT);
  // Serial.begin(9600);


  digitalWrite(D, LOW);
  analogWrite(M, 210);

  delay(320);

  analogWrite(M, 0);
  digitalWrite(D, HIGH);
  analogWrite(M, 80);
  delay(199);
  analogWrite(M, 0);



  /*
    for (int i = 0; i < 255; i++)
    {
    //analogWrite(LED, i);
    //analogWrite(LED1, i);
    analogWrite(M, i);
    digitalWrite(D, HIGH);
    Serial.println(i);

    delay(5);

    }

    for (int i = 255; i > 0; i--)
    {
    //analogWrite(LED, i);
    //analogWrite(LED1, i);
    analogWrite(M, i);
    digitalWrite(D, HIGH);
    Serial.println(i);
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

  */
}
void loop() {



  /*
    for (int i = 0; i < 255; i++)
    {
      //analogWrite(LED, i);
      //analogWrite(LED1, i);
      analogWrite(M, i);
      digitalWrite(D, HIGH);
      Serial.println(i);

      delay(5);

    }

    for (int i = 255; i > 0; i--)
    {
      //analogWrite(LED, i);
      //analogWrite(LED1, i);
      analogWrite(M, i);
      digitalWrite(D, HIGH);
      Serial.println(i);
      delay(5);
    }




  */
  // put your main code here, to run repeatedly:

}
