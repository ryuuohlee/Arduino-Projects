//Project 6
/*
   Set the force sensor with a while loop to change the color of the LED.
*/

#include <ArduinoSTL.h>
using namespace std;


//global variables
const int BLED = 9;
const int RLED = 11;
const int GLED = 10;
const int FS = 0;
int val = 0;
const int min_pressure = 25;
const int max_pressure = 535;
int threshold = 240;
int maxVal = 255;

void setup()
{
  Serial.begin(9600);
  pinMode(BLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(FS, INPUT);

  digitalWrite(BLED, HIGH);
  digitalWrite(RLED, HIGH);
  digitalWrite(GLED, HIGH);
}

void loop()
{
  bool pressed = false;
  bool released = false;

  while (!pressed || !released)
  { val = analogRead(FS);
    val = map(val, min_pressure, max_pressure, 255, 0);
    val = constrain(val, 0, 255);
    if ( val < maxVal && pressed)
    {
      maxVal = val;
    }
    if (val < threshold)
    {
      pressed = true;
    }
    else if (pressed && val > threshold)
    {
      released = true;
    }
  }

  if ((maxVal > 170) && (maxVal < 254))          //BLUE LIGHT
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(BLED, LOW);
    digitalWrite(GLED, HIGH);
  }
  else if ((maxVal > 85) && (maxVal < 170))  //GREEN LIGHT
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(BLED, HIGH);
    digitalWrite(GLED, LOW);
  }
  else if ((maxVal >= 0) && (maxVal <= 85))   //RED LIGHT
  {
    digitalWrite(RLED, LOW);
    digitalWrite(BLED, HIGH);
    digitalWrite(GLED, HIGH);
  }
  cout << maxVal << endl;
  delay(500);
  maxVal=255;
}
