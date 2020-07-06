/*
Rotary Encoder - get the position
modified on 23 Feb 2019
by Saeed Hosseini
https://electropeak.com/learn/
*/

#include <Arduino.h>

#define encoderOutA 6 // CLK
#define encoderOutB 7 // DT
int counter = 0;
int State;
int old_State;

void setup() {
pinMode (encoderOutA, INPUT);
pinMode (encoderOutB, INPUT);
Serial.begin (9600);
//Read First Position of Channel A
old_State = digitalRead(encoderOutA);
}

void loop() {
State = digitalRead(encoderOutA);
if (State != old_State)
{
if (digitalRead(encoderOutB) != State)
{
counter ++;
}
else {
counter --;
}
Serial.print("Position: ");
Serial.println(counter);
}
old_State = State; // the first position was changed
}