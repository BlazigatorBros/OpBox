#ifndef Lever_h
#define Lever_h

#include "Instrument.h"

class Lever: public Instrument {

        public:
                Lever(int pin,
                        int inLimit,
                        int outLimit,
                        int outMotor,
                        int inMotor,
                        func_t isr)
                        : Instrument(pin, isr)
                {

                    _inLimitPin = inLimit;
                    _outLimitPin = outLimit;
                    _motorPinOut = outMotor;
                    _motorPinIn = inMotor;
                    pinMode(_motorPinOut, OUTPUT);
                    pinMode(_motorPinIn, OUTPUT);
                    pinMode(_leverPin, INPUT);
                    pinMode(_inLimitPin, INPUT);
                    pinMode(_outLimitPin, INPUT);
                    stopCarriage();
                    setCarriage(true);
                }

                void setCarriage(bool state);
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

#endif
