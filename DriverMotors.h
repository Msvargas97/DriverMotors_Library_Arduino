#ifndef _DRIVERMOTORS_H
#define _DRIERMOTORS_H

/*Libreria creada para el uso de driver para motores 
Autor: Michael Vargas
1/04/2016
*/
class DriverMotors{
  public: 
         DriverMotors(unsigned char pinsPWM[2],unsigned char pinsControl[4]); //Constructor
         void setSpeedLeft(int speed);
         void setSpeedRight(int speed);
         void setSpeeds(int left,int right);
         void Brake();
         void Stop();

  private:
  unsigned char i;
  unsigned char pinPWMA,pinPWMB,_pinsControl[4];

};

#endif

