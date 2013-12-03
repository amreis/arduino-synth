#include "waves.h"

const short DAC_BIT0 = 13;
const short DAC_BIT1 = 12;
const short DAC_BIT2 = 11;
const short DAC_BIT3 = 10;
int sinValues [33] = {7, 9, 10, 11, 13, 13, 14, 14, 15, 15, 14, 13, 13, 11, 10, 9, 7, 6, 5, 3, 2, 1, 0, 0, 0, 0, 1, 1, 2, 3, 4, 6, 7};
int crazyValues [33] = { 0,6,12,17,22,25,28,30,31,30,28,25,22,17,12,6,0,-6,-11,-17,-21,-25,-28,-30,-30,-30,-28,-25,-22,-17,-11,-6,-0};

void crazyWave(int freq, int durationInMillis)
{
  int startPoint = millis();
  do {
    for (int i = 0; i < 32; i++)
    {
      digitalWrite(DAC_BIT0, (crazyValues [i] & 1));
      digitalWrite(DAC_BIT1, (crazyValues [i] & 2) >> 1);
      digitalWrite(DAC_BIT2, (crazyValues [i] & 4) >> 2);
      digitalWrite(DAC_BIT3, (crazyValues [i] & 8) >> 3);
      delayMicroseconds(freq-19);
    }
  } while (millis() - startPoint <= durationInMillis);
}

void sawtoothWave(int freq, int durationInMillis)
{
  int startPoint = millis();
  do {
    for (int i = 0; i < 31; i++)
    {
      digitalWrite(DAC_BIT0, (i & 1));
      digitalWrite(DAC_BIT1, (i & 2) >> 1);
      digitalWrite(DAC_BIT2, (i & 4) >> 2);
      digitalWrite(DAC_BIT3, (i & 8) >> 3);
      delayMicroseconds(freq);
    }
  } while (millis() - startPoint <= durationInMillis);
}

void sineWave(int freq, int durationInMillis)
{
  int startPoint = millis();
  do {
    for (int i = 0; i < 32; i++)
    {
      digitalWrite(DAC_BIT0, (sinValues [i] & 1));
      digitalWrite(DAC_BIT1, (sinValues [i] & 2) >> 1);
      digitalWrite(DAC_BIT2, (sinValues [i] & 4) >> 2);
      digitalWrite(DAC_BIT3, (sinValues [i] & 8) >> 3);
      delayMicroseconds(freq-19);
    }
  } while (millis() - startPoint <= durationInMillis);
}

void squareWave (int freq, int durationInMillis)
{
    int startPoint = millis();
    do {
    digitalWrite(DAC_BIT0,LOW);
    digitalWrite(DAC_BIT1,LOW);
    digitalWrite(DAC_BIT2,LOW);
    digitalWrite(DAC_BIT3,LOW);
    delayMicroseconds(16*freq+120);
 
    digitalWrite(DAC_BIT0,HIGH);
    digitalWrite(DAC_BIT1,HIGH);
    digitalWrite(DAC_BIT2,HIGH);
    digitalWrite(DAC_BIT3,HIGH);
    delayMicroseconds(16*freq+120);
    } while (millis() - startPoint <= durationInMillis);
}




void triangularWave(int freq, int durationInMillis)
{
  int startPoint = millis();
  do {
    for (int i = 0; i < 32; i++)
    {
      digitalWrite(DAC_BIT0, (i & 1));
      digitalWrite(DAC_BIT1, (i & 2) >> 1);
      digitalWrite(DAC_BIT2, (i & 4) >> 2);
      digitalWrite(DAC_BIT3, (i & 8) >> 3);
      delayMicroseconds(freq);
    }
    for (int i = 31; i >= 0; i--)
    {
      digitalWrite(DAC_BIT0, (i & 1));
      digitalWrite(DAC_BIT1, (i & 2) >> 1);
      digitalWrite(DAC_BIT2, (i & 4) >> 2);
      digitalWrite(DAC_BIT3, (i & 8) >> 3);
      delayMicroseconds(freq);
    }
  } while (millis() - startPoint <= durationInMillis);
}


