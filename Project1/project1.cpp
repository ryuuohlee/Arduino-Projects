//Project 1
//This project turns an LED on for one second, then off for one second, repeatedly.

// the setup function runs once when you press reset or power the board
#include <ArduinoSTL.h>
using namespace std;

int onTime;  // time led is on
int offTime; // time led is off

void setup() {
  Serial.begin(9600);
  cout << "What is your desired delay time in milliseconds?" << endl;
  cin >> onTime;
  pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(onTime);                       // wait for onTime period
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(offTime);         // wait for offTime period
  offTime = onTime * 2;   // off time is double on time.
}
