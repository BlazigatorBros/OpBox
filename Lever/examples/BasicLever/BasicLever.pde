#include <Lever.h>
#define leverPin    7 //pin belonging to the lever switch (white wires)
#define inLimitPin  8 //pin attached to the outer limit pin (blue and green wires)
#define outLimitPin 9 //pin attached to inner limit pin ((red and brown wires)
#define outMotorPin 2 //pin sending motor in forward directon
#define inMotorPin  3 //pin sending motor in backwards direction

Lever myLever(leverPin,inLimitPin,outLimitPin,outMotorPin,inMotorPin);

void setup() {
  pinMode(13, OUTPUT);//Output pin, blinks LED
  myLever.setCarriage(true);//send switch out
}

void loop() {
  if (myLever.state()) {//if swich is pressed
    digitalWrite(13, HIGH);//illuminate LED on pin 13
    myLever.setCarriage(false);//send switch in
    myLever.setCarriage(true);//send switch out
    digitalWrite(13, LOW);//turn off LED
  }
}
