#include "Arduino.h"
#include "Lever.h"

extern volatile boolean lev0pressed;
extern volatile boolean lev1pressed;

Lever::Lever(int leverPin, int inLimitPin, int outLimitPin, int motorPinOut, int motorPinIn) {
    _leverPin = leverPin;
    _inLimitPin = inLimitPin;
    _outLimitPin = outLimitPin;
    _motorPinOut = motorPinOut;
    _motorPinIn = motorPinIn;
    pinMode(_motorPinOut, OUTPUT);
    pinMode(_motorPinIn, OUTPUT);
    pinMode(_leverPin, INPUT);
    pinMode(_inLimitPin, INPUT);
    pinMode(_outLimitPin, INPUT);
    stopCarriage();
    setCarriage(true);
    attachInterrupt(3, lever0Pressed, RISING);
    attachInterrupt(4, lever1Pressed, RISING);
}  

void Lever::setCarriage(bool position) {

    // detachInterrupt(3);
    // detachInterrupt(4);    
    // noInterrupts();
    go(position);

    if(position) {
        while(!outLimitState()) {}
    }
    else {
        while(!inLimitState()) {}
    }
    stopCarriage();
    // delayMicroseconds(10000);
    // interrupts();
}

void Lever::init() {
    setCarriage(true);
}

bool Lever::state() {
    if(digitalRead(_leverPin) == HIGH) {
        delay(3);//debounce
        return (digitalRead(_leverPin) == HIGH);
    }
    return false;
}

bool Lever::inLimitState() {
    return (digitalRead(_inLimitPin) == LOW);
}

bool Lever::outLimitState() {
    return (digitalRead(_outLimitPin) == LOW);
}

void Lever::stopCarriage() {
    digitalWrite(_motorPinOut, HIGH);
    digitalWrite(_motorPinIn, HIGH);
}

void Lever::go(bool direction) {
    stopCarriage();
    if(direction) digitalWrite(_motorPinOut, LOW);
    else digitalWrite(_motorPinIn, LOW);
}

void lever0Pressed() {
    lev0pressed = true;
}

void lever1Pressed() {
    lev1pressed = true;
}