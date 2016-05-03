#include "LiquidReward.h"

LiquidReward::LiquidReward(int pin) {
    _controlPin = pin;
    pinMode(_controlPin, OUTPUT);
    digitalWrite(_controlPin, LOW);
}

void LiquidReward::dispense(int duration) {
    digitalWrite(_controlPin, HIGH);
    delay(duration);
    digitalWrite(_controlPin, LOW);  
}
