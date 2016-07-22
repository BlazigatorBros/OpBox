#include "LiquidReward.h"
#include <SPI.h>

LiquidReward::LiquidReward(int num_steps, int what_speed) {
	_num_steps = num_steps;
	_what_speed = what_speed;
	_current_step = current_step;
	// _step_delay = 60L * 1000L * 1000L / _step_count / _what_speed;
}

void LiquidReward::dispense(int steps_to_move) {
	int steps_left = steps_to_move;

	while(steps_left > 0) {
		
		_current_step++;
	
		if(_current_step == _num_steps) {
			_current_step = 0;
		}

		steps_left--;
		dispStep(_current_step % 4)
	}
}

void LiquidReward::SPIcmd(uint16_t command) {
	SPI.beginTransaction(SPISettings(5000000, MSBFIRST, SPI_MODE0));
	digitalWrite(_ssPin, LOW);
	SPI.transfer(command,16);
	digitalWrite(_ssPin, HIGH);
	SPI.endTransaction();
}

void dispStep(int this_step) {
	switch (this_step) {
	    case 0:
	    	SPIcmd(_stepper_pos[0]);
	    	SPIcmd(_stepper_pos[3]);
	    	break;
	    case 1:
	    	SPIcmd(_stepper_pos[1]);
	    	SPIcmd(_stepper_pos[3]);
	    	break;
	    case 2:
	    	SPIcmd(_stepper_pos[1]);
	    	SPIcmd(_stepper_pos[2]);
	    	break;
	    case 3:
	    	SPIcmd(_stepper_pos[0]);
	    	SPIcmd(_stepper_pos[2]);
	    	break;
	}
}
