#include "Arduino.h"
#include "FanControl.h"

volatile long half_revolutions = 0;

FanControl::FanControl(int powerPin, int controlPin, int feedbackPin, int RPM) {
    _feedbackPin = feedbackPin;
    _controlPin = controlPin;
    _powerPin = powerPin;
    _RPM = RPM;

    pinMode(_feedbackPin, INPUT);
    pinMode(_powerPin, OUTPUT);
    pinMode(_controlPin, OUTPUT);
    digitalWrite(_powerPin, LOW);
    digitalWrite(_feedbackPin, HIGH);
    analogWrite(_controlPin, RPM);
}

void FanControl::setSpeed(int RPM) {
    analogWrite(_controlPin, RPM);
}

int FanControl::getSpeed() {

    if (digitalRead(_powerPin)) {
        return 0;
    }
    else {
        unsigned long timeold = 0;
        attachInterrupt(2, fan_int, FALLING);
        timeold = millis(); 
    
        while((millis() - timeold) < 1000);

        detachInterrupt(2);
        _RPM = 30*1000/(millis() - timeold)*half_revolutions;    
        half_revolutions = 0; // Restart the RPM counter

        return _RPM;
    }
}

void FanControl::fanOn() {
    digitalWrite(_powerPin, HIGH);
}

void FanControl::fanOff() {
    digitalWrite(_powerPin, LOW);
}

void fan_int() {
    half_revolutions++;
}


////////////////////////////////////////////////
// Max RPM: 2800
// Min RPM: 1000
// Max at 255
// Min at 80
// 5% RPM increment = 15 steps = ~100RPM
////////////////////////////////////////////////