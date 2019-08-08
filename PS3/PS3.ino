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



const int m1 = 5;
const int dir1 = 7;

const int m2 = 6;
const int dir2 = 8;

const int m3 = 10;
const int dir3 = 13;

const int m4 = 11;
const int dir4 = 12;

void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(dir1, OUTPUT);

  pinMode(m2, OUTPUT);
  pinMode(dir2, OUTPUT);

  pinMode(m3, OUTPUT);
  pinMode(dir3, OUTPUT);

  pinMode(m4, OUTPUT);
  pinMode(dir4, OUTPUT);

  // Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    // Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  //Serial.print(F("\r\nPS3 USB Library Started"));
}
void loop() {
  Usb.Task();
  int a=0, b=0, c=0, d=0, e=0, f=0;

  a = PS3.getAnalogButton(UP);
  b = PS3.getAnalogButton(RIGHT);
  c = PS3.getAnalogButton(DOWN);
  d = PS3.getAnalogButton(LEFT);
  e = PS3.getAnalogButton(TRIANGLE);
  f = PS3.getAnalogButton(CROSS);


  if (a > 0)
  {
    analogWrite(m1, 100);
    analogWrite(m2, 100);
    analogWrite(m3, 0);
    analogWrite(m4, 0);

    digitalWrite(dir1, 1);
    digitalWrite(dir2, 1);
  }

  else if (b > 0)
  {
    analogWrite(m1, 100);
    analogWrite(m2, 100);
    analogWrite(m3, 100);
    analogWrite(m4, 100);

    digitalWrite(dir1, 1);
    digitalWrite(dir2, 0);
    digitalWrite(dir3, 1);
    digitalWrite(dir4, 0);
  }

  else if (c > 0)
  {
    analogWrite(m1, 100);
    analogWrite(m2, 100);
    analogWrite(m3, 0);
    analogWrite(m4, 0);

    digitalWrite(dir1, 0);
    digitalWrite(dir2, 0);
  }

  else if (d > 0)
  {
    analogWrite(m1, 100);
    analogWrite(m2, 100);
    analogWrite(m3, 100);
    analogWrite(m4, 100);

    digitalWrite(dir1, 0);
    digitalWrite(dir2, 1);
    digitalWrite(dir3, 0);
    digitalWrite(dir4, 1);
  }
  else  if (e > 0)
  {
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, 100);
    analogWrite(m4, 100);

    digitalWrite(dir3, 1);
    digitalWrite(dir4, 1);
  }
  else if (f > 0)
  {
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, 100);
    analogWrite(m4, 100);

    digitalWrite(dir3, 0);
    digitalWrite(dir4, 0);
  }

  else
  {
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 0);
  }
}


