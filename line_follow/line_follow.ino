const byte rx = 0;    // Defining pin 0 as Rx
const byte tx = 1;    // Defining pin 1 as Tx
const byte rx1 = 0;
const byte rx2 = 0;
const byte rx3 = 0;
const byte jPulse = 53;   // Connect JPULSE of LSA08 to pin 4
const byte jPulse2 = 45;
const byte jPulse3 = 41;
const byte jPulse4 = 35;//37
const byte digital_1 = 51;
const byte digital_2 = 47;
const byte digital_3 = 39;
const byte digital_4 = 33;//35
const byte dir1 = 44;
const byte dir2 = 46;
const byte dir3 = 48;
const byte dir4 = 50;
const byte pwm1 = 5;
const byte pwm2 = 4;
const byte pwm3 = 3;
const byte pwm4 = 2;
const byte laser1 = 49;
const byte laser2 = 43;
const byte laser3 = 37;//33
const byte laser4 = 31;
unsigned int junctionCount = 0;   // Variable to store junction count value
unsigned int junctionCount2 = 0;
unsigned int junctionCount3 = 0;
unsigned int junctionCount4 = 0;

unsigned int digital_stop_1 = 0;
unsigned int digital_stop_2 = 0;
unsigned int digital_stop_3 = 0;
unsigned int digital_stop_4 = 0;
int flag = 0;
int flagx = 0;
int flag1 = 0;
int flag1x = 0;
int flag1y = 0;
int flag1z = 0;
int flag1n = 0;
int flag1m = 0;
unsigned int laser_interrupt_1 ;
unsigned int laser_interrupt_2;
unsigned int laser_interrupt_3;
unsigned int laser_interrupt_4;
int a = 0;
int b = 0;
int c = 0;
int d = 0;


volatile int err = 0;


void setup()
{
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);

  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);

  pinMode(jPulse, INPUT);
  pinMode(jPulse2, INPUT);
  pinMode(jPulse3, INPUT);
  pinMode(jPulse4, INPUT);
  pinMode(rx, INPUT);
  pinMode(rx1, INPUT);
  pinMode(rx2, INPUT);
  pinMode(rx3, INPUT);
  pinMode(digital_1, INPUT);
  pinMode(digital_2, INPUT);
  pinMode(digital_3, INPUT);
  pinMode(digital_4, INPUT);
  pinMode(laser1, INPUT);
  pinMode(laser2, INPUT);
  pinMode(laser3, INPUT);

  // digitalWrite(4,HIGH);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  analogWrite(pwm1, 90);
  analogWrite(pwm2, 90);
}

void line_follow()
{
  if ((a > 24) && (a < 96))
  {
    analogWrite(pwm3, 17);
    digitalWrite(dir3, HIGH);
  }
  else if (a >= 96)
  {
    analogWrite(pwm3, 22);
    digitalWrite(dir3, HIGH);
  }

  else if (a == 24)
  {
    analogWrite(pwm3, 0);
    digitalWrite(dir3, LOW);
  }
  else if ((a < 24) && (a > 8))
  {
    analogWrite(pwm3, 17);
    digitalWrite(dir3, LOW);
  }
  else if (a <= 8)
  {
    analogWrite(pwm3, 22);
    digitalWrite(dir3, LOW);
  }

}

void line_follow1()
{
  if ((b > 24) && (b < 96))
  {
    analogWrite(pwm2, 17);
    digitalWrite(dir2, LOW);
  }
  else if (b >= 96)
  {
    analogWrite(pwm2, 22);
    digitalWrite(dir2, LOW);
  }

  else if (b == 24)
  {
    analogWrite(pwm2, 0);
    digitalWrite(dir2, HIGH);
  }
  else if ((b < 24) && (b > 8))
  {
    analogWrite(pwm2, 17);
    digitalWrite(dir2, HIGH);
  }
  else if (b <= 8)
  {
    analogWrite(pwm2, 22);
    digitalWrite(dir2, HIGH);
  }
}

void line_follow2()
{
  if ((c > 24) && (c < 96))
  {
    analogWrite(pwm1, 17);
    digitalWrite(dir1, HIGH);
  }
  else if (c >= 96)
  {
    analogWrite(pwm1, 22);
    digitalWrite(dir1, HIGH);
  }

  else if (c == 24)
  {
    analogWrite(pwm1, 0);
    digitalWrite(dir1, LOW);
  }
  else if ((c < 24) && (c > 8))
  {
    analogWrite(pwm1, 17);
    digitalWrite(dir1, LOW);
  }
  else if (c <= 8)
  {
    analogWrite(pwm1, 22);
    digitalWrite(dir1, LOW);
  }

}

void line_follow3()
{
  if ((d > 24) && (d < 96))
  {
    analogWrite(pwm4, 17);
    digitalWrite(dir4, LOW);
  }
  else if (d >= 96)
  {
    analogWrite(pwm4, 22);
    digitalWrite(dir4, LOW);
  }

  else if (d == 24)
  {
    analogWrite(pwm4, 0);
    digitalWrite(dir4, HIGH);
  }
  else if ((d < 24) && (d > 8))
  {
    analogWrite(pwm4, 17);
    digitalWrite(dir4, HIGH);
  }
  else if (d <= 8)
  {
    analogWrite(pwm4, 22);
    digitalWrite(dir4, HIGH);
  }

}


void loop()
{


  a = Serial1.read();
  Serial.println(a);
  b = Serial2.read();
  c = Serial3.read();
  d = Serial.read();
  junctionCount = digitalRead(jPulse);
  junctionCount2 = digitalRead(jPulse2);
  junctionCount3 = digitalRead(jPulse3);
  junctionCount4 = digitalRead(jPulse4);
  digital_stop_1 = digitalRead(digital_1);
  digital_stop_2 = digitalRead(digital_2);
  digital_stop_3 = digitalRead(digital_3);
  digital_stop_4 = digitalRead(digital_4);
  laser_interrupt_1 = digitalRead(laser1);
  laser_interrupt_2 = digitalRead(laser2);
  laser_interrupt_3 = digitalRead(laser3);
  laser_interrupt_4 = digitalRead(laser4);
  // Serial.println(laser_interrupt_1);
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  digitalWrite(dir3, LOW);
  digitalWrite(dir4, LOW);
 // Serial.println("u");
  line_follow();

  if ((junctionCount == 1) && (flag == 0))
  {


    flag = 1;
 //   Serial.println("flag");
  }
  if ((digital_stop_1 == 1) && (flag == 1))
  {
    flag = 2;
 //   Serial.println("flag2");
    // delay(1000);

    while (flag == 2)
    {
      a = Serial1.read();
 //     Serial.println("while");
      line_follow(); //pwm3
      junctionCount = digitalRead(jPulse);
      digital_stop_1 = digitalRead(digital_1);

      if (junctionCount == 1)
      {
        a = Serial1.read();
        analogWrite(pwm1, 40);
        analogWrite(pwm2, 40);
        line_follow();
        flag1 = 1;
        flag = 3;
 //       Serial.println("Slow");
        digital_stop_1 = digitalRead(digital_1);
      }
    }

  }




  if ((digital_stop_1 == 1) && (flag1 == 1))
  {
    flag1 = 2;
    if (digital_stop_1 == 1)
    {
      analogWrite(pwm1, 0);
      analogWrite(pwm2, 0);
      analogWrite(pwm3, 0);

    }
  }

  if ( (laser_interrupt_1 == 1) && (flag1 == 2))
  {

    while ((laser_interrupt_1 == 1) && (flag1 == 2))
    {
      b = Serial2.read();
     // Serial.print("b == ");
     // Serial.println(b);
      analogWrite(pwm4, 50);
      analogWrite(pwm3, 50);

      digitalWrite(dir3, LOW);
      digitalWrite(dir4, LOW);
      line_follow1();
      junctionCount2 = digitalRead(jPulse2);
      digital_stop_2 = digitalRead(digital_2);

      if (junctionCount2 == 1)
      {
        flag1 = 3;
        line_follow1();
        while ((junctionCount2 == 1) && (flag1 == 3) )
        {
          b = Serial2.read();
     //     Serial.print("b = ");
       //   Serial.println(b);
          digital_stop_2 = digitalRead(digital_2);
          analogWrite(pwm4, 25);
          analogWrite(pwm3, 25);

          digitalWrite(dir3, LOW);
          digitalWrite(dir4, LOW);
          line_follow1();
          laser_interrupt_2 = digitalRead(laser2);
          flag1x == 2;

          if (digital_stop_2 == 1) //&& (flag1x == 2))
          {

            //flag1x = 3;
            flag1 = 4;
            while ((digital_stop_2 == 1) && (flag1 == 4))
            {
              analogWrite(pwm1, 0);
              analogWrite(pwm2, 0);
              analogWrite(pwm3, 0);
              analogWrite(pwm4, 0);
          //    Serial.println("stop");
              laser_interrupt_2 = digitalRead(laser2);
              flag1n = 2;

              if ((laser_interrupt_2 == 1) && (flag1n == 2))
              {


          //      Serial.println("detect");
                flag1 = 6;
                flag1y = 2;
                flag1x = 3;
                flag1n = 3;
              }
            }

            //Serial.println(pwm3);
          }
        }


      }

      /*  digital_stop_2 = digitalRead(digital_2);
        if ((digital_stop_2 == 1))// && (flag1x == 1))
        {
          flag1x = 3;
          flag1 = 3;
          if (digital_stop_2 == 1)
          {
            analogWrite(pwm1, 0);
            analogWrite(pwm2, 0);
            analogWrite(pwm3, 0);
            analogWrite(pwm4, 0);
            Serial.println(pwm3);

          }
        }
      */
    }

  }
  ////////////////////////reverse

  if ( (laser_interrupt_2 == 1) && (flag1y == 2))
  {

    while ((laser_interrupt_2 == 1) && (flag1y == 2))
    {
      c = Serial3.read();
    //  Serial.print("c = ");
    //  Serial.println(c);
      digitalWrite(dir3, HIGH);
      digitalWrite(dir4, HIGH);

      analogWrite(pwm3, 50);
      analogWrite(pwm4, 50);
      //    digitalWrite(dir3, LOW);
      //      digitalWrite(dir4, LOW);


      line_follow2();
      junctionCount3 = digitalRead(jPulse3);
      digital_stop_2 = digitalRead(digital_2);

      if (junctionCount3 == 1)
      {
        flag1y = 3;
        line_follow2();
        while ((junctionCount3 == 1) && (flag1y == 3) )
        {

          c = Serial3.read();
          line_follow2();
          digital_stop_2 = digitalRead(digital_2);
          digitalWrite(dir3, HIGH);
          digitalWrite(dir4, HIGH);

          analogWrite(pwm4, 25);
          analogWrite(pwm3, 25);
          
          if (digital_stop_2 == 1)
          {
            while (digital_stop_2 == 1)
            {
              flag1y = 4;
              // flag1x = 2;
              flag1y = 5;
              analogWrite(pwm1, 0);
              analogWrite(pwm2, 0);
              analogWrite(pwm3, 0);
              analogWrite(pwm4, 0);
        //      Serial.println("Stop");
        //      Serial.println(pwm3);
            }
          }
        }


      }


    }

  }


  ///////////tz1
  if ( (laser_interrupt_3 == 1) && (flag1m == 0))
  {

    while ((laser_interrupt_3 == 1) && (flag1m == 0))
    {
      d = Serial.read();
     // Serial.print("d = ");
   //   Serial.println(d);
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, HIGH);

      analogWrite(pwm1, 50);
      analogWrite(pwm2, 50);
      analogWrite(pwm3, 0);

      line_follow3();
      junctionCount4 = digitalRead(jPulse4);
      digital_stop_1 = digitalRead(digital_1);

      if (junctionCount4 == 1)
      {
        flag1m = 3;
        line_follow3();
        while ((junctionCount4 == 1) && (flag1m == 3) )
        {

          d = Serial.read();
          digital_stop_1 = digitalRead(digital_1);
          digitalWrite(dir1, HIGH);
          digitalWrite(dir2, HIGH);
       //   Serial.println("slow");
          analogWrite(pwm1, 25);
          analogWrite(pwm2, 25);
          analogWrite(pwm3, 0);
          line_follow3();
          if (digital_stop_1 == 1)
          {
            flagx = 1;

            while (flagx == 1)
            {
              // flag1x = 2;
              flag1m = 4;
              line_follow1();
              b = Serial2.read();
              analogWrite(pwm1, 0);

              analogWrite(pwm3, 50);
              analogWrite(pwm4, 50);

              digitalWrite(dir3, LOW);
              digitalWrite(dir4, LOW);
       //
     //
     
   //Serial.println("In");
    //          Serial.println(pwm2);
              junctionCount2 = digitalRead(jPulse2);
            
              if (junctionCount2 == 1) 
              {
                 junctionCount2 = digitalRead(jPulse2);
                flag1m = 5;
                while (flag1m == 5)
                {
                  line_follow1();
                  b = Serial2.read();
                  analogWrite(pwm1, 0);

                  analogWrite(pwm3, 25);
                  analogWrite(pwm4, 25);

                  digitalWrite(dir3, LOW);
                  digitalWrite(dir4, LOW);
                //  Serial.println("InSlow");
                //  Serial.println(pwm2);
                  digital_stop_4 = digitalRead(digital_4);
                  if (digital_stop_4 == 1)
                  {

                    flag1m = 5;
                    flagx = 2;
                    while (flag1m == 8)
                    {
                      analogWrite(pwm3, 0);
                      analogWrite(pwm4, 0);
                      analogWrite(pwm1, 0);
                      analogWrite(pwm2, 0);
                      digitalWrite(dir1, LOW);
                      digitalWrite(dir2, LOW);
                      digitalWrite(dir3, LOW);
                      digitalWrite(dir4, LOW);
                     // Serial.println("StoP");
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}


