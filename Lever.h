#ifndef Lever_h
#define Lever_h

#include "Instrument.h"

class Lever: public Instrument {

        public:
        
                void setCarriage(bool state);
                bool outLimitState();
                bool inLimitState();
                void stopCarriage();
                void init();
                void SPIcmd(uint16_t command);

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
                    setCarriage(true);
                }

        private:
                void go(bool direction);
                int _ssPin;
                int _leverPin;
                int _inLimitPin;
                int _outLimitPin;
                int _PWM_pin;
};

#endif
