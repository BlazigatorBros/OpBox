#include "Lever.h"

void Lever::setCarriage(bool state) {

	go(state);
	if(state) {
		while(!outLimitState()) {}
	}
	else {
		while(!inLimitState()) {}
	}
	stopCarriage();
}

void Lever::init() {
	setCarriage(true);
}


bool Lever::inLimitState() {
	return (!digitalRead(_inLimitPin));
}

bool Lever::outLimitState() {
	return (!digitalRead(_outLimitPin));
}



void Lever::stopCarriage() {
	digitalWrite(_motorPinOut, HIGH);
	digitalWrite(_motorPinIn, HIGH);
}

void Lever::go(bool direction) {
	stopCarriage();
	if(direction) {
		digitalWrite(_motorPinOut, LOW);
	}
	else {
		digitalWrite(_motorPinIn, LOW);
	}
}
