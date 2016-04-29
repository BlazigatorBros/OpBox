#ifndef Reward_H
#define Reward_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class LiquidReward {
    public:
        LiquidReward(int controlPin);
        void Dispense(bool disp);
    private:
        int _controlPin;
};
#endif