#include "SmokeEmitter.h"

SmokeEmitter::SmokeEmitter(HardwareSerial * ser) {
	_ser = ser;
	_ser->begin(9600);
}

void SmokeEmitter::sendCommand(String command) {
	_ser->print(command);
}

int SmokeEmitter::checkStatus() {
	while (_ser->available()) {

		char inChar = (char)_ser->read(); 
		_inputString += inChar;
		if (inChar == '\r') {
		    _inputString = "";
		}
		if (inChar == '\n') {
		    _stringComplete = true;
		}
	}

	if (_stringComplete) {

        _lastMessage = _inputString;
        _inputString = "";
		_stringComplete = false;

		if (_lastMessage.startsWith("Warning:")) {
			return S_WARNING;
		}

		if(_lastMessage.startsWith("Error:")) {
			return S_ERROR;
		}
		
		return S_OK;

	}

	return S_WAIT;
}

String SmokeEmitter::getLastMessage() {
    return _lastMessage;
}
