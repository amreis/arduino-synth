#include "waves.h"

const short POT_STEP[8] = {A0, A1, A2, A3, A4, A5, A6, A7 };
const short LED_STEP[8] = {36, 34, 32, 30, 28, 26, 24, 22 };

const short DO = 1;
const short DO_SHARP = 2;
const short RE = 3;
const short RE_SHARP = 4;
const short MI = 5;
const short FA = 6;
const short FA_SHARP = 7;
const short SOL = 8;
const short SOL_SHARP = 9;
const short LA = 10;
const short LA_SHARP = 11;
const short SI = 12;

void setup()
{
  int i;
  for (i = 0; i < 8; i++)
  {
    pinMode(POT_STEP[i], INPUT);
    pinMode(LED_STEP[i], OUTPUT);
  }
}
int currentStep;
int duration;
void loop()
{
  // Main loop:
  // For Each Step s in StepSequencer do:
  //   Play the frequency associated with s for x millis.
  //   Turn s's led on.
  //   Next step.
  //   Cycle!
  for (currentStep = 0; currentStep < 8; currentStep ++)
  {
      duration = map(analogRead(POT_STEP[7]), 0, 1023, 100, 800);
    int note = map(analogRead(currentStep), 0, 1023, 0, 12);
    digitalWrite(LED_STEP[currentStep], HIGH);
    if (note != 0)
      squareWave(100/note + 100, duration);
    else delay(duration);
    digitalWrite(LED_STEP[currentStep], LOW);
    
  }
}
