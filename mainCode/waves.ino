#include "waves.h"

const short DAC_BIT0 = 13;
const short DAC_BIT1 = 12;
const short DAC_BIT2 = 11;
const short DAC_BIT3 = 10;

void squareWave (int f, int durationInMillis)
{
    int startPoint = millis();
    do {
    digitalWrite(DAC_BIT0,LOW);
    digitalWrite(DAC_BIT1,LOW);
    digitalWrite(DAC_BIT2,LOW);
    digitalWrite(DAC_BIT3,LOW);
    delayMicroseconds(16*f+120);
 
    digitalWrite(DAC_BIT0,HIGH);
    digitalWrite(DAC_BIT1,HIGH);
    digitalWrite(DAC_BIT2,HIGH);
    digitalWrite(DAC_BIT3,HIGH);
    delayMicroseconds(16*f+120);
    } while (millis() - startPoint <= durationInMillis);
}

