//Project #2
//This project turns an LED on for the duration depending on what the user inputs.

// the setup function runs once when you press reset or power the board
#include <ArduinoSTL.h>


using namespace std;

int onTime;  // time led is on
int offTime; // time led is off

void setup()
{
  Serial.begin(9600);
  cout << "What is your desired delay time in milliseconds?" << endl;
  cin >> onTime;
  pinMode(13, OUTPUT);
  if ( onTime < 100 )
  {
    cout << "Value is too small!" << endl;
  }
  if ( onTime > 2000 )
  {
    cout << "Value is too large!" << endl;
  }

}


void loop()
{
  if ( (onTime >= 100) && (onTime <= 2000))
  {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(onTime);                       // wait for onTime period
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(offTime);         // wait for offTime period
    offTime = onTime * 2;   // off time is double on time.
  }
  else
  {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for onTime period
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);         // wait for offTime period
  }
}
