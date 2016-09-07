#ifndef SMOKEMACHINE_H
#define SMOKEMACHINE_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class SmokeMachine
{
  public:
    SmokeMachine(int wheelDirPin, int wheelMovePin, int wheelEnPin, int ignitionPin, int fanCtrlPin, int fanFbPin, int slot1Pin, int slot2Pin, int slot3Pin, int clampPin, int loaderIRPin, int loaderFbPin, int loaderDirPin);
    void burnRound(int burnTime);
   
    bool loadRound();
    bool scanLA();
    
    int standbyInit();
    int getPos();

    void Empty();
    void moveWheel();
    void clampRound(bool dir);
    void ignition(bool ignit);
    void fanCtrl(bool Fan_Ctrl);
    void burnRoundnRot(int burnTime);
    void rotWheel();
    
  private:
    int _burnTime;
    int _wheelEnPin;
    int _fanFbPin;
    int _slot1Pin;
    int _slot2Pin;
    int _slot3Pin;
    int _clampPin;
    int _wheelMovePin;
    int _fanCtrlPin;
    int _wheelDirPin;
    int _loaderIRPin;
    int _loaderFbPin;
    int _ignitionPin;
    int _loaderDirPin;

    void initialize();
    
    void raiseLA();
//    void clampRound(bool dir);
};
#endif
