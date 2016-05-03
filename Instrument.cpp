#include "Instrument.h"
#include "Arduino.h"

Instrument::Instrument(int pin, func_t isr) {
	_pin = pin;
	pinMode(_pin, INPUT);
	attachInterrupt(digitalPinToInterrupt(_pin), isr, RISING);
}

boolean Instrument::getState(int debounce) {
    delay(debounce);
	return digitalRead(_pin);
}
