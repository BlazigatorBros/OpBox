#ifndef Lever_h
#define Lever_h

#include "Instrument.h"

class Lever: public Instrument {

        public:
                Lever(int pin,
                        int inMotor,
                        int outMotor,
                        int inLimit,
                        int outLimit)
                        : Instrument(pin)
                {

                }

                void setCarriage(bool state);
};

#endif
