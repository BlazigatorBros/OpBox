#ifndef Fan_h
#define Fan_h

class Fan {
        public:
                Fan(int pin);
                void fanOn();
                void fanOff();
                void setSpeed(int speed);
                int getSpeed();
};

#endif
