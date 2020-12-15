/*
 * PIR sensor 
 */
 #include "pitches.h"
int speakerPin = 9;                // choose the pin for the speaker
int inputPin = 3;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int inputPin2 = 5;               
int pirState2 = LOW;             
int val = 0;                    // variable for reading the pin status
int val2 = 0; 
             

const int lightPin1 = 13;     
const int lightPin2 = 12;
const int lightPin3 = 7;


// notes in the melody:
int melody1[] = {
  NOTE_D1, NOTE_C1, NOTE_B0, NOTE_C1, NOTE_F1, NOTE_B0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 2, 8, 8, 4, 2
};
int melody2[] = {
  NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {
  8, 8, 4, 4, 2
};
int melody3[] = {
  NOTE_B3, NOTE_A4, 
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations3[] = {
  4, 4
};
 
void setup() {
  pinMode(speakerPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(inputPin2, INPUT);     // declare sensor as input


  pinMode(lightPin1, OUTPUT);
  pinMode(lightPin2, OUTPUT);
  pinMode(lightPin3, OUTPUT);

 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  val2 = digitalRead(inputPin2);  // read input value
  int sensorReading = analogRead(A0);
  int thisPitch = map(sensorReading, 10, 150, 120, 1024);
  
  if (val == HIGH) {            // check if the input is HIGH
     for (int thisNote = 0; thisNote < 6; thisNote++) {

      int noteDuration = 1000 / noteDurations[thisNote];
      tone(9, melody1[thisNote], noteDuration);
      digitalWrite(12, HIGH);   
      digitalWrite(13, HIGH);   
 
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
  }
  
    if (pirState == LOW) {
      pirState = HIGH;
    }
  } 
  else {
   noTone(9);
    if (pirState == HIGH){
      pirState = LOW;
      digitalWrite(12, LOW);   
      digitalWrite(13, LOW); 
    }
  }
    if (val2 == HIGH) {            // check if the input is HIGH
     for (int thisNote = 0; thisNote < 5; thisNote++) {

      int noteDuration2 = 1000 / noteDurations2[thisNote];
      tone(9, melody2[thisNote], noteDuration2);
      digitalWrite(7, HIGH);   
         
 
      int pauseBetweenNotes = noteDuration2 * 1.30;
      delay(pauseBetweenNotes);
  }
  
    if (pirState2 == LOW) {
      pirState2 = HIGH;
    }
  } 
  else {
   noTone(9);
    if (pirState2 == HIGH){
      pirState2 = LOW;
      digitalWrite(7, LOW);   
    }
  }
  if (sensorReading < 10){
     Serial.print(" hello ");
     for (int thisNote = 0; thisNote < 5; thisNote++) {

      int noteDuration3 = 1000 / noteDurations3[thisNote];
      tone(9, melody3[thisNote], noteDuration3);
      digitalWrite(7, HIGH);   
         
 
      int pauseBetweenNotes = noteDuration3 * 1.30;
      delay(pauseBetweenNotes);
  }
}
}
