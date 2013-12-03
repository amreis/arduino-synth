#include "rgb_led.h"


RGB_LED::RGB_LED()
{
  this->RED_PIN = 7;
  this->GREEN_PIN = 6;
  this->BLUE_PIN = 5;
  pinMode(this->RED_PIN, OUTPUT);
  pinMode(this->GREEN_PIN, OUTPUT);
  pinMode(this->BLUE_PIN, OUTPUT);
  
}

RGB_LED::RGB_LED(short R_PIN, short G_PIN, short B_PIN)
{
  this->RED_PIN = R_PIN;
  this->GREEN_PIN = G_PIN;
  this->BLUE_PIN = B_PIN;
  
  pinMode(this->RED_PIN, OUTPUT);
  pinMode(this->GREEN_PIN, OUTPUT);
  pinMode(this->BLUE_PIN, OUTPUT);
}

void RGB_LED::setRed(unsigned short value)
{
  analogWrite(RED_PIN, value);
}

void RGB_LED::setGreen(unsigned short value)
{
  analogWrite(GREEN_PIN, value);
}

void RGB_LED::setBlue(unsigned short value)
{
  analogWrite(BLUE_PIN, value);
}

void RGB_LED::setColor(unsigned short red,
                  unsigned short green,
                  unsigned short blue)
{
  setRed(red); 
  setGreen(green);
  setBlue(blue);
}
