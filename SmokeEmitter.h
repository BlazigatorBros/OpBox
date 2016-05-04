#ifndef SmokeEmitter_h
#define SmokeEmitter_h

#define LOAD "load"
#define BURN "burn"
#define CLEAR "clear"

#define S_WAIT 0
#define S_OK 1
#define S_WARNING 2
#define S_ERROR 3

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
                String getLastMessage();
        private:
                HardwareSerial * _ser;
                String _inputString;
                boolean _stringComplete;
                String _lastMessage;
};

#endif
