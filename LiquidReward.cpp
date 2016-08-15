#include "LiquidReward.h"
#include <SPI.h>

#define STEPPER_A_NEG 	0x1841 	//6209
#define STEPPER_A_POS 	0x1821 	//6177
#define STEPPER_B_POS 	0x4183	//16771
#define STEPPER_B_NEG 	0x4185	//16773
#define STEPPER_STOP_A 	0x1801	//6145
#define STEPPER_STOP_B	0x4181	//16769

LiquidReward::LiquidReward(int num_steps, int ssPin) {
	_num_steps = num_steps;
	_ssPin = ssPin;
	_current_step = 0;
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
		dispStep(_current_step % 4);
		delay(15);
	}
	SPIcmd(STEPPER_STOP_A);
	SPIcmd(STEPPER_STOP_B);
}

void LiquidReward::dispStep(int this_step) {
	switch (this_step) {
	    case 0:
	    	SPIcmd(STEPPER_A_POS);
	    	SPIcmd(STEPPER_STOP_B);
	    	break;
	    case 1:
	    	SPIcmd(STEPPER_B_POS);
	    	SPIcmd(STEPPER_STOP_A);
	    	break;
	    case 2:
	    	SPIcmd(STEPPER_A_NEG);
	    	SPIcmd(STEPPER_STOP_B);
	    	break;
	    case 3:
	    	SPIcmd(STEPPER_B_NEG);
	    	SPIcmd(STEPPER_STOP_A);
	    	break;
	}
}

uint16_t LiquidReward::SPIcmd(uint16_t command) {
	SPI.beginTransaction(SPISettings(5000000, MSBFIRST, SPI_MODE1));
	digitalWrite(_ssPin, LOW);
	SPI.transfer16(command);
	digitalWrite(_ssPin, HIGH);
	SPI.endTransaction();
}

