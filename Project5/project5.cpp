//Project 5
/*
   Use a pot to control the brightness of an LED.
*/

#include <ArduinoSTL.h>
using namespace std;

//global declarations

int LED = 3;
const int POT = 0;
int delayTime = 10;
int val = 0;
int minV = 0;
int maxV = 255;
int potMinV = 0;
int potMaxV = 1023;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);
}

void loop()
{
  val = analogRead(POT);
  val = map(val, potMinV, potMaxV , minV, maxV);
  val = constrain(val, minV, maxV);
  analogWrite(LED, val);
}
