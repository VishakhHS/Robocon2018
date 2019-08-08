const byte rotation = 8;
const byte rotation1 = 9;

//const byte button1 = 12;
//const byte button2 = 13;
//const byte digital_2 = 5;
const byte reverse = 10;

unsigned int laser_interrupt_1;
unsigned int laser_interrupt_2;
unsigned int laser_interrupt_3 ;

const int s0 = A1;
const int s1 = A0;
const int s2 = A3;
const int s3 = A2;
const int out = A4;
// values
int red = 0;
int green = 0;
int blue = 0;
const int red_pin = A5;
const int blue_pin = 7;
const int green_pin = 4;

int red_flag = 0;
int blue_flag = 0;
int green_flag = 0;


unsigned int rotationState = 0;
unsigned int rotationState1 = 0;
unsigned int reverse_interrupt = 0;

const byte pwm8 = 3;

const byte dir = 2;

const byte buzzer_pwm = 6;

const byte buzzer_dir = 5;
int buttonState = 0;
int State = 0;
int flag1 = 0;
int flag2 = 0;

//unsigned int digital_stop_2 = 0;

void setup()
{
  pinMode(rotation, INPUT);;
  //  pinMode(button1, OUTPUT);
  //  pinMode(button2, OUTPUT);

  pinMode(pwm8, OUTPUT);
  pinMode(dir, OUTPUT);
  analogWrite(pwm8, 0);
  Serial.begin(9600);


  pinMode(buzzer_pwm, OUTPUT);
  pinMode(buzzer_dir, OUTPUT);


  pinMode(reverse, INPUT);


  pinMode(A5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

void loop()
{

  digitalWrite(red_pin , LOW);
  digitalWrite(blue_pin , LOW);
  digitalWrite(green_pin , LOW);


  Serial.println("start");
  analogWrite(pwm8, 0);

  rotationState = digitalRead(rotation);



  color();

 if (3 < blue < 6 && 7 < green < 9 && red == 0)
  {
    digitalWrite(red_pin , HIGH);
    Serial.println("red colour");
    red_flag = 1;
  }

  if (green == 1 && blue == 2 && red == 3)
  {
    digitalWrite(green_pin , HIGH);
    Serial.println("green colour");
    green_flag = 1;

  }

  if ( green == 1 && red == 4 && blue == 0)
  {
    digitalWrite(blue_pin , HIGH);
    Serial.println("blue colour");
    blue_flag = 1;
  }

  laser_interrupt_3 = red_flag;
  laser_interrupt_2 = blue_flag;
  laser_interrupt_1 = green_flag;
  reverse_interrupt = digitalRead(reverse);

  if ((laser_interrupt_3 == 1) && (flag1 == 0))
  {
    digitalWrite(red_pin, HIGH);
    Serial.println("RED");
    analogWrite(pwm8, 80);
    digitalWrite(dir, HIGH);
    rotationState = digitalRead(rotation);
    rotationState1 = digitalRead(rotation1);

    while (rotationState == 0)
    {
      digitalWrite(red_pin, HIGH);
      Serial.println("RED while");
      analogWrite(pwm8, 80);
      digitalWrite(dir, HIGH);
      rotationState = digitalRead(rotation);
      rotationState1 = digitalRead(rotation1);
    }
    if (rotationState == 1)
    {
      //      digitalWrite(blue_pin, HIGH);
      //      Serial.println("BLUE while1");
      //      analogWrite(pwm8, 140);
      //      digitalWrite(dir, HIGH);
      //      // flag2 = 1;
      rotationState = digitalRead(rotation);
      rotationState1 = digitalRead(rotation1);
      analogWrite(pwm8, 0);
      Serial.println("red 0.0..");
      digitalWrite(dir, HIGH);
      digitalWrite(buzzer_dir, HIGH);
      analogWrite(buzzer_pwm, 255);
      delay(500);
      digitalWrite(buzzer_dir, HIGH);
      analogWrite(buzzer_pwm, 0);
      delay(200);
      digitalWrite(buzzer_dir, HIGH);
      analogWrite(buzzer_pwm, 255);
      delay(200);
      digitalWrite(buzzer_dir, HIGH);
      analogWrite(buzzer_pwm, 0);

    }
    flag2 = 0;
    flag1 = 1;
  }
  if ((laser_interrupt_1 == 1) && (flag1 == 0))
  {
    digitalWrite(green_pin, HIGH);
    Serial.println("GREEN");
    analogWrite(pwm8, 80);
    digitalWrite(dir, HIGH);
    rotationState = digitalRead(rotation);
    rotationState1 = digitalRead(rotation1);

    while (rotationState == 0)
    {
      digitalWrite(green_pin, HIGH);
      Serial.println("GREEN while");
      analogWrite(pwm8, 80);
      digitalWrite(dir, HIGH);
      rotationState = digitalRead(rotation);
      rotationState1 = digitalRead(rotation1);
    }
    if (rotationState == 1)
    {
      //      digitalWrite(blue_pin, HIGH);
      //      Serial.println("BLUE while1");
      //      analogWrite(pwm8, 140);
      //      digitalWrite(dir, HIGH);
      //      // flag2 = 1;
      rotationState = digitalRead(rotation);
      rotationState1 = digitalRead(rotation1);
      analogWrite(pwm8, 0);
      Serial.println("green 0.0..");
      digitalWrite(dir, HIGH);
    }

    flag2 = 0;
    flag1 = 1;
  }


  if ((laser_interrupt_2 == 1) && (flag1 == 0))
  {
    digitalWrite(blue_pin, HIGH);
    Serial.println("BLUE");
    analogWrite(pwm8, 80);
    digitalWrite(dir, HIGH);

    rotationState = digitalRead(rotation);
    rotationState1 = digitalRead(rotation1);
    while (rotationState == 0)
    {
      digitalWrite(blue_pin, HIGH);
      Serial.println("BLUE while");
      analogWrite(pwm8, 80);
      digitalWrite(dir, HIGH);
      // flag2 = 1;
      rotationState = digitalRead(rotation);
      rotationState1 = digitalRead(rotation1);
    }
    if (rotationState == 1)
    {
      //      digitalWrite(blue_pin, HIGH);
      //      Serial.println("BLUE while1");
      //      analogWrite(pwm8, 140);
      //      digitalWrite(dir, HIGH);
      //      // flag2 = 1;
      rotationState = digitalRead(rotation);
      rotationState1 = digitalRead(rotation1);
      analogWrite(pwm8, 0);
      Serial.println("blue 0.0..");
      digitalWrite(dir, HIGH);
    }
    flag2 = 0;
    flag1 = 1;

  }

  if ((reverse_interrupt == 1) && (flag2 == 0))
  {
    delay(500);
    Serial.println("REVERSE");
    analogWrite(pwm8, 80);
    digitalWrite(dir, LOW);

    rotationState1 = digitalRead(rotation1);
    rotationState = digitalRead(rotation);
    while (rotationState1 == 0)
    {
      Serial.println("REVERSE while");
      analogWrite(pwm8, 80);
      digitalWrite(dir, LOW);
      // flag2 = 1;
      rotationState1 = digitalRead(rotation1);
      rotationState = digitalRead(rotation);
    }
    if (rotationState1 == 1)
    {
      analogWrite(pwm8, 0);

      rotationState1 = digitalRead(rotation1);
      rotationState = digitalRead(rotation);
    }

    analogWrite(pwm8, 0);
    digitalWrite(dir, LOW);

    flag2 = 1;
    flag1 = 0;
  }
  else
  {
    digitalWrite(red_pin , LOW);
    digitalWrite(blue_pin , LOW);
    digitalWrite(green_pin , LOW);
    red_flag = 0;
    blue_flag = 0;
    green_flag = 0;
  }
}

void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  green = map(green, 0, 32767, 0, 1024);
  red = map(red, 0, 32767, 0, 1024);
  blue = map(blue, 0, 32767, 0, 1024);
}


