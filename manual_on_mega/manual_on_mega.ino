/*
  Example sketch for the PS3 USB library - developed by Kristian Lauszus
  For more information visit my blog: http://blog.tkjelectronics.dk/ or
  send me an e-mail:  kristianl@tkjelectronics.com
*/

#include <PS3USB.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
/* You can create the instance of the class in two ways */
PS3USB PS3(&Usb); // This will just create the instance
//PS3USB PS3(&Usb,0x00,0x15,0x83,0x3D,0x0A,0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

bool printAngle;
uint8_t state = 0;

void setup() {

  // pinMode(2, OUTPUT);   //m1
  //pinMode(40, OUTPUT);

  // pinMode(3, OUTPUT);   //m2
  // pinMode(41, OUTPUT);

  // pinMode(4, OUTPUT);   //m3
  //pinMode(42, OUTPUT);

  // pinMode(5, OUTPUT);   //m4
  // pinMode(43, OUTPUT);

  pinMode(6, OUTPUT);   //wheel
  pinMode(44, OUTPUT);



  //Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    //Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  // Serial.print(F("\r\nPS3 USB Library Started"));
}
//int a, b, c, d, e, f, i, j, k, l, m, n;
void loop() {
  Usb.Task();


  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {

    /* if (PS3.getAnalogHat(RightHatX) < 117)
      {
       e = PS3.getAnalogHat(RightHatX);
       m = map(e, 117, 0, 0, 50);
       analogWrite(5, m);
       analogWrite(6, m);
       analogWrite(3, m);
       analogWrite(9, m);

       digitalWrite(7, LOW);
       digitalWrite(8, HIGH);
       digitalWrite(0, LOW);
       digitalWrite(1, HIGH);
      }
      if ( PS3.getAnalogHat(RightHatX) > 137)
      {
       f = PS3.getAnalogHat(RightHatX);
       n = map(f, 137, 255, 0, 50);
       analogWrite(5, n);
       analogWrite(6, n);
       analogWrite(3, n);
       analogWrite(9, n);

       digitalWrite(7, HIGH);
       digitalWrite(8, LOW);
       digitalWrite(0, HIGH);
       digitalWrite(1, LOW);
      }
      if (PS3.getAnalogHat(RightHatY) < 117)
      {
       i = PS3.getAnalogHat(RightHatY);
       a = map(i, 117, 0, 0, 200);
       analogWrite(5, a);
       analogWrite(6, a);
       analogWrite(3, 0);
       analogWrite(9, 0);

       digitalWrite(7, LOW);
       digitalWrite(8, LOW);
       digitalWrite(0, LOW);
       digitalWrite(1, LOW);
       //Serial.println(a);
      }
      if ( PS3.getAnalogHat(RightHatY) > 137)
      {
       j = PS3.getAnalogHat(RightHatY);
       b = map(j, 137, 255, 0, 200);
       analogWrite(5, b);
       analogWrite(6, b);
       analogWrite(3, 0);
       analogWrite(9, 0);

       digitalWrite(7, HIGH);
       digitalWrite(8, HIGH);
       digitalWrite(0, HIGH);
       digitalWrite(1, HIGH);
       //Serial.println(b);
      }*/
    /* if (PS3.getAnalogHat(LeftHatY) < 117)
      {
       k = PS3.getAnalogHat(LeftHatY);
       c = map(k, 117, 0, 0, 200);
       analogWrite(2, 0);
       analogWrite(3, 0);
       analogWrite(4, c);
       analogWrite(5, c);
       analogWrite(6, 0);

       digitalWrite(40, HIGH);
       digitalWrite(41, HIGH);
       digitalWrite(42, HIGH);
       digitalWrite(43, HIGH);
       digitalWrite(44, LOW);
       //Serial.println(c);
      }
      else  if ( PS3.getAnalogHat(LeftHatY) > 137)
      {
       l = PS3.getAnalogHat(LeftHatY);
       d = map(l, 137, 255, 0, 200);
       analogWrite(2, 0);
       analogWrite(3, 0);
       analogWrite(4, d);
       analogWrite(5, d);
       digitalWrite(6, LOW);

       digitalWrite(40, LOW);
       digitalWrite(41, LOW);
       digitalWrite(42, LOW);
       digitalWrite(43, LOW);
       digitalWrite(44, LOW);
       //Serial.println(d);
      }
      else if (PS3.getAnalogButton(L2) > 5)
      {
       analogWrite(2, PS3.getAnalogButton(L2));
       analogWrite(3, PS3.getAnalogButton(L2));
       analogWrite(4, 0);
       analogWrite(5, 0);
       digitalWrite(6, LOW);

       digitalWrite(40, LOW);
       digitalWrite(41, LOW);
       digitalWrite(42, LOW);
       digitalWrite(43, LOW);
      }
      else if (PS3.getAnalogButton(R2) > 5)
      {
       analogWrite(2, PS3.getAnalogButton(R2));
       analogWrite(3, PS3.getAnalogButton(R2));
       analogWrite(4, 0);
       analogWrite(5, 0);
       digitalWrite(6, LOW);

       digitalWrite(40, HIGH);
       digitalWrite(41, HIGH);
       digitalWrite(42, HIGH);
       digitalWrite(43, HIGH);
      }
      else if (PS3.getAnalogButton(R1) > 5)
      {
       analogWrite(2, PS3.getAnalogButton(R1));
       analogWrite(3, PS3.getAnalogButton(R1));
       analogWrite(4, 0);
       analogWrite(5, 0);
       digitalWrite(6, LOW);

       digitalWrite(40, HIGH);
       digitalWrite(41, LOW);
       digitalWrite(42, HIGH);
       digitalWrite(43, HIGH);
      }
      else if (PS3.getAnalogButton(L1) > 5)
      {
       analogWrite(2, PS3.getAnalogButton(L1));
       analogWrite(3, PS3.getAnalogButton(L1));
       analogWrite(4, 0);
       analogWrite(5, 0);
       digitalWrite(6, LOW);

       digitalWrite(40, LOW);
       digitalWrite(41, HIGH);
       digitalWrite(42, HIGH);
       digitalWrite(43, HIGH);
      }
      else if (PS3.getAnalogButton(RIGHT) >= 1)
      {
       analogWrite(2, 0);
       analogWrite(3, 0);
       analogWrite(4, 0);
       analogWrite(5, 0);
       analogWrite(6, PS3.getAnalogButton(RIGHT));

       digitalWrite(40, LOW);
       digitalWrite(41, HIGH);
       digitalWrite(42, HIGH);
       digitalWrite(43, HIGH);
       digitalWrite(44, HIGH);
      }
      else if (PS3.getAnalogButton(LEFT) >= 1)
      {
       analogWrite(2, 0);
       analogWrite(3, 0);
       analogWrite(4, 0);
       analogWrite(5, 0);
       analogWrite(6, PS3.getAnalogButton(LEFT));

       digitalWrite(40, LOW);
       digitalWrite(41, HIGH);
       digitalWrite(42, HIGH);
       digitalWrite(43, HIGH);
       digitalWrite(44, LOW);
      }
      else
      {
       analogWrite(2, 0);
       analogWrite(3, 0);
       analogWrite(4, 0);
       analogWrite(5, 0);
       digitalWrite(6, LOW);


       digitalWrite(40, 0);
       digitalWrite(41, 0);
       digitalWrite(42, 0);
       digitalWrite(43, 0);
       digitalWrite(44, 0);
      }
    */
    if (PS3.getButtonClick(TRIANGLE))
    {
      analogWrite(6, 40);
      digitalWrite(44, HIGH);
    }
    if (PS3.getButtonClick(CROSS))
    {
      analogWrite(6, 40);
      digitalWrite(44, HIGH);
    }
    else
    {
      analogWrite(6, 0);
    }
  }
}
