#include "SmokeEmitter.h"

SmokeEmitter::SmokeEmitter(HardwareSerial * ser) {
	_ser = ser;
}

void SmokeEmitter::sendCommand(String command) {
	_ser->println(command);
}

int SmokeEmitter::checkStatus() {
	while (_ser->available()) {

		char inChar = (char)_ser->read(); 
		_inputString += inChar;
		if (inChar == '\n') {
		    _stringComplete = true;
		}
	}

	if (_stringComplete) {

		if (_inputString.startsWith("Warning:")) {
			return WARNING;
		}

		if(_inputString.startsWith("Error:")) {
			return ERROR;
		}
	}

	return OK;
}
