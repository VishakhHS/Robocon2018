

#include <XBOXRECV.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXRECV Xbox(&Usb);

void setup() {

  pinMode(2, OUTPUT);   //m1
  pinMode(8, OUTPUT);

  pinMode(3, OUTPUT);   //m2
  pinMode(9, OUTPUT);

  pinMode(4, OUTPUT);   //m3
  pinMode(10, OUTPUT);

  pinMode(5, OUTPUT);   //m4
  pinMode(1, OUTPUT);

  pinMode(6, OUTPUT);   //wheel
  pinMode(12, OUTPUT);

  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXbox Wireless Receiver Library Started"));
}
int a, b, c, d, e, f, j, k, l, m, g, h;
//uint8_t i = 0;


void loop() {
  Usb.Task();
  if (Xbox.XboxReceiverConnected) {
    //  for (uint8_t i = 0; i < 4; i++) {
    if (Xbox.Xbox360Connected) {

      //Backward
      if (Xbox.getButtonPress(L2) > 5)
      {
        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(4, Xbox.getButtonPress(L2));
        analogWrite(5, Xbox.getButtonPress(L2));
        analogWrite(6, 0);

        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(1, LOW);
        digitalWrite(12, HIGH);
      }

      //Forward
      else if (Xbox.getButtonPress(R2) > 5)
      {
        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(4, Xbox.getButtonPress(R2));
        analogWrite(5, Xbox.getButtonPress(R2));
        analogWrite(6, 0);

        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(12, HIGH);
      }

      //Left
      else if (Xbox.getButtonPress(X))
      {
        analogWrite(2, 40);
        analogWrite(3, 40);
        analogWrite(4, 40);
        analogWrite(5, 40);
        analogWrite(6, 0);

        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(1, LOW);
        digitalWrite(12, LOW);

      }

      //Right
      else if (Xbox.getButtonPress(B))
      {
        analogWrite(2, 40);
        analogWrite(3, 40);
        analogWrite(4, 40);
        analogWrite(5, 40);
        analogWrite(6, 0);

        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(1, HIGH);
        digitalWrite(12, LOW);
      }

      //WheelR
      else if (Xbox.getButtonPress(Y))
      {
        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(4, 0);
        analogWrite(5, 0);
        analogWrite(6, 100);

        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(12, HIGH);

      }

      //WheelL
      else if (Xbox.getButtonPress(A))
      {
        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(4, 0);
        analogWrite(5, 0);
        analogWrite(6, 100);

        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(1, LOW);
        digitalWrite(12, LOW);
      }
      //32767

      //PodForward
      else if (Xbox.getAnalogHat(RightHatY) > 7599)
      {
        a = Xbox.getAnalogHat(RightHatY);
        b = map(a, 7600, 32767, 0, 100);

        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(4, b);
        analogWrite(5, b);
        analogWrite(6, 0);

        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(12, HIGH);
      }

      //PodBackward
      else if (Xbox.getAnalogHat(RightHatY) < -7599)
      {
        c = Xbox.getAnalogHat(RightHatY);
        d = map(c, -7600, -32768, 0, 100);

        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(4, d);
        analogWrite(5, d);
        analogWrite(6, 0);

        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(1, LOW);
        digitalWrite(12, LOW);
      }

      //PodRight
      else if (Xbox.getAnalogHat(RightHatX) > 7599)
      {
        e = Xbox.getAnalogHat(RightHatX);
        f = map(e, 7600, 32767, 0, 100);

        analogWrite(2, f);
        analogWrite(3, f);
        analogWrite(4, f);
        analogWrite(5, f);
        analogWrite(6, 0);

        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(1, HIGH);
        digitalWrite(12, HIGH);
      }

      //PodLeft
      else if (Xbox.getAnalogHat(RightHatX) < -7599)
      {
        g = Xbox.getAnalogHat(RightHatX);
        h = map(g, -7600, -32768, 0, 100);

        analogWrite(2, h);
        analogWrite(3, h);
        analogWrite(4, h);
        analogWrite(5, h);
        analogWrite(6, 0);

        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(1, LOW);
        digitalWrite(12, LOW);
      }

      //LPodForward
      else if (Xbox.getAnalogHat(LeftHatX) > 7599)
      {
        j = Xbox.getAnalogHat(LeftHatX);
        k = map(j, 7600, 32767, 0, 100);

        analogWrite(2, k);
        analogWrite(3, k);
        analogWrite(4, 0);
        analogWrite(5, 0);
        analogWrite(6, 0);

        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(1, LOW);
        digitalWrite(12, LOW);
      }

      //LPodBackward
      else if (Xbox.getAnalogHat(LeftHatX) < -7599)
      {
        l = Xbox.getAnalogHat(LeftHatX);
        m = map(l, -7600, -32768, 0, 100);

        analogWrite(2, m);
        analogWrite(3, m);
        analogWrite(4, 0);
        analogWrite(5, 0);
        analogWrite(6, 0);

        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(12, HIGH);
      }

      //Buffer
      else if (((Xbox.getAnalogHat(RightHatY) > 7500) && (Xbox.getAnalogHat(RightHatY) < 7600)) || ((Xbox.getAnalogHat(RightHatX) > 7500) && (Xbox.getAnalogHat(RightHatX) < 7600)) || ((Xbox.getAnalogHat(LeftHatY) > 7500) && (Xbox.getAnalogHat(LeftHatY) < 7600)) || ((Xbox.getAnalogHat(LeftHatX) > 7500) && (Xbox.getAnalogHat(LeftHatX) < 7600)))
      {
        analogWrite(4, 0);
        analogWrite(5, 0);
        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(6, 0);

        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(12, HIGH);
      }
      else
      {
        analogWrite(4, 0);
        analogWrite(5, 0);
        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(6, 0);

        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(12, HIGH);
      }
      /* if (Xbox.getButtonPress(L2, i) || Xbox.getButtonPress(R2, i)) {
         Serial.print("L2: ");
         Serial.print(Xbox.getButtonPress(L2, i));
         Serial.print("\tR2: ");
         Serial.println(Xbox.getButtonPress(R2, i));
         Xbox.setRumbleOn(Xbox.getButtonPress(L2, i), Xbox.getButtonPress(R2, i), i);
        }

        if (Xbox.getAnalogHat(LeftHatX, i) > 7500 || Xbox.getAnalogHat(LeftHatX, i) < -7500 || Xbox.getAnalogHat(LeftHatY, i) > 7500 || Xbox.getAnalogHat(LeftHatY, i) < -7500 || Xbox.getAnalogHat(RightHatX, i) > 7500 || Xbox.getAnalogHat(RightHatX, i) < -7500 || Xbox.getAnalogHat(RightHatY, i) > 7500 || Xbox.getAnalogHat(RightHatY, i) < -7500) {
         if (Xbox.getAnalogHat(LeftHatX, i) > 7500 || Xbox.getAnalogHat(LeftHatX, i) < -7500) {
           Serial.print(F("LeftHatX: "));
           Serial.print(Xbox.getAnalogHat(LeftHatX, i));
           Serial.print("\t");
         }
         if (Xbox.getAnalogHat(LeftHatY, i) > 7500 || Xbox.getAnalogHat(LeftHatY, i) < -7500) {
           Serial.print(F("LeftHatY: "));
           Serial.print(Xbox.getAnalogHat(LeftHatY, i));
           Serial.print("\t");
         }
         if (Xbox.getAnalogHat(RightHatX, i) > 7500 || Xbox.getAnalogHat(RightHatX, i) < -7500) {
           Serial.print(F("RightHatX: "));
           Serial.print(Xbox.getAnalogHat(RightHatX, i));
           Serial.print("\t");
         }
         if (Xbox.getAnalogHat(RightHatY, i) > 7500 || Xbox.getAnalogHat(RightHatY, i) < -7500) {
           Serial.print(F("RightHatY: "));
           Serial.print(Xbox.getAnalogHat(RightHatY, i));
         }
         Serial.println();
        }

        if (Xbox.getButtonClick(UP, i)) {
         Xbox.setLedOn(LED1, i);
         Serial.println(F("Up"));
        }
        if (Xbox.getButtonClick(DOWN, i)) {
         Xbox.setLedOn(LED4, i);
         Serial.println(F("Down"));
        }
        if (Xbox.getButtonClick(LEFT, i)) {
         Xbox.setLedOn(LED3, i);
         Serial.println(F("Left"));
        }
        if (Xbox.getButtonClick(RIGHT, i)) {
         Xbox.setLedOn(LED2, i);
         Serial.println(F("Right"));
        }

        if (Xbox.getButtonClick(START, i)) {
         Xbox.setLedMode(ALTERNATING, i);
         Serial.println(F("Start"));
        }
        if (Xbox.getButtonClick(BACK, i)) {
         Xbox.setLedBlink(ALL, i);
         Serial.println(F("Back"));
        }
        if (Xbox.getButtonClick(L3, i))
         Serial.println(F("L3"));
        if (Xbox.getButtonClick(R3, i))
         Serial.println(F("R3"));

        if (Xbox.getButtonClick(L1, i))
         Serial.println(F("L1"));
        if (Xbox.getButtonClick(R1, i))
         Serial.println(F("R1"));
        if (Xbox.getButtonClick(XBOX, i)) {
         Xbox.setLedMode(ROTATING, i);
         Serial.print(F("Xbox (Battery: "));
         Serial.print(Xbox.getBatteryLevel(i)); // The battery level in the range 0-3
         Serial.println(F(")"));
        }
        if (Xbox.getButtonClick(SYNC, i)) {
         Serial.println(F("Sync"));
         Xbox.disconnect(i);
        }

        if (Xbox.getButtonClick(A, i))
         Serial.println(F("A"));
        if (Xbox.getButtonClick(B, i))
         Serial.println(F("B"));
        if (Xbox.getButtonClick(X, i))
         Serial.println(F("X"));
        if (Xbox.getButtonClick(Y, i))
         Serial.println(F("Y"));
      */
    }
  }
}
//}

