#ifndef RGB_LED_H
#define RGB_LED_H

class RGB_LED
{
private:
  short RED_PIN;
  short GREEN_PIN;
  short BLUE_PIN;
public:
  RGB_LED();
  RGB_LED(short R_PIN, short G_PIN, short B_PIN);
  void setRed(unsigned short value);
  void setGreen(unsigned short value);
  void setBlue(unsigned short value);
  
  void setColor(unsigned short red,
                unsigned short green,
                unsigned short blue);
};

#endif
