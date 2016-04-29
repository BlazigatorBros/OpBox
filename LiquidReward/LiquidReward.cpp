#include "Arduino.h"
#include "LiquidReward.h"

LiquidReward::LiquidReward(int controlPin) {
    _controlPin = controlPin;
    pinMode(_controlPin, OUTPUT);
    digitalWrite(_controlPin, LOW);
}

// void LiquidReward::Dispense(int duration) {
//     digitalWrite(_controlPin, HIGH); 
//     delay(duration);                
//     digitalWrite(_controlPin, LOW);
// }

void LiquidReward::Dispense(bool disp) {
    if(disp) digitalWrite(_controlPin, HIGH);
    else digitalWrite(_controlPin, LOW);                
}