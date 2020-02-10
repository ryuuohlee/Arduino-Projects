//Project 4
/*
  This project uses a potentiometer to act as a thermostat and turn 4 LED's on and off
  using analog inputs.
*/

#include <ArduinoSTL.h>
using namespace std;

int LED1 = 6;
int LED2 = 9;
int LED3 = 10;
int LED4 = 11;
const int POT = 0;    //POT on analog pin 0
int delayTime = 10;
int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(POT, INPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

}

void loop()
{
  if (val == 0)
  {
    val = analogRead(POT);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(delayTime);
  }
  if ((val > 0) && (val < 255))
  {
    val = analogRead(POT);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(delayTime);
  }
  if ((val >= 255) && (val < 510))
  {
    val = analogRead(POT);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(delayTime);
  }
  if ((val >= 510) && (val < 766))
  {
    val = analogRead(POT);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    delay(delayTime);
  }
  if ((val >= 766) && (val < 1023))
  {
    val = analogRead(POT);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    delay(delayTime);
  }
}
