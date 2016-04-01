#include "DriverMotors.h"
#include "Arduino.h"
//Constructor de la clase
DriverMotors::DriverMotors(unsigned char pinsPWM[2],unsigned char pinsControl[4]){

for(i=0;i<6;i++){ //Asigna los pines como salidas
  if(i<2){
    pinMode(pinsPWM[i],OUTPUT);
    }
  else{pinMode(pinsControl[i-2],OUTPUT);
  _pinsControl[i-2] = pinsControl[i-2];
  }
}
pinPWMA = pinsPWM[0];
pinPWMB = pinsPWM[1];
}
//Controla la velocidad del motor izquierdo
void DriverMotors::setSpeedLeft(int speed){
  static bool reverse;
  reverse = false;
  if(speed < 0 ){
    reverse=true;
    speed = abs(speed);
  }
  if(!reverse){
    digitalWrite(_pinsControl[0],HIGH);
    digitalWrite(_pinsControl[1],LOW);
  }else{
    digitalWrite(_pinsControl[0],LOW);
    digitalWrite(_pinsControl[1],HIGH);
  }
  analogWrite(pinPWMA,speed);
}
//Controla velocidad motor derecho
void DriverMotors::setSpeedRight(int speed){
  static bool reverse;
  reverse = false;
  if(speed < 0 ){
    reverse=true;
    speed = abs(speed);
  }
  if(!reverse){
    digitalWrite(_pinsControl[2],HIGH);
    digitalWrite(_pinsControl[3],LOW);
  }else{
    digitalWrite(_pinsControl[2],LOW);
    digitalWrite(_pinsControl[3],HIGH);
  }
  analogWrite(pinPWMB,speed);
}
void DriverMotors::setSpeeds(int left,int right){
  setSpeedLeft(left);
  setSpeedRight(right);
}
void DriverMotors::Brake(){
  for(i=0;i<4;i++) digitalWrite(_pinsControl[i],HIGH);
  analogWrite(pinPWMA,255);
  analogWrite(pinPWMB,255);
}
void DriverMotors::Stop(){
  for(i=0;i<4;i++) digitalWrite(_pinsControl[i],LOW);
  analogWrite(pinPWMA,0);
  analogWrite(pinPWMB,0);
}

