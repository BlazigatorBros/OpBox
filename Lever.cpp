#include "Lever.h"
#include <SPI.h>

#define M_stop 0x0780

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
/*
void Lever::init() {
	setCarriage(true);
}
*/
bool Lever::inLimitState() {
	return (!digitalRead(_inLimitPin));
}

bool Lever::outLimitState() {
	return (!digitalRead(_outLimitPin));
}

void Lever::stopCarriage() {
	SPIcmd(M_stop);
}

void Lever::go(bool direction) {
	stopCarriage();
	if(direction) {
		SPIcmd(_inCMD);
	}
	else {
		SPIcmd(_outCMD);
	}
}

uint16_t Lever::SPIcmd(uint16_t command){
	SPI.beginTransaction(SPISettings(5000000, MSBFIRST, SPI_MODE1));
	digitalWrite(_ssPin, LOW);
	SPIdata = SPI.transfer16(command);
	digitalWrite(_ssPin, HIGH);
	SPI.endTransaction();
	return SPIdata;
}
