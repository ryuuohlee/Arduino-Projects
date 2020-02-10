//Project #3
/*Creating a code to use two buttons to control the direction order
 of the light bulbs turning on and off.*/

#include <ArduinoSTL.h>
using namespace std;

//global vars
int LED1 = 3;
int LED2 = 4;
int LED3 = 5;
int LED4 = 6;
int BUTTON1 = 7;
int BUTTON2 = 8;
int state1 = 0;
int state2 = 0;
int cnt = -1;
int delayTime = 250;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

void loop()
{
  state1 = digitalRead(BUTTON1);
  state2 = digitalRead(BUTTON2);
  delay(delayTime);
  if (state1 == 0)   //initial starting point with BUTTON1
  {
    if (cnt != -1)
    {
      digitalWrite(LED1 + cnt, LOW);    //turns off current LED
    }
    cnt = cnt + 1;
    cnt = cnt % 4;
    digitalWrite(LED1 + cnt, HIGH);     //turns on next LED
  }
  else if(state2 == 0)
  {
    digitalWrite(LED1 + cnt, LOW);    //turns off current LED
    cnt = cnt - 1;
    cnt = cnt % 4;
    if(cnt < 0)
    {
      cnt = cnt + 4;
    }
    digitalWrite(LED1 + cnt, HIGH);
  }
}
