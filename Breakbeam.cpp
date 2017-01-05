#include "Arduino.h"
#include "Breakbeam.h"

extern volatile boolean beamBroken;

Breakbeam::Breakbeam(int detector_pin) {
    //set pin modes
    _detector_pin = detector_pin;
    pinMode(_detector_pin, INPUT);
    attachInterrupt(_detector_pin, movement, FALLING);
    isBroken = false;
    chk_state = false;
}

boolean Breakbeam::stayedBroken(int interval){
	int clk = millis();
	int start = millis();
	int dest = millis() + (interval*1000);
	int brokenFor = 0;
	chk_state = true;

	while(clk < dest){
		if(chk_state == true){
			isBroken = !(digitalRead(_detector_pin));
			if(isBroken == false){
				brokenFor = clk - start;
				chk_state = false;
			}
		}
		clk = millis();
	}

	if(isBroken){
		isBroken = false;
		return false;
	}
	else
		return false;
}

void movement() {
    beamBroken = true;
    isBroken = true;
}