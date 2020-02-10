/*
  Project 8
  Create a longer melody using the playTone() method.

  The calculation of the tones is made following the mathematical
  operation:

        timeHigh = period / 2 = 1 / (2 * toneFrequency)

  where the different tones are described as in the table:

  note   frequency   period  timeHigh
  c          261 Hz          3830  1915
  d          294 Hz          3400  1700
  e          329 Hz          3038  1519
  f          349 Hz          2864  1432
  g          392 Hz          2550  1275
  a          440 Hz          2272  1136
  b          493 Hz          2028  1014
  C          523 Hz          1912  956

  http://www.arduino.cc/en/Tutorial/Melody
*/

#include <ArduinoSTL.h>
using namespace std;


//global variables
int speakerPin = 9;
int tempo = 200;

void playTone(int tone, int duration)
{
  for (long i = 0; i < duration * 1000L; i += tone * 2)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration)
{
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', ' ' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 0 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++)
  {
    if (names[i] == note)
    {
      playTone(tones[i], duration);
    }
  }
}

void read(char str[], int capacity, int &size)
{
  size = 0;
  while (size < capacity)
  {
    str[size] = cin.get();

    if (str[size] == '\n' || str[size] == '\r')
    {
      str[size] = 0;
      return;
    }
    size++;
  }
  cout << "\nNotes entered is too large";
  str[0] = 0;
  size = 0;
}

void setup()
{
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char notes[128];
  int maxLength = sizeof(notes);
  int length;

  cout << "Enter melody notes(use ' ' as rests and '-' to carry notes):" << endl;
  read(notes, maxLength, length);

  for (int i = 0; i < length; i++)
  {
    char lastnote;
    if (notes[i] == ' ')
    {
      delay(200); // rest
    }
    else if (notes[i] >= 'a' && notes[i] <= 'g' || notes[i] == 'C')
    {
      playNote(notes[i], tempo);
      lastnote = notes[i];
      delay(10);
    }
    else if (notes[i] == '-')
    {
      playNote(lastnote, tempo);
    }
  }
}
