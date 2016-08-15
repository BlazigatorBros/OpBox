#ifndef LiquidReward_h
#define LiquidReward_h

#include "Arduino.h"

class LiquidReward {
    public:
        LiquidReward(int num_steps, int ssPin);
        void dispense(int steps_to_move);
        void dispStep(int this_step);
        uint16_t SPIcmd(uint16_t command);

    private:
        int _num_steps;
        int _step_delay;
        int _current_step;
        int _ssPin;
};

#endif
