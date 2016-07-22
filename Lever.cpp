#include "Lever.h"
#include <SPI.h>

#define M_stop 0x0781

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
	SPI.begin();
	digitalWrite(_ssPin, HIGH);
}

bool Lever::inLimitState() {
	return (!digitalRead(_inLimitPin));
}

bool Lever::outLimitState() {
	return (!digitalRead(_outLimitPin));
}

void Lever::stopCarriage() {
	SPIcmd(M_stop)
}

void Lever::go(bool direction) {
	stopCarriage()
	if(direction) {
		SPIcmd(_inCMD);
	}
	else {
		SPIcmd(_outCMD);
	}
}

void Lever::SPIcmd(uint16_t command){
	SPI.beginTransaction(SPISettings(5000000, MSBFIRST, SPI_MODE0));
	digitalWrite(_ssPin, LOW);
	SPI.transfer(command,16);
	digitalWrite(_ssPin, HIGH);
	SPI.endTransaction();
}
