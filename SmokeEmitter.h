#ifndef SmokeEmitter_h
#define SmokeEmitter_h

#define LOAD "load"
#define BURN "burn"
#define CLEAR "clear"

#define OK 0
#define WARNING 1
#define ERROR 2

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class SmokeEmitter {
        public:
                SmokeEmitter(HardwareSerial * ser);
                void sendCommand(String Command);
                int checkStatus();
        private:
                HardwareSerial * _ser;
                String _inputString;
                boolean _stringComplete;
};

#endif
