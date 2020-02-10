//Project 7
/*
   Create a RGB LED Night light that has 9 different settings using a force sensor using the calibrate function.
*/
#include <ArduinoSTL.h>
using namespace std;

//global variables
const int RLED = 11;
const int GLED = 10;
const int BLED = 9;

int low_force;
int high_force;
const int FORCE = A0;


void setup()
{
  Serial.begin(9600);

  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(FORCE, INPUT);

  calibrate(FORCE);
}

void loop()
{
  int num;
  //FORCE is the pin# that reads force sensor
  num = sensorRead(FORCE);

  //this function sets the LED,  num is between 0-9
  setRGB_LED(num);

  delay(500);
}

void setRGB_LED(int num)
{
  int val;
  int minV = 0;
  int maxV = 765;

  if (num == 0)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  else if ((num >= 1) && (num <= 3))
  {
    int min_light = 1;
    int max_light = 3;
    val = map(num, min_light, max_light , maxV, minV);
    val = constrain(val, minV, maxV);
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    analogWrite(BLED, val);
  }
  else if ((num >= 4) && (num <= 6))
  {
    int min_light = 4;
    int max_light = 6;
    val = map(num, min_light, max_light , maxV, minV);
    val = constrain(val, minV, maxV);
    digitalWrite(RLED, HIGH);
    analogWrite(GLED, val);
    digitalWrite(BLED, HIGH);
  }
  else if ((num >= 7) && (num <= 9))
  {
    int min_light = 7;
    int max_light = 9;
    val = map(num, min_light, max_light , maxV, minV);
    val = constrain(val, minV, maxV);
    analogWrite(RLED, val);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  else
  {

  }
}

int sensorRead(int FORCE)
{
  int val;
  val = analogRead(FORCE);
  if (val == 0)
  {
    val = 0;
  }
  else if ((val > 0) && (val <= high_force))
  {
    int min_num = 1;
    int max_num = 10;
    int min_val = low_force;
    int max_val = high_force;
    val = map(val, min_val, max_val, min_num, max_num);
    val = constrain(val, min_num, max_num);
  }
  return val;
}

float calibrate(int FORCE)
{
  int val;
  int vtotal;
  int low_force = 1;

  cout << "Hold the force sensor as hard as you can for 5 seconds to calibrate." << endl;

  for (int i = 0; i < 10; i++)
  {
    val = analogRead(FORCE);
    vtotal = vtotal + val;
    delay(500);
  }
  high_force = vtotal / 10;
  cout << high_force << endl;
  return high_force;
}
