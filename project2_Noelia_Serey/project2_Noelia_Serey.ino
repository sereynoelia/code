/*
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody1[] = {
  NOTE_A3, NOTE_C3, NOTE_E3, NOTE_A3, NOTE_C3, NOTE_A2, NOTE_B3, NOTE_G2
};
int melody2[] = {
  NOTE_B2, NOTE_B3, NOTE_B3, NOTE_A3, 0, NOTE_A3, NOTE_B3, NOTE_D4,NOTE_B3
};
const int buttonPin = 2;     // the number of the pushbutton pin
const int lightPin1 = 13;     // the number of the pushbutton pin
const int lightPin2 = 12;     // the number of the pushbutton pin


int buttonState = 0;         // variable for reading the pushbutton status
int count = 0;

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 8, 4, 4, 2
};

void setup() {
Serial.begin(9600);

// initialize pin 9 as an output for the speaker:
  pinMode(9, OUTPUT);
  pinMode(lightPin1, OUTPUT);
  pinMode(lightPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  digitalWrite(13, LOW);  
  digitalWrite(12, LOW);   
 


  if (buttonState == HIGH) {
    count += 1;
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(9, melody1[thisNote], noteDuration);
    digitalWrite(13, HIGH);   
 
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

  }
  }
if(count == 3){
  if (buttonState == HIGH) {
    count = 0;
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(9, melody2[thisNote], noteDuration);
    digitalWrite(12, HIGH);   
  
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  }
}
  else{
    noTone(9);
  }
  
 Serial.println(buttonState);
}
