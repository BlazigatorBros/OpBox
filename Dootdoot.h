#ifndef Dootdoot_h
#define Dootdoot_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Dootdoot{

        public:
                Dootdoot(int pin, int freq) {
                        _pin = pin;
                        _freq = freq;
                        pinMode(pin, OUTPUT);
                }

                void doot(int duration) {
                        tone(_pin, _freq, duration);
                }

                void setFreq(int freq) {
                        _freq = freq;
                }

        private:
                int _pin;
                int _freq;
                int _end;
};

#endif
