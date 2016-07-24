#include <stdlib.h>
#include "DriverMotors.h"
#include <Arduino.h>

//Constructor de la clase para modo 3 pines
DriverMotors::DriverMotors(unsigned char *pinsPWM,unsigned char *pinsControl,bool _brake,unsigned char numMotors){
mode = 3;
numPinsPWM = numMotors;
numPinsControl= 2*numMotors;
brake = _brake;
//Asigna la memoria RAM
     _pinsPWM = (unsigned char*)malloc(sizeof(unsigned char)*numPinsPWM);
	 _pinsControl = (unsigned char*)malloc(sizeof(unsigned char)*numPinsControl);
     if (_pinsPWM == 0 || _pinsControl == 0)  //Si no hay suficiente memoria retorna
     return;
for(i=0;i<(numPinsControl+numPinsPWM);i++){ //Asigna los pines como salidas
  if(i<numPinsPWM){
	_pinsPWM[i] = pinsPWM[i];
    pinMode(_pinsPWM[i],OUTPUT);
    }
  else{
  _pinsControl[i-numPinsPWM] = pinsControl[i-numPinsPWM];
  pinMode(_pinsControl[i-numPinsPWM],OUTPUT);
  }
}
DriverMotors::ShortBrake();
}
DriverMotors::DriverMotors(unsigned char *pinsControl,bool _brake,unsigned char numMotors){
mode = 2;
numPinsControl= 2*numMotors;
brake = _brake;
//Asigna la memoria RAM
	 _pinsControl = (unsigned char*)malloc(sizeof(unsigned char)*numPinsControl);
     if (_pinsControl == 0) //Si no hay suficiente memoria retorna
     return;
for(i=0;i < numPinsControl;i++){ //Asigna los pines como salidas
  _pinsControl[i] = pinsControl[i];
  pinMode(_pinsControl[i],OUTPUT);
  }
 DriverMotors::ShortBrake();
}
void DriverMotors::setSpeed(int speed,unsigned char motor){
  static bool reverse;
  reverse = false;
  if(speed == 0 && motor == 1){
	 if(brake==SHORT_BRAKE){
     DriverMotors::ShortBrake();
	 }else{
	 DriverMotors::Stop();
	 }
  }else{
  if(motor == 1) motor = motor - 1;
  if(speed < 0 ){
    reverse=true;
    speed = abs(speed);
  }
  if(!reverse){
	digitalWrite(_pinsControl[motor],LOW);
	if(mode==3) digitalWrite(_pinsControl[motor+1],HIGH);
	else analogWrite(_pinsControl[motor+1],speed);
  }else{
	digitalWrite(_pinsControl[motor+1],LOW);
	if(mode==3)  digitalWrite(_pinsControl[motor],HIGH);
    else analogWrite(_pinsControl[motor],speed);
  }
  if(motor > 0) motor = motor - 1;
  if(mode==3)  analogWrite(_pinsPWM[motor],speed);
  }
}
//Controla la velocidad del motor izquierdo
void DriverMotors::setSpeedLeft(int speed){
  static bool reverse;
  reverse = false;
   if(speed == 0){
	  if(brake==SHORT_BRAKE){
     digitalWrite(_pinsControl[0],HIGH);
     digitalWrite(_pinsControl[1],HIGH);
	 }else{
	 digitalWrite(_pinsControl[0],LOW);
     digitalWrite(_pinsControl[1],LOW);
	 if(mode==3) digitalWrite(_pinsPWM[0],HIGH);
	 }
  }else{
  if(speed < 0 ){
    reverse=true;
    speed = abs(speed);
  }
  if(!reverse){
	digitalWrite(_pinsControl[1],LOW);
	if(mode==3) digitalWrite(_pinsControl[0],HIGH);
	else analogWrite(_pinsControl[0],speed);
  }else{
	digitalWrite(_pinsControl[0],LOW);
	if(mode==3)  digitalWrite(_pinsControl[1],HIGH);
    else analogWrite(_pinsControl[1],speed);
  }
 if(mode==3)  analogWrite(_pinsPWM[0],speed);
  }
}
//Controla velocidad motor derecho
void DriverMotors::setSpeedRight(int speed){
  static bool reverse;
  reverse = false;
  if(speed == 0){
	  if(brake==SHORT_BRAKE){
     digitalWrite(_pinsControl[2],HIGH);
     digitalWrite(_pinsControl[3],HIGH);
	 }else{
	 digitalWrite(_pinsControl[2],LOW);
     digitalWrite(_pinsControl[3],LOW);
	 if(mode==3) digitalWrite(_pinsPWM[1],1);
	 }
  }else{
  if(speed < 0 ){
    reverse=true;
    speed = abs(speed);
  }
  if(!reverse){
     if(mode==3) digitalWrite(_pinsControl[2],HIGH);
	 else analogWrite(_pinsControl[2],speed);
    digitalWrite(_pinsControl[3],LOW);
  }else{
    digitalWrite(_pinsControl[2],LOW);
     if(mode==3) digitalWrite(_pinsControl[3],HIGH);
	 else analogWrite(_pinsControl[3],speed);
  }
  if(mode==3) analogWrite(_pinsPWM[1],speed);
  }
}
void DriverMotors::setSpeeds(int left,int right){
  setSpeedLeft(left);
  setSpeedRight(right);
}
void DriverMotors::ShortBrake(){
  for(i=0;i < numPinsControl; i++) digitalWrite(_pinsControl[i],HIGH);
  if(mode == 3) {
  digitalWrite(_pinsPWM[0],1);
  digitalWrite(_pinsPWM[1],1);
  }
}
void DriverMotors::Stop(){
  for(i=0;i<numPinsControl;i++) digitalWrite(_pinsControl[i],LOW);
   if(mode == 3) {
  digitalWrite(_pinsPWM[0],0);
  digitalWrite(_pinsPWM[1],0);
   }
}
void DriverMotors::StopMode(bool newValue){
	brake = newValue;
}
/*
  version() returns the version of the library:
*/
int DriverMotors::version(void)
{
  return 1;
}
