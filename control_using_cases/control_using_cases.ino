int i = 0;
int j = 0;
const int D = 10;
const int M = 9;

void setup() {

  pinMode(D, OUTPUT);
  pinMode(M, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
  /* for (i = 0; i <= 255; i++)
    {
     analogWrite(M, i);
     digitalWrite(D, HIGH);
    }
    delay(1000);
    analogWrite(M, 0);
  */


}

int x;
void loop() {

  Serial.print("Enter the case\n");
  x = Serial.read();
  switch (x)
  {
    /*case 'a': analogWrite(M, 64);
      digitalWrite(D, HIGH);
      Serial.print("64up");
      delay(5000);
      break;
      case 'b': analogWrite(M, 64);
      digitalWrite(D, LOW);
      Serial.print("64dn");
      delay(5000);
      break;
      case 'c':  analogWrite(M, 127);
      digitalWrite(D, HIGH);
      Serial.print("127up");
      delay(5000);
      break;
      case 'd': analogWrite(M, 127);
      digitalWrite(D, LOW);
      Serial.print("127dn");
      delay(5000);
      break;
      case 'e': analogWrite(M, 191);
      digitalWrite(D, HIGH);
      Serial.print("191up");
      delay(5000);
      break;
      case 'f': analogWrite(M, 191);
      digitalWrite(D, LOW);
      Serial.print("191dn");
      delay(5000);
      break;
      case 'g': analogWrite(M, 255);
      digitalWrite(D, HIGH);
      Serial.print("255up");
      delay(5000);
      break;
      case 'h': analogWrite(M, 255);
      digitalWrite(D, LOW);
      Serial.print("255dn");
      delay(5000);
      break;
      case 'j': analogWrite(M, 0);
              digitalWrite(D,LOW);
    */
    case 'v':  digitalWrite(D, LOW);
      analogWrite(M, 150);

      delay(300);

      analogWrite(M, 0);
      digitalWrite(D, HIGH);
      analogWrite(M, 100);
      delay(200);
      analogWrite(M, 0);
      break;
  }
  /*

    // put your main code here, to run repeatedly:
    if(x=='a')
    {

    }
    else if(x=='b')
    {

    }
    else if(x=='c')
    {

    }
    else if(x=='d')
    {

    }
    else if(x=='e')
    {
    analogWrite(M,191);
    digitalWrite(D,HIGH);
    }
    else if(x=='f')
    {
    analogWrite(M,191);
    digitalWrite(D,LOW);
    }
    else if(x=='g')
    {
    analogWrite(M,255);
    digitalWrite(D,HIGH);
    }
    else if(x=='h')
    {
    analogWrite(M,255);
    digitalWrite(D,LOW);
    }
    delay(5000);
    }*/
}
