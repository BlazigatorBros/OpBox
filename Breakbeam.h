#ifndef BREAKBEAM_H
#define BREAKBEAM_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Breakbeam {

    public:
        Breakbeam(int detector_pin);
		bool stayedBroken(int time);

    private:
        int _detector_pin;
        bool isBroken;
        bool chk_state;
};
    
void movement();

#endif
