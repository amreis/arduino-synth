#include "waves.h"
#include "rgb_led.h"

const short POT_STEP[8] = {A0, A1, A2, A3, A4, A5, A6, A7 };
const short LED_STEP[8] = {36, 34, 32, 30, 28, 26, 24, 22 };
const int SQUARE_FREQ [13] = {0, 228, 214, 202, 190, 179, 168, 158, 149, 140, 132, 124, 117};
                          //  x   C    C#   D    D#   E    F    F#   G   G#   A    A#    B
const short NO_NOTE = 0;
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

const short POT_DURATION = A9;
const short POT_WAVE_SELECTOR = A8;

const short NUMBER_OF_WAVES = 5;
const short SQUARE_WAVE = 1;
const short SAWTOOTH_WAVE = 2;
const short TRIANGULAR_WAVE = 3;
const short CRAZY_WAVE = 4; // CRAZY TRAAAAAAAAAAAIN
const short SINE_WAVE = 5;

RGB_LED WAVE_INDICATOR(7,6,5);

void setup()
{
  int i;
  for (i = 0; i < 8; i++)
  {
    pinMode(POT_STEP[i], INPUT);
    pinMode(LED_STEP[i], OUTPUT);
  }
  
  pinMode(POT_DURATION, INPUT);
  pinMode(POT_WAVE_SELECTOR, INPUT);
  
}
int currentStep;
int duration;
int selectedWave;
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
    selectedWave = map(analogRead(POT_WAVE_SELECTOR), 0, 1023, 1, NUMBER_OF_WAVES);
  
    duration     = map(analogRead(POT_DURATION), 0, 1023, 450, 0);
    if (duration == 500) duration = -1;   
    int note = map(analogRead(POT_STEP[currentStep]), 0, 1023, 0, 12);
    digitalWrite(LED_STEP[currentStep], HIGH);
    if (note != NO_NOTE)
    {
      switch(selectedWave)
      {
      case CRAZY_WAVE:
        WAVE_INDICATOR.setColor(0xFF, 0x00, 0x00);
        crazyWave(note*50, duration);
        break;
      case SAWTOOTH_WAVE:
        WAVE_INDICATOR.setColor(0xFF, 0x00, 0xff);
        sawtoothWave(note*50, duration);
        break;
      case SINE_WAVE:
        WAVE_INDICATOR.setColor(0xFF, 0xff, 0x00);
        sineWave(note*50, duration);
        break;
      case SQUARE_WAVE:
        WAVE_INDICATOR.setColor(0x00, 0x00, 0xFF);
        squareWave(SQUARE_FREQ[note], duration);
        break;
      case TRIANGULAR_WAVE:
        WAVE_INDICATOR.setColor(0xCC, 0xCC, 0xCC);
        triangularWave(note*50, duration);
        break;
      }
    }
    else { delay(duration); }
    digitalWrite(LED_STEP[currentStep], LOW);
    
  }
}
