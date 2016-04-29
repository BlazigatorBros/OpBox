#include "Instrument.h"
#include "Arduino.h"

Instrument::Instrument(int pin, func_t isr) {

	_pin = pin;
	pinMode(_pin, INPUT);
	attachInterrupt(_pin, isr, FALLING);
}

boolean Instrument::getState() {
	return digitalRead(_pin);
}
