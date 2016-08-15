#ifndef Lever_h
#define Lever_h

#include "Instrument.h"

class Lever: public Instrument {

        public:
        
                void setCarriage(bool state);
                bool outLimitState();
                bool inLimitState();
                void stopCarriage();
                uint16_t SPIcmd(uint16_t command);
                uint16_t SPIdata;

                Lever(  int pin,
                        int inLimit,
                        int outLimit,
                        uint16_t outCMD,
                        uint16_t inCMD,
                        int ssPin,
                        func_t isr)
                        : Instrument(pin, isr)
                {
                    _ssPin = ssPin;
                    _inLimitPin = inLimit;
                    _outLimitPin = outLimit;
                    _outCMD = outCMD;
                    _inCMD = inCMD;
                    init();
                    stopCarriage();
                    pinMode(_ssPin, OUTPUT);
                    pinMode(_leverPin, INPUT);
                    pinMode(_inLimitPin, INPUT);
                    pinMode(_outLimitPin, INPUT);
                    stopCarriage();
                }


        private:
                void go(bool direction);
                int _ssPin;
                int _leverPin;
                int _inLimitPin;
                int _outLimitPin;
                int _PWM_pin;
                int _outCMD;
                int _inCMD;
};

#endif
