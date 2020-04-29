/*
 * Arduino based Tap and Tone player
 * Published by: CircuitDigest.com
 * Code By: B.Aswinth Raj
 * Dated:8-7-2017
 * 
 * ###CONNECTIONS###
 * Darlington Wire 1 -> Pin 2
 * Darlington Wire 2 -> Pin 3
 * FlexSensor 1 -> A0
 * FlexSensor 2 -> A1
 * Speaker -> Pin 8
 */

#include "pitches.h"      //add this librarey into the project folder
int flexSensor1,flexSensor2;

void setup() {
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(2), tone1, LOW); //Trigger tone1 when LOW
attachInterrupt(digitalPinToInterrupt(3), tone2, LOW); //Trigger tone2 when LOW
Serial.begin(9600);
}

void loop() {
 flexSensor1 = map(analogRead(A0),200,130,1,3); //Map up with your own values based on your flex sensor
 flexSensor2 = map(analogRead(A1),170,185,1,3); //Map up with your own values based on your flex sensor
}

//**Function to execute on Interrupt 1**//
void tone1()
{

if (flexSensor1==1)
tone(8, NOTE_D4,50);
else if (flexSensor1==2)
tone(8, NOTE_A3,50);
else if (flexSensor1==3)
tone(8, NOTE_G4,50);
else
tone(8, NOTE_D4,50); 
}

//**Function to execute on Interrupt 2**//
void tone2()
{

if (flexSensor1==1)
tone(8, NOTE_A4,50);
else if (flexSensor1==2)
tone(8, NOTE_F4,50);
else if (flexSensor1==3)
tone(8, NOTE_E4,50);
else
  tone(8, NOTE_A4,50);
}
