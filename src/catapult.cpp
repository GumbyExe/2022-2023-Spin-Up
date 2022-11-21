#include "catapult.hpp"
#include "main.h"
using namespace ez;

Motor catapult(10, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_COUNTS);

ADIDigitalIn cataLimit(1);

bool cataPressed = false;

void setCata(int percent){
  // percent to voltage
  int voltage = percent*1.27;
  // -127 to +127
  catapult.move(voltage);
}

void cataFor(double sec, int percent){
  setCata(percent);
  delay(sec*1000);
  setCata(0);
}

void resetCata(){
  while(!cataLimit.get_value() && cataPressed == false) {
    setCata(-100);

  }
  setCata(0); 
  cataPressed = true;
}

void fireCata(){
  cataFor(0.5, -100);
  cataPressed = false;
}

void cataControl(void*){
  catapult.set_brake_mode(MOTOR_BRAKE_COAST);
  resetCata();
  while (true){
    if (master.get_digital(E_CONTROLLER_DIGITAL_L1)){
      fireCata();
      delay(600);
      resetCata();
    }
    delay(20);
  }
}
