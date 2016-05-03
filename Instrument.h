#ifndef Instrument_h
#define Instrument_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

typedef void (*func_t)();

class Instrument {
        public:
                Instrument(int pin, func_t isr);
                boolean getState(int debounce);
        private:
                int _pin;
};

#endif
