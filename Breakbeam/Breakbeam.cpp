#include "Arduino.h"
#include "Breakbeam.h"

extern volatile boolean beamBroken;

Breakbeam::Breakbeam(int detector_pin) {
    //set pin modes
    _detector_pin = detector_pin;
    pinMode(_detector_pin, INPUT);
    attachInterrupt(_detector_pin, movement, FALLING);
}

void movement() {
    beamBroken = true;
}