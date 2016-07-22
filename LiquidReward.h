#ifndef LiquidReward_h
#define LiquidReward_h

#include "Arduino.h"

class LiquidReward {
    public:
        LiquidReward(int num_steps, int what_speed);
        void dispense(int steps_to_move);
        void SPIcmd(uint16_t command);
        void dispStep(int this_step);
    private:
        int _num_steps;
        int _what_speed;
        int _step_delay;
        int _current_step;
        uint16_t _stepper_pos[] = {0x1841,0x1821,0x4183,0x4185};
};

#endif
