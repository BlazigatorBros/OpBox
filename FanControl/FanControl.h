#ifndef FAN_H
#define FAN_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class FanControl {
    public:
        FanControl(int powerPin, int controlPin, int feedbackPin, int RPM);
        void setSpeed(int RPM);
        void fanOn();
        void fanOff();
        int getSpeed();
    private:
        int _controlPin;
        int _feedbackPin;
        int _RPM;
        int _powerPin;
};

void fan_int();
#endif