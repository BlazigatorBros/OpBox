#ifndef LEVER_H
#define LEVER_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class Lever
{
  public:
    Lever(int leverPin,  int inLimitPin, int outLimitPin, int motorPinOut, int motorPinIn);
    bool state();
    void setCarriage(bool position);
    bool outLimitState();
    bool inLimitState();
    void stopCarriage();
    void init();
  private:
    void go(bool direction);
    int _motorPinOut; 
    int _motorPinIn;
    int _leverPin;
    int _inLimitPin;
    int _outLimitPin;
    int _directionPin;
    int _PWM_pin;
};

void lever0Pressed();
void lever1Pressed();

#endif
