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
		void movement();
    private:
        int _detector_pin;
        bool chk_state;
        bool isBroken;
};
#endif
