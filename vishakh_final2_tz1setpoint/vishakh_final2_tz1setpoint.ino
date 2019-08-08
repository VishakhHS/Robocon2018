#define      TRUE  1U
#define      FALSE 0U


const byte rx = 0;    // Defining pin 0 as Rx
const byte tx = 1;    // Defining pin 1 as Tx
const byte rx1 = 0;
const byte rx2 = 0;
const byte jPulse = 53;   // Connect JPULSE of LSA08 to pin 4
const byte jPulse2 = 45;
const byte jPulse3 = 41;
const byte jPulse4 = 35;
const byte digital_1 = 51;
const byte digital_2 = 47;
const byte digital_3 = 39;
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
const byte laser3 = 37;
const byte laser4 = 33;
const byte button = 9;
const byte pwm8 = 6;
const byte dir = 7;
const byte actuate = 9;
const byte button1 = 12;
const byte button2 = 13;
int buttonState1 = 0;
int buttonState2 = 0;
int case3_test_case = 0;

int buttonState = 0;
int actuateState = 0;
//////////////////////////TEST FLAGS////////////////////////

bool case_three_execution_status = FALSE;

//////////////////////////////////////////////////////////

unsigned int junctionCount = 0;   // Variable to store junction count value
unsigned int junctionCount2 = 0;
unsigned int junctionCount3 = 0;
unsigned int junctionCount4 = 0;

unsigned int digital_stop_1 = 0;
unsigned int digital_stop_2 = 0;
unsigned int digital_stop_3 = 0;
int flag1 = 0;
int flag1x = 0;
int flag1y = 0;
int flag1z = 0;
int flag1n = 0;
int flagtz = 0;
int flag1s = 0;
int flag5 = 0;
int flag1v = 0;
int flagstart = 0;
int flagstart2 = 0;
int flagtzstop = 0;
unsigned int laser_interrupt_1;
unsigned int laser_interrupt_2;
unsigned int laser_interrupt_3;
unsigned int laser_interrupt_4;
int a = 0;
int b = 0;
int c = 0;
int m = 0, n = 0;
int t = 0, u = 0;
int w, x, y, z, flag = 0;
int w1, x1, y1, z1;
int w2, x2, y2, z2;
int m3 = 0, n3 = 0;
int mx = 0, nx = 0;
int flagtz1 = 0;
int flagtz1x = 0;
int flagtz1y = 0;
int flag5n = 0;
int flagsh = 0;
int flagshuruwat = 0;
int flagsuruwat = 0;
int flagcase1 = 0;
int flagcase2 = 0;
int flagcase3 = 0;
int flagcase1start = 0;
int flagcase2start = 0;
int flagcase3start = 0;
int m4 = 0, n4 = 0;
int ms = 0, ns = 0;
int ma = 0, na = 0;
int mq = 0, nq = 0;
int mw = 0, nw = 0;


volatile char err = 0, lerr = 0;
volatile float corr = 0;
volatile float kp = 0.4, pro = 0;//0.5
volatile float ki = 0.0, intg = 0, I = 0;//0.00001
volatile float kd = 0.0, diff = 0;//0.0002
volatile float pwm = 0;



//volatile int err = 0;

int laser;
void setup() {

  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);

  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);


  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);


  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);

  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);

  pinMode(jPulse, INPUT);
  pinMode(jPulse2, INPUT);
  pinMode(jPulse3, INPUT);
  pinMode(jPulse4, INPUT);

  pinMode(rx, INPUT);
  pinMode(rx1, INPUT);
  pinMode(rx2, INPUT);
  //
  //  pinMode(button1, OUTPUT);
  //  pinMode(button2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(pwm8, OUTPUT);
  //pinMode(actuate, OUTPUT);
  pinMode(actuate, INPUT);

  pinMode(digital_1, INPUT);
  pinMode(digital_2, INPUT);
  pinMode(digital_3, INPUT);
  pinMode(laser1, INPUT);
  pinMode(laser2, INPUT);
  pinMode(laser3, INPUT);
  pinMode(laser4, INPUT);

  // digitalWrite(4,HIGH);
  Serial.begin(9600);
  Serial1.begin(115200);
  //Serial2.begin(9600);
  //Serial3.begin(9600);
  while (flagsuruwat == 0)
  {
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, LOW);
    analogWrite(pwm3, 40);
    analogWrite(pwm4, 40);
    digital_stop_2 = digitalRead(digital_2);
    if ((digital_stop_2 == 1) && (flagshuruwat == 0))
    {
      flagshuruwat = 1;
      analogWrite(pwm3, 0);
      analogWrite(pwm4, 0);
      while (flagshuruwat == 1)
      {
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, LOW);
        //////**
        w1 = digitalRead(A4);
        x1 = digitalRead(A5);
        y1 = digitalRead(A6);
        z1 = digitalRead(A7);

        Serial.println("start");
        analogWrite(pwm1, 90);
        analogWrite(pwm2, 90);
        analogWrite(pwm4, 0);
        //a = Serial1.read();
        //1 Serial.print("a == ");
        //Serial.println(a);
        //Serial1.begin(115200);
        //digital_stop_1 = digitalRead(digital_1);
        line1();
        // line_follow();
        //-------------------------------------------
        junctionCount = digitalRead(jPulse);
        if ((junctionCount == 1) && (flag1 == 0))
        {
          w1 = digitalRead(A4);
          x1 = digitalRead(A5);
          y1 = digitalRead(A6);
          z1 = digitalRead(A7);
          flag1 = 1;
          line1();
          while (flag1 == 1)
          {
            digital_stop_1 = digitalRead(digital_1);
            w1 = digitalRead(A4);
            x1 = digitalRead(A5);
            y1 = digitalRead(A6);
            z1 = digitalRead(A7);
            line1();
            analogWrite(pwm1, 40);
            analogWrite(pwm2, 40);
            digitalWrite(dir1, LOW);
            digitalWrite(dir2, LOW);
            if (digital_stop_1 == 1)
            {
              line1();
              flag1 = 2;
              while (flag1 == 2)
              {
                line1();
                w1 = digitalRead(A4);
                x1 = digitalRead(A5);
                y1 = digitalRead(A6);
                z1 = digitalRead(A7);
                Serial.println("start_stop");
                analogWrite(pwm1, 0);
                analogWrite(pwm2, 0);
                analogWrite(pwm3, 0);
                analogWrite(pwm4, 0);

                flagstart2 = 1;

                flagshuruwat = 9;
                flagsuruwat = 9;
                flag1 = 5;
                //   flag1 = 9;
                flagstart = 3;
                m = 0;
                n = 0;
              }
            }
          }
        }
      }
    }
  }
}

void line()
{
  if ((w == 1) && (x == 0) && (y == 0) && (z == 0))
  {
    analogWrite(pwm1, 22);//22
    digitalWrite(dir1, LOW);
  }

  if ((w == 1) && (x == 1) && (y == 0) && (z == 0))
  {
    analogWrite(pwm1, 18);//18
    digitalWrite(dir1, LOW);
  }

  if ((w == 0) && (x == 1) && (y == 1) && (z == 0))
  {
    analogWrite(pwm1, 0);
    digitalWrite(dir1, LOW);
  }

  if ((w == 0) && (x == 0) && (y == 1) && (z == 1))
  {
    analogWrite(pwm1, 18);
    digitalWrite(dir1, HIGH);
  }

  if ((w == 0) && (x == 0) && (y == 0) && (z == 1))
  {
    analogWrite(pwm1, 22);
    digitalWrite(dir1, HIGH);
  }

  //  if ((w == 1) && (x == 1) && (y == 1) && (z == 1))
  //  {
  //    //    analogWrite(pwm1, 40);
  //    //    analogWrite(pwm2, 40);
  //    //
  //    //    digitalWrite(dir1, HIGH);
  //    //    digitalWrite(dir2, HIGH);
  //  }

}

void line1()
{
  if ((w1 == 1) && (x1 == 0) && (y1 == 0) && (z1 == 0))
  {
    analogWrite(pwm3, 200);
    digitalWrite(dir3, LOW);
  }

  if ((w1 == 1) && (x1 == 1) && (y1 == 0) && (z1 == 0))
  {
    analogWrite(pwm3, 50);
    digitalWrite(dir3, LOW);
  }

  if ((w1 == 0) && (x1 == 1) && (y1 == 1) && (z1 == 0))
  {
    analogWrite(pwm3, 0);
    digitalWrite(dir3, HIGH);
  }

  if ((w1 == 0) && (x1 == 0) && (y1 == 1) && (z1 == 1))
  {
    analogWrite(pwm3, 50);
    digitalWrite(dir3, HIGH);
  }

  if ((w1 == 0) && (x1 == 0) && (y1 == 0) && (z1 == 1))
  {
    analogWrite(pwm3, 200);
    digitalWrite(dir3, HIGH);
  }

  //  if ((w == 1) && (x == 1) && (y == 1) && (z == 1))
  //  {
  //    //    analogWrite(pwm1, 40);
  //    //    analogWrite(pwm2, 40);
  //    //
  //    //    digitalWrite(dir1, HIGH);
  //    //    digitalWrite(dir2, HIGH);
  //  }

}

void line2()
{
  if ((w2 == 1) && (x2 == 0) && (y2 == 0) && (z2 == 0))
  {
    analogWrite(pwm2, 28);//28
    digitalWrite(dir2, HIGH);
  }

  if ((w2 == 1) && (x2 == 1) && (y2 == 0) && (z2 == 0))
  {
    analogWrite(pwm2, 22);//22
    digitalWrite(dir2, HIGH);
  }

  if ((w2 == 0) && (x2 == 1) && (y2 == 1) && (z2 == 0))
  {
    analogWrite(pwm2, 0);
    digitalWrite(dir2, LOW);
  }

  if ((w2 == 0) && (x2 == 0) && (y2 == 1) && (z2 == 1))
  {
    analogWrite(pwm2, 22);
    digitalWrite(dir2, LOW);
  }

  if ((w2 == 0) && (x2 == 0) && (y2 == 0) && (z2 == 1))
  {
    analogWrite(pwm2, 28);
    digitalWrite(dir2, LOW);
  }

  //  if ((w == 1) && (x == 1) && (y == 1) && (z == 1))
  //  {
  //    //    analogWrite(pwm1, 40);
  //    //    analogWrite(pwm2, 40);
  //    //
  //    //    digitalWrite(dir1, HIGH);
  //    //    digitalWrite(dir2, HIGH);
  //  }

}


void line_follow()
{
  pro = kp * err;
  diff = kd * (err - lerr);
  I = I + err;
  intg = I * kd;
  corr = pro + diff + intg;
  pwm = corr * 20;
  analogWrite(pwm4, pwm);
  Serial.println(a);

  if (a == 24)
  {
    //analogWrite(pwm3, 0);
    err = 0;
    digitalWrite(dir4, LOW);
  }
  else if (a == 48)
  {
    //analogWrite(pwm3, 20);
    //analogWrite(pwm3, 28);
    err = 1;
    digitalWrite(dir4, LOW);
  }

  else if (a == 96)
  {
    //analogWrite(pwm3, 30);
    err = 2;
    digitalWrite(dir4, LOW);
  }
  else if (a == 192)
  {
    //analogWrite(pwm3, 40);
    err = 3;
    digitalWrite(dir4, LOW);
  }
  else if (a == 128)
  {
    //analogWrite(pwm3, 50);
    err = 4;
    digitalWrite(dir4, LOW);
  }

  else if (a == 12)
  {
    //analogWrite(pwm3, 20);
    err = 1;
    digitalWrite(dir4, HIGH);
  }

  else if (a == 6)
  {
    //analogWrite(pwm3, 30);
    err = 2;
    digitalWrite(dir4, HIGH);
  }

  else if (a == 3)
  {
    //analogWrite(pwm3, 40);
    err = 3;
    digitalWrite(dir4, HIGH);
  }

  else if (a == 1)
  {
    //analogWrite(pwm3, 50);
    err = 4;
    digitalWrite(dir4, HIGH);
  }

}

void rotate()
{

  laser_interrupt_1 = digitalRead(laser1);
  actuateState = digitalRead(actuate);
  digital_stop_2 = digitalRead(digital_2);
  if ((laser_interrupt_1 == 1) && (actuateState == 0))
  {
    //motor start in left side
    analogWrite(pwm8, 150);
    digitalWrite(dir, HIGH);
    while ((laser_interrupt_1 == 1) && (actuateState == 0)) {
      laser_interrupt_1 = digitalRead(laser1);
      actuateState = digitalRead(actuate);

    }

  }
  if ((laser_interrupt_1 == 0) && (actuateState == 1))
  {
    //still moving
    analogWrite(pwm8, 150);
    digitalWrite(dir, HIGH);
    while ((laser_interrupt_1 == 0) && (actuateState == 1)) {
      laser_interrupt_1 = digitalRead(laser1);
      actuateState = digitalRead(actuate);

    }
  }
  if ((laser_interrupt_1 == 0) && (actuateState == 0))
  {
    //stop
    analogWrite(pwm8, 0);
    digitalWrite(dir, HIGH);
    while ((laser_interrupt_1 == 0) && (actuateState == 0)) {
      laser_interrupt_1 = digitalRead(laser1);
      actuateState = digitalRead(actuate);

    }
  }


}

void loop()
{

  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
  analogWrite(pwm3, 0);
  analogWrite(pwm4, 0);

  //a = Serial1.read();
  Serial.println("baher gelay111111111111111111111111111111111111111111111111");
  //  b = Serial2.read();
  //c = Serial3.read();

  w = digitalRead(A0);
  x = digitalRead(A1);
  y = digitalRead(A2);
  z = digitalRead(A3);

  w1 = digitalRead(A4);
  x1 = digitalRead(A5);
  y1 = digitalRead(A6);
  z1 = digitalRead(A7);

  w2 = digitalRead(A8);
  x2 = digitalRead(A9);
  y2 = digitalRead(A10);
  z2 = digitalRead(A11);

  junctionCount = digitalRead(jPulse);
  junctionCount2 = digitalRead(jPulse2);
  digital_stop_1 = digitalRead(digital_1);
  digital_stop_2 = digitalRead(digital_2);
  laser_interrupt_1 = digitalRead(laser1);
  laser_interrupt_2 = digitalRead(laser2);
  laser_interrupt_3 = digitalRead(laser3);
  laser_interrupt_4 = digitalRead(laser4);

  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  actuateState = digitalRead(actuate);


  if (laser_interrupt_1 == 1)
  {
    laser = 1;
    flagcase1start = 1;
  }

  if (laser_interrupt_3 == 1)
  {
    laser = 2;
    flagcase2start = 1;
  }

  if (laser_interrupt_4 == 1)
  {

    laser = 3;
    flagcase3start = 1;
  }

  switch (laser)
  {


    case 0:
      analogWrite(pwm1, 0);
      analogWrite(pwm2, 0);
      analogWrite(pwm3, 0);
      analogWrite(pwm4, 0);

      if (laser_interrupt_1 == 1)
      {
        laser = 1;
        flagcase1start = 1;
      }

      if (laser_interrupt_3 == 1)
      {

        laser = 2;
        flagcase2start = 1;
      }

      if (laser_interrupt_4 == 1)
      {
        laser = 3;
        flagcase3start = 1;

      }


      break;


    case 1:    // your hand is close to the sensor
      while (flagcase1start == 1)
      {
        analogWrite(pwm1, 90);
        analogWrite(pwm2, 90);
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, LOW);
        w1 = digitalRead(A4);
        x1 = digitalRead(A5);
        y1 = digitalRead(A6);
        z1 = digitalRead(A7);
        line1();
        junctionCount = digitalRead(jPulse);
        if (junctionCount == 1)
        {
          flagcase1 = 1;
          while (falgcase1 == 1)
          {
            analogWrite(pwm1, 40);
            analogWrite(pwm2, 40);
            digitalWrite(dir1, LOW);
            digitalWrite(dir2, LOW);
            w1 = digitalRead(A4);
            x1 = digitalRead(A5);
            y1 = digitalRead(A6);
            z1 = digitalRead(A7);
            line1();
            digital_stop_1 = digitalRead(digital_1);




            while ((flagcase1 == 2) && (digital_stop_1 == 1))
            {
              w2 = digitalRead(A8);
              x2 = digitalRead(A9);
              y2 = digitalRead(A10);
              z2 = digitalRead(A11);
              line2();

              if ((w2 == 1) && (x2 == 0) && (y2 == 0) && (z2 == 0))
              {
                analogWrite(pwm2, 255);//38
                digitalWrite(dir2, HIGH);
              }

              if ((w2 == 1) && (x2 == 1) && (y2 == 0) && (z2 == 0))
              {
                analogWrite(pwm2, 40);//26
                digitalWrite(dir2, HIGH);
              }

              if ((w2 == 0) && (x2 == 1) && (y2 == 1) && (z2 == 0))
              {
                analogWrite(pwm2, 0);
                digitalWrite(dir2, LOW);
              }

              if ((w2 == 0) && (x2 == 0) && (y2 == 1) && (z2 == 1))
              {
                analogWrite(pwm2, 40);
                digitalWrite(dir2, LOW);
              }

              if ((w2 == 0) && (x2 == 0) && (y2 == 0) && (z2 == 1))
              {
                analogWrite(pwm2, 255 );
                digitalWrite(dir2, LOW);
              }


              analogWrite(pwm4, 160);//65  //150
              analogWrite(pwm3, 165);//70  //155
              analogWrite(pwm1, 0);
              line2();
              digitalWrite(dir3, LOW);
              digitalWrite(dir4, LOW);
              Serial.println(pwm2);
              junctionCount2 = digitalRead(jPulse2);
              digital_stop_2 = digitalRead(digital_2);
              //////////////////////////////
              junctionCount2 = digitalRead(jPulse2);
              if ((junctionCount2 == 1) && (m == 0))
              {
                n++;
                m = 1;
                //Serial.println(n);
                while (junctionCount2 == 1)
                {
                  junctionCount2 = digitalRead(jPulse2);
                  if (junctionCount2 == 0)
                  {
                    m = 0;
                  }
                }
              }
              //////////////////////////

              if (n == 2)
              {

                w2 = digitalRead(A8);
                x2 = digitalRead(A9);
                y2 = digitalRead(A10);
                z2 = digitalRead(A11);
                flag1 = 3;
                line2();
                while ((n == 2) && (flag1 == 3) )
                {

                  w2 = digitalRead(A8);
                  x2 = digitalRead(A9);
                  y2 = digitalRead(A10);
                  z2 = digitalRead(A11);
                  line2();
                  Serial.println("tz2_junction");

                  digital_stop_2 = digitalRead(digital_2);
                  analogWrite(pwm4, 40);
                  analogWrite(pwm3, 40);

                  digitalWrite(dir3, LOW);
                  digitalWrite(dir4, LOW);
                  laser_interrupt_2 = digitalRead(laser2);
                  flag1x == 2;

                  if (digital_stop_2 == 1) //&& (flag1x == 2))
                  {
                    //flag1x = 3;
                    flag1 = 4;
                    while (flag1 == 4)
                    {
                      flag1v = 1;

                      Serial.println("tz2_stop");
                      analogWrite(pwm1, 0);
                      analogWrite(pwm2, 0);
                      analogWrite(pwm3, 0);
                      analogWrite(pwm4, 0);
                      analogWrite(pwm8, 50);
                      //              digitalWrite(actuateState, HIGH);

                      Serial.println("XXXXXXXXXXXXXXX");

                      delay(2000);
                      digitalWrite(13, HIGH);
                      digitalWrite(12, LOW);
                      delay(1000);
                      digitalWrite(13, LOW);
                      digitalWrite(12, HIGH);

                      if (flag1v == 1)
                      {
                        flag1v = 2;
                        while (flag1v == 2)
                        {
                          laser_interrupt_2 = digitalRead(laser2);
                          flag1n = 2;

                          if ((laser_interrupt_2 == 1) && (flag1n == 2))
                          {
                            Serial.println("detect");
                            flag1 = 6;
                            flag1y = 2;
                            flag1x = 3;
                            flag1n = 3;
                            flag1v = 5;
                            m = 0;
                            n = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          ////////////////////////reverse

          if ( (laser_interrupt_2 == 1) && (flag1y == 2))
          {
            flag1y = 3;

            w = digitalRead(A0);
            x = digitalRead(A1);
            y = digitalRead(A2);
            z = digitalRead(A3);

            while  (flag1y == 3)
            {
              w = digitalRead(A0);
              x = digitalRead(A1);
              y = digitalRead(A2);
              z = digitalRead(A3);

              digitalWrite(dir3, HIGH);
              digitalWrite(dir4, HIGH);
              Serial.println("tz2_reverse");
              analogWrite(pwm3, 150);//74
              analogWrite(pwm4, 150);//70
              line();


              // junctionCount3 = digitalRead(jPulse3);
              digital_stop_3 = digitalRead(digital_3);

              //////////////////////////////
              junctionCount3 = digitalRead(jPulse3);
              if ((junctionCount3 == 1) && (t == 0))
              {
                u++;
                t = 1;
                Serial.println(u);
                while (junctionCount3 == 1)
                {
                  junctionCount3 = digitalRead(jPulse3);
                  if (junctionCount3 == 0)
                  {
                    t = 0;
                  }
                }
              }
              //////////////////////////
              if (u == 2)
              {
                w = digitalRead(A0);
                x = digitalRead(A1);
                y = digitalRead(A2);
                z = digitalRead(A3);

                flag1y = 4;
                line();
                while ((u == 2) && (flag1y == 4) )
                {
                  w = digitalRead(A0);
                  x = digitalRead(A1);
                  y = digitalRead(A2);
                  z = digitalRead(A3);

                  line();
                  Serial.println("tz2_reverse_junction");
                  //c = Serial3.read();
                  digital_stop_2 = digitalRead(digital_2);
                  digitalWrite(dir3, HIGH);
                  digitalWrite(dir4, HIGH);
                  flag1s = 4;
                  analogWrite(pwm4, 40);
                  analogWrite(pwm3, 43);
                  // u = 0;
                  if ((digital_stop_2 == 1) && (flag1s == 4))
                  {
                    flag1s = 5;
                    while (flag1s == 5)
                    {
                      // flag1x = 2;
                      //flag1y = 5;
                      analogWrite(pwm1, 0);
                      analogWrite(pwm2, 0);
                      analogWrite(pwm3, 0);
                      analogWrite(pwm4, 0);
                      Serial.println("tz2_reverse_Stop");
                      //Serial.println(pwm3);
                      laser_interrupt_1 = digitalRead(laser1);
                      laser_interrupt_2 = digitalRead(laser2);
                      laser_interrupt_3 = digitalRead(laser3);

                      flag5n = 2;

                      flag1 = 0;
                      flag1y = 0;
                      flag1x = 0;
                      flag1n = 0;
                      flag5n = 0;
                      flag1s = 0;
                      Serial.println("de555tect");
                      flagtz = 0;
                      m = 0;
                      t = 0;
                      u = 0;
                      n = 0;
                      laser = 0;
                      flagcase1 = 0;
                      flagcase1start = 0;

                    }
                  }
                }
              }
            }
          }
        }
      }
      break;
    case 2:


      while (flagcase2 == 1)
      {
        Serial.println("tz1");

        // Serial.println("zalaekdach");
        analogWrite(pwm1, 70);
        analogWrite(pwm2, 70);
        a = Serial1.read();
        //a = Serial1.read();
        Serial.print("a == ");
        Serial.println(a);
        Serial1.begin(115200);
        flagtz = 1;
        digitalWrite(dir1, HIGH);
        digitalWrite(dir2, HIGH);

        //      w1 = digitalRead(A4);
        //      x1 = digitalRead(A5);
        //      y1 = digitalRead(A6);
        //      z1 = digitalRead(A7);

        digital_stop_1 = digitalRead(digital_1);
        digital_stop_2 = digitalRead(digital_2);
        junctionCount4 = digitalRead(jPulse4);
        laser_interrupt_2 = digitalRead(laser2);
        line_follow();
        //line1();

        //b = Serial2.read();

        if ((junctionCount4 == 1) && (flagtz = 1))
        {
          flag5 = 1;
          line_follow();
          //line1();
          while (flag5 == 1)
          {
            a = Serial1.read();
            //          w1 = digitalRead(A4);
            //          x1 = digitalRead(A5);
            //          y1 = digitalRead(A6);
            //          z1 = digitalRead(A7);
            //          line_follow();
            //line1();
            line_follow();
            Serial.println("tz1_junction");
            digital_stop_1 = digitalRead(digital_1);
            analogWrite(pwm1, 40);
            analogWrite(pwm2, 40);

            flag = 1;
            digitalWrite(dir1, HIGH);
            digitalWrite(dir2, HIGH);
            //////////////////////////////////////////////----------------------
            //          digital_stop_1 = digitalRead(digital_1);
            //
            //          if ((digital_stop_1 == 1) && (ms == 0))
            //          {
            //            ns++;
            //            ms = 1;
            //            Serial.println(ns);
            //            while (digital_stop_1 == 1)
            //            {
            //              digital_stop_1 = digitalRead(digital_1);
            //              if (digital_stop_1 == 0)
            //              {
            //                ms = 0;
            //              }
            //            }
            //          }
            //          //////////////////////////

            if ((digital_stop_1 == 1) && (flag == 1))
            {
              flag = 2;


              while (flag == 2)

              {
                Serial.println("tz1_enter");


                /////////////
                w2 = digitalRead(A8);
                x2 = digitalRead(A9);
                y2 = digitalRead(A10);
                z2 = digitalRead(A11);
                //  line2();

                if ((w2 == 1) && (x2 == 0) && (y2 == 0) && (z2 == 0))
                {
                  analogWrite(pwm2, 255);//38
                  digitalWrite(dir2, HIGH);
                }

                if ((w2 == 1) && (x2 == 1) && (y2 == 0) && (z2 == 0))
                {
                  analogWrite(pwm2, 40);//26
                  digitalWrite(dir2, HIGH);
                }

                if ((w2 == 0) && (x2 == 1) && (y2 == 1) && (z2 == 0))
                {
                  analogWrite(pwm2, 0);
                  digitalWrite(dir2, LOW);
                }

                if ((w2 == 0) && (x2 == 0) && (y2 == 1) && (z2 == 1))
                {
                  analogWrite(pwm2, 40);
                  digitalWrite(dir2, LOW);
                }

                if ((w2 == 0) && (x2 == 0) && (y2 == 0) && (z2 == 1))
                {
                  analogWrite(pwm2, 255 );
                  digitalWrite(dir2, LOW);
                }

                //    b = Serial2.read();
                //   Serial.print("b == ");
                //    Serial.println(b);
                analogWrite(pwm4, 110);//65  //150
                analogWrite(pwm3, 115);//70  //155
                // line2();
                analogWrite(pwm1, 0);
                digitalWrite(dir3, LOW);
                digitalWrite(dir4, LOW);
                Serial.println(pwm2);

                junctionCount2 = digitalRead(jPulse2);
                if ((junctionCount2 == 1) && (m3 == 0))
                {
                  n3++;
                  m3 = 1;
                  Serial.println("chutya222");
                  Serial.println(n3);
                  while (junctionCount2 == 1)
                  {
                    junctionCount2 = digitalRead(jPulse2);
                    if (junctionCount2 == 0)
                    {
                      m3 = 0;
                    }
                  }
                }
                /////////////////////////

                if (n3 == 2)
                {
                  Serial.println("tz1_enter_junction");
                  analogWrite(pwm3, 20);
                  analogWrite(pwm4, 20);
                  digitalWrite(dir3, LOW);
                  digitalWrite(dir4, LOW);

                  digital_stop_2 = digitalRead(digital_2);
                  flagtz1x = 2;
                  line2();

                }
                if ((digital_stop_2 == 1) && (flagtz1x == 2))
                {
                  flagtz1x = 3;
                  flagtz1 = 4;
                  analogWrite(pwm1, 0);
                  analogWrite(pwm2, 0);
                  analogWrite(pwm3, 0);
                  analogWrite(pwm4, 0);
                  laser_interrupt_2 = digitalRead(laser2);

                  while (flagtz1x == 3)
                  {
                    flagtz1y = 2;
                    Serial.println("tz1_enter_stop");
                    analogWrite(pwm1, 0);
                    analogWrite(pwm2, 0);
                    analogWrite(pwm3, 0);
                    analogWrite(pwm4, 0);

                    delay(2000);
                    digitalWrite(13, HIGH);
                    digitalWrite(12, LOW);
                    delay(1000);
                    digitalWrite(13, LOW);
                    digitalWrite(12, HIGH);

                    if (flagtz1y == 2)
                    {

                      flagtz1y = 3;
                      while (flagtz1y == 3)
                      {

                        laser_interrupt_2 = digitalRead(laser2);
                        Serial.println("Detect mar re bhava");


                        if ((laser_interrupt_2 == 1) && (flagtz1y == 3))
                        {
                          w = digitalRead(A0);
                          x = digitalRead(A1);
                          y = digitalRead(A2);
                          z = digitalRead(A3);
                          line();
                          flagtz1y = 3;
                          laser_interrupt_2 = digitalRead(laser2);
                          while (flagtz1y == 3)
                          {
                            w = digitalRead(A0);
                            x = digitalRead(A1);
                            y = digitalRead(A2);
                            z = digitalRead(A3);

                            Serial.println("tz1_enter_reverse");
                            //  flagtz1y = 2;

                            digitalWrite(dir3, HIGH);
                            digitalWrite(dir4, HIGH);
                            analogWrite(pwm3, 110);
                            analogWrite(pwm4, 110);

                            line();
                            junctionCount3 = digitalRead(jPulse3);
                            digital_stop_2 = digitalRead(digital_2);

                            //////////////////////////////
                            junctionCount3 = digitalRead(jPulse3);
                            if ((junctionCount3 == 1) && (mx == 0))
                            {
                              nx++;
                              mx = 1;
                              Serial.println(nx);
                              while (junctionCount3 == 1)
                              {
                                junctionCount3 = digitalRead(jPulse3);
                                if (junctionCount3 == 0)
                                {
                                  mx = 0;
                                }
                              }
                            }
                            //////////////////////////

                            if (nx == 2)
                            {
                              w = digitalRead(A0);
                              x = digitalRead(A1);
                              y = digitalRead(A2);
                              z = digitalRead(A3);

                              flagtz1y = 4;
                              line();
                              while ((nx == 2) && (flagtz1y == 4) )
                              {
                                w = digitalRead(A0);
                                x = digitalRead(A1);
                                y = digitalRead(A2);
                                z = digitalRead(A3);

                                //c = Serial3.read();
                                line();
                                digital_stop_2 = digitalRead(digital_2);
                                digitalWrite(dir3, HIGH);
                                digitalWrite(dir4, HIGH);
                                Serial.println("tz1_enter_junction");
                                analogWrite(pwm4, 50);
                                analogWrite(pwm3, 50);



                                //////////////////////////////



                                if (digital_stop_2 == 1)
                                {
                                  flagsh = 1;

                                  while (flagsh == 1)
                                  {
                                    w1 = digitalRead(A4);
                                    x1 = digitalRead(A5);
                                    y1 = digitalRead(A6);
                                    z1 = digitalRead(A7);
                                    flagtz1y = 5;

                                    //flagtz1y = 5;
                                    // line();
                                    line1();
                                    //line_follow();
                                    digital_stop_1 = digitalRead(digital_1);
                                    digital_stop_2 = digitalRead(digital_2);
                                    digitalWrite(dir1, LOW);
                                    digitalWrite(dir2, LOW);
                                    Serial.println("tz1_reverse");

                                    analogWrite(pwm1, 70);
                                    analogWrite(pwm2, 70);
                                    analogWrite(pwm4, 0);

                                    junctionCount = digitalRead(jPulse);
                                    if ((junctionCount == 1) && (flagtz1y == 5))
                                    {
                                      flagtz1y = 6;
                                      while (flagtz1y == 6)
                                      {
                                        digitalWrite(dir1, LOW);
                                        digitalWrite(dir2, LOW);
                                        Serial.println("tz1_JUNCTION5");
                                        w1 = digitalRead(A4);
                                        x1 = digitalRead(A5);
                                        y1 = digitalRead(A6);
                                        z1 = digitalRead(A7);
                                        line1();
                                        flagtz1y = 6;
                                        analogWrite(pwm1, 30);
                                        analogWrite(pwm2, 30);
                                        analogWrite(pwm4, 0);


                                        digital_stop_1 = digitalRead(digital_1);
                                        /*
                                          if ((digital_stop_1 == 1) && (m4 == 0))
                                          {
                                          n4++;
                                          m4 = 1;
                                          Serial.println(n4);
                                          while (digital_stop_1 == 1)
                                          {
                                            digital_stop_1 = digitalRead(digital_1);
                                            if (digital_stop_1 == 0)
                                            {
                                              m4 = 0;
                                            }
                                          }
                                          }
                                          8*/
                                        //////////////////////////

                                        if ((digital_stop_1 == 1) && (flagtz1y == 6))
                                        {
                                          flagtz1y = 7;
                                          while (flagtz1y == 7)
                                          {

                                            flagtzstop = 1;
                                            Serial.println("tz1_stop");
                                            analogWrite(pwm1, 0);
                                            analogWrite(pwm2, 0);
                                            analogWrite(pwm3, 0);
                                            analogWrite(pwm4, 0);

                                            laser_interrupt_1 = digitalRead(laser1);
                                            laser_interrupt_2 = digitalRead(laser2);
                                            laser_interrupt_3 = digitalRead(laser3);
                                            //nx = 3;




                                            Serial.println("shubhambhaiiiii");


                                            flag5 = 0;
                                            flag1x = 0;
                                            flagtz1y = 0;
                                            flagtz1x = 0;
                                            flag = 0;
                                            flag1y = 0;
                                            flag1z = 0;
                                            flagsh = 0;
                                            flag1n = 0;
                                            flagtz = 0;
                                            flag1s = 0;
                                            flagstart = 0;
                                            flagstart2 = 0;
                                            flagtzstop = 0;
                                            mx = 0;
                                            nx = 0;
                                            m3 = 0;
                                            n3 = 0;
                                            m4 = 0;
                                            n4 = 0;
                                            ns = 0;
                                            ms = 0;
                                            digital_stop_2 = digitalRead(digital_2);
                                            case3_test_case = 1;
                                            case_three_execution_status = TRUE;
                                            laser = 0;
                                            flagcase2 = 0;
                                          }

                                        }
                                      }
                                      if (TRUE == case_three_execution_status)
                                      {
                                        Serial.println("exit1");
                                      }
                                    }
                                    if (TRUE == case_three_execution_status)
                                    {
                                      Serial.println("exit2");
                                    }
                                  }
                                  if (TRUE == case_three_execution_status)
                                  {
                                    Serial.println("exit3");
                                  }
                                }
                                if (TRUE == case_three_execution_status)
                                {
                                  Serial.println("exit4");
                                }
                              }
                              if (TRUE == case_three_execution_status)
                              {
                                Serial.println("exit5");
                              }
                            }
                            if (TRUE == case_three_execution_status)
                            {
                              Serial.println("exit6");
                            }
                          }
                          if (TRUE == case_three_execution_status)
                          {
                            Serial.println("exit7");
                          }
                        }
                        if (TRUE == case_three_execution_status)
                        {
                          Serial.println("exit8");
                        }
                      }
                      if (TRUE == case_three_execution_status)
                      {
                        Serial.println("exit9");
                      }
                    }
                    if (TRUE == case_three_execution_status)
                    {
                      Serial.println("exit10");
                    }
                  }
                  if (TRUE == case_three_execution_status)
                  {
                    Serial.println("exit11");
                  }
                }
                if (TRUE == case_three_execution_status)
                {
                  Serial.println("exit12");
                }
              }
              if (TRUE == case_three_execution_status)
              {
                Serial.println("exit13");
              }
            }
            if (TRUE == case_three_execution_status)
            {
              Serial.println("exit14");
            }
          }
        }
      }

      if (TRUE == case_three_execution_status)
      {

        Serial.println("Case 2 Execution Done!!!!");
      }
      break;
    case 3:    // your hand is nowhere near the sensor


      Serial.println("tz3");
      while (flagcase3 == 1)
      {


        w2 = digitalRead(A8);
        x2 = digitalRead(A9);
        y2 = digitalRead(A10);
        z2 = digitalRead(A11);
        line2();

        if ((w2 == 1) && (x2 == 0) && (y2 == 0) && (z2 == 0))
        {
          analogWrite(pwm2, 255);//38
          digitalWrite(dir2, HIGH);
        }

        if ((w2 == 1) && (x2 == 1) && (y2 == 0) && (z2 == 0))
        {
          analogWrite(pwm2, 40);//26
          digitalWrite(dir2, HIGH);
        }

        if ((w2 == 0) && (x2 == 1) && (y2 == 1) && (z2 == 0))
        {
          analogWrite(pwm2, 0);
          digitalWrite(dir2, LOW);
        }

        if ((w2 == 0) && (x2 == 0) && (y2 == 1) && (z2 == 1))
        {
          analogWrite(pwm2, 40);
          digitalWrite(dir2, LOW);
        }

        if ((w2 == 0) && (x2 == 0) && (y2 == 0) && (z2 == 1))
        {
          analogWrite(pwm2, 255 );
          digitalWrite(dir2, LOW);
        }


        analogWrite(pwm4, 160);//65  //150
        analogWrite(pwm3, 165);//70  //155
        line2();
        digitalWrite(dir3, LOW);
        digitalWrite(dir4, LOW);
        Serial.println(pwm2);



        junctionCount2 = digitalRead(jPulse2);
        digital_stop_2 = digitalRead(digital_2);

        //////////////////////////////
        junctionCount2 = digitalRead(jPulse2);
        if ((junctionCount2 == 1) && (m == 0))
        {
          n++;
          m = 1;
          //Serial.println(n);
          while (junctionCount2 == 1)
          {
            junctionCount2 = digitalRead(jPulse2);
            if (junctionCount2 == 0)
            {
              m = 0;
            }
          }
        }
        //////////////////////////

        if (n == 4)
        {

          w2 = digitalRead(A8);
          x2 = digitalRead(A9);
          y2 = digitalRead(A10);
          z2 = digitalRead(A11);
          flag1 = 3;
          line2();
          while ((n == 4) && (flag1 == 3) )
          {

            w2 = digitalRead(A8);
            x2 = digitalRead(A9);
            y2 = digitalRead(A10);
            z2 = digitalRead(A11);
            line2();
            Serial.println("tz3_junction");

            digital_stop_2 = digitalRead(digital_2);
            analogWrite(pwm4, 40);//40
            analogWrite(pwm3, 40);//40

            digitalWrite(dir3, LOW);
            digitalWrite(dir4, LOW);
            laser_interrupt_2 = digitalRead(laser2);
            flag1x == 2;

            digital_stop_2 = digitalRead(digital_2);
            ////*/*/*/*

            if ((digital_stop_2 == 1) && (mq == 0))
            {
              nq++;
              mq = 1;
              //Serial.println(n);
              while (digital_stop_2  == 1)
              {
                digital_stop_2 = digitalRead(digital_2);
                if (digital_stop_2 == 0)
                {
                  mq = 0;
                }
              }
            }
            //////////////////////////

            ////////////*/*/*

            if (nq == 2) //&& (flag1x == 2))
            {
              //flag1x = 3;
              flag1 = 4;
              while (flag1 == 4)
              {
                flag1v = 1;

                Serial.println("tz3_stop");
                analogWrite(pwm1, 0);
                analogWrite(pwm2, 0);
                analogWrite(pwm3, 0);
                analogWrite(pwm4, 0);
                analogWrite(pwm8, 50);
                //              digitalWrite(actuateState, HIGH);

                Serial.println("XXXXXXXXXXXXXXX");

                delay(2000);
                digitalWrite(13, HIGH);
                digitalWrite(12, LOW);
                delay(1000);
                digitalWrite(13, LOW);
                digitalWrite(12, HIGH);

                if (flag1v == 1)
                {
                  flag1v = 2;
                  while (flag1v == 2)
                  {
                    laser_interrupt_2 = digitalRead(laser2);
                    flag1n = 2;

                    if ((laser_interrupt_2 == 1) && (flag1n == 2))
                    {
                      Serial.println("detect");
                      flag1 = 6;
                      flag1y = 2;
                      flag1x = 3;
                      flag1n = 3;
                      flag1v = 5;
                      m = 0;
                      n = 0;
                    }
                  }
                }
              }
            }
          }
        }

        ////////////////////////reverse

        if ( (laser_interrupt_2 == 1) && (flag1y == 2))
        {
          flag1y = 3;

          w = digitalRead(A0);
          x = digitalRead(A1);
          y = digitalRead(A2);
          z = digitalRead(A3);

          while  (flag1y == 3)
          {
            w = digitalRead(A0);
            x = digitalRead(A1);
            y = digitalRead(A2);
            z = digitalRead(A3);

            digitalWrite(dir3, HIGH);
            digitalWrite(dir4, HIGH);
            Serial.println("tz3_reverse");
            analogWrite(pwm3, 150);//74
            analogWrite(pwm4, 150);//70
            line();


            // junctionCount3 = digitalRead(jPulse3);
            digital_stop_3 = digitalRead(digital_3);

            //////////////////////////////
            junctionCount3 = digitalRead(jPulse3);
            if ((junctionCount3 == 1) && (t == 0))
            {
              u++;
              t = 1;
              Serial.println(u);
              while (junctionCount3 == 1)
              {
                junctionCount3 = digitalRead(jPulse3);
                if (junctionCount3 == 0)
                {
                  t = 0;
                }
              }
            }
            //////////////////////////
            if (u == 4)
            {
              w = digitalRead(A0);
              x = digitalRead(A1);
              y = digitalRead(A2);
              z = digitalRead(A3);

              flag1y = 4;
              line();
              while ((u == 4) && (flag1y == 4) )
              {
                w = digitalRead(A0);
                x = digitalRead(A1);
                y = digitalRead(A2);
                z = digitalRead(A3);

                line();
                Serial.println("tz3_reverse_junction");
                //c = Serial3.read();
                digital_stop_2 = digitalRead(digital_2);
                digitalWrite(dir3, HIGH);
                digitalWrite(dir4, HIGH);
                flag1s = 4;
                analogWrite(pwm4, 40);
                analogWrite(pwm3, 43);
                // u = 0;


                //////*/*

                digital_stop_2 = digitalRead(digital_2);
                ////*/*/*/*

                if ((digital_stop_2 == 1) && (mw == 0))
                {
                  nw++;
                  mw = 1;
                  //Serial.println(n);
                  while (digital_stop_2  == 1)
                  {
                    digital_stop_2 = digitalRead(digital_2);
                    if (digital_stop_2 == 0)
                    {
                      mw = 0;
                    }
                  }
                }
                //////////*/*
                if ((nw == 2) && (flag1s == 4))
                {
                  flag1s = 5;
                  while (flag1s == 5)
                  {
                    // flag1x = 2;
                    //flag1y = 5;
                    analogWrite(pwm1, 0);
                    analogWrite(pwm2, 0);
                    analogWrite(pwm3, 0);
                    analogWrite(pwm4, 0);
                    Serial.println("tz3_reverse_Stop");
                    //Serial.println(pwm3);
                    laser_interrupt_1 = digitalRead(laser1);
                    laser_interrupt_2 = digitalRead(laser2);
                    laser_interrupt_3 = digitalRead(laser3);

                    flag5n = 2;

                    flag1 = 0;
                    flag1y = 0;
                    flag1x = 0;
                    flag1n = 0;
                    flag5n = 0;
                    flag1s = 0;
                    Serial.println("de555tect");
                    flagtz = 0;
                    m = 0;
                    t = 0;
                    u = 0;
                    n = 0;
                    mq = 0;
                    nq = 0;
                    mw = 0;
                    nq = 0;
                    laser = 0;
                    flagcase3 = 0;

                  }
                }
              }
            }
          }
        }
      }

      break;
  }
  // delay(1);        // delay in between reads for stability
}





