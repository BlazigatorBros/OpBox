#ifndef LiquidReward_h
#define LiquidReward_h

#include "Arduino.h"

class LiquidReward {
        public:
                LiquidReward(int pin);
                void dispense(int duration);
        private:
                int _controlPin;
};

#endif
