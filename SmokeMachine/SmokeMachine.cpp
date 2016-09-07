/*  
DIR_In:             HIGH = Forward wheel dir            LOW = Backward wheel dir         
Closed-In:          HIGH = Hold ignition clamp closed   LOW = Stay open (default state)
Step_EN-In:         HIGH = Move wheel                   LOW = Wheel stationary
LA-Up/Dn-In:        HIGH = LA down                      LOW = LA up
Motor_EN-In:        HIGH = Wheel motion disabled        LOW = Wheel motion enabled
Ignition_On/Off-In: HIGH = On                           LOW = Off
FAN_PWM-In:         Fan speed proportional to duty cycle 
IR-Out:             HIGH = Magazine empty               LOW = Magazine not empty
LA-FB-Out:          HIGH = LA down or rising            LOW = LA up or falling 
Data#-Out:          HIGH = slot ready to recieve        LOW = slot moving in motion
Fan_FB-Out:         Fan tachyometer out
*/

#include "Arduino.h"
#include "SmokeMachine.h"

volatile boolean magEmpty;
#define clampTime 10000

SmokeMachine::SmokeMachine(int wheelDirPin, int wheelMovePin, int wheelEnPin, int ignitionPin, int fanCtrlPin, int fanFbPin, int slot1Pin, int slot2Pin, int slot3Pin, int clampPin, int loaderIRPin, int loaderFbPin, int loaderDirPin) {

    // _burnTime = burnTime;
    _wheelEnPin = wheelEnPin;
    _fanFbPin = fanFbPin;
    _slot1Pin = slot1Pin;
    _slot2Pin = slot2Pin;
    _slot3Pin = slot3Pin;
    _clampPin = clampPin;
    _wheelMovePin = wheelMovePin;
    _fanCtrlPin = fanCtrlPin;
    _wheelDirPin = wheelDirPin;
    _loaderIRPin = loaderIRPin;
    _loaderFbPin = loaderFbPin;
    _ignitionPin = ignitionPin;
    _loaderDirPin = loaderDirPin;

    pinMode(_fanFbPin, INPUT);
    pinMode(_slot1Pin, INPUT);
    pinMode(_slot2Pin, INPUT);
    pinMode(_slot3Pin, INPUT);
    pinMode(_loaderIRPin, INPUT);
    pinMode(_loaderFbPin, INPUT);

    pinMode(_clampPin, OUTPUT);
    pinMode(_wheelMovePin, OUTPUT);
    pinMode(_wheelEnPin, OUTPUT);
    pinMode(_fanCtrlPin, OUTPUT);
    pinMode(_ignitionPin, OUTPUT);
    pinMode(_wheelDirPin, OUTPUT);
    pinMode(_loaderDirPin, OUTPUT);

    initialize();
}

void SmokeMachine::initialize() {

    digitalWrite(_wheelMovePin, HIGH);  // no wheel movement
    digitalWrite(_loaderDirPin, LOW);  // LA down
    digitalWrite(_wheelEnPin, LOW);     // enable wheel motion  
    digitalWrite(_fanCtrlPin, LOW);     // default fan speed
    digitalWrite(_wheelDirPin, HIGH);   // wheel spins forward 
    digitalWrite(_ignitionPin, LOW);    // ignition off
    magEmpty = false;
//    moveWheel();
}

int SmokeMachine::getPos() {
    if(digitalRead(_slot1Pin)) return 1;
    else if(digitalRead(_slot2Pin)) return 2;
    else if(digitalRead(_slot3Pin)) return 3;
    else return 0;
} 

void SmokeMachine::moveWheel() {
    clampRound(false);
    delay(500);
    int nextPos = 0;
    int currentPos = getPos();
    if (currentPos == 3) nextPos = 1;
    else nextPos = currentPos + 1;

    while(getPos() == currentPos) {
        digitalWrite(_wheelMovePin,LOW);
    }  
    digitalWrite(_wheelMovePin,HIGH);
    while(getPos() != nextPos);
    delay(500);
//    clampRound(true);
}

void SmokeMachine::Empty() {
    clampRound(false);
    delay(500);
    int nextPos = 0;
    int currentPos = getPos();
    if (currentPos == 3) nextPos = 1;
    else nextPos = currentPos + 1;
    while(getPos() == currentPos) {
        digitalWrite(_wheelMovePin,LOW);
    }  
    digitalWrite(_wheelMovePin,HIGH);
    while(getPos() != nextPos);
}

void SmokeMachine::ignition(bool ignit) {
  if(ignit) digitalWrite(_ignitionPin, HIGH);
  else digitalWrite(_ignitionPin,LOW);
}

void SmokeMachine::fanCtrl(bool Fan_Ctrl) {
  if(Fan_Ctrl) digitalWrite(_fanCtrlPin, HIGH);
  else digitalWrite(_fanCtrlPin, LOW);
}

bool SmokeMachine::scanLA() {
  if(digitalRead(_loaderIRPin) == 1) return false;
  else
    return true;
}

void SmokeMachine::raiseLA() {
    
    digitalWrite(_loaderDirPin, HIGH);
    delay(2000);
    digitalWrite(_loaderDirPin, LOW);
    delay(2000);
}

bool SmokeMachine::loadRound() {
    clampRound(true);
    if (digitalRead(_loaderIRPin) == 1) return false;
    else {
        //moveWheel();
        //delay(1000);
        raiseLA();
        return true;
    }
}

int SmokeMachine::standbyInit() {
    if (digitalRead(_loaderIRPin) == 1) return 0;
    else {
        raiseLA();
        moveWheel();
//        delay(1000);
//        while( !digitalRead(_slot1Pin) && !digitalRead(_slot2Pin) && !digitalRead(_slot3Pin));
        clampRound(true);
        if(digitalRead(_loaderIRPin) == 1) return 1;
        else
        {
          raiseLA();
          return 2;
        }
    }
}

void SmokeMachine::clampRound(bool dir) {
    if(dir) digitalWrite(_clampPin, HIGH);
    else digitalWrite(_clampPin, LOW);
}

void SmokeMachine::rotWheel() {
  moveWheel();
  delay(1000);
}

void SmokeMachine::burnRoundnRot(int burnTime) {
    
    //if(loadRound()) {
    //clampRound(true);
    ignition(true);
    delay(burnTime);
    ignition(false);
    delay(clampTime);
    clampRound(false);
    delay(500);
    moveWheel();
    delay(1000);
    clampRound(true);
}

void SmokeMachine::burnRound(int burnTime) {
    
    //if(loadRound()) {
    //clampRound(true);
    ignition(true);
    delay(burnTime);
    ignition(false);
    delay(clampTime);
    clampRound(false);
    delay(500);
}

/*bool SmokeMachine::burnRound() {
    
    //if(loadRound()) {
    clampRound(true);
    ignition(true);
    delay(_burnTime);
    ignition(false);
    delay(_burnTime);
    clampRound(false);
    delay(500);
    if(loadRound()){
        return true;
    }
    else
    {
        moveWheel();
        delay(1000);
        return false;
    }
}*/

