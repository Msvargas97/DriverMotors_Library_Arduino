#ifndef _DRIVERMOTORS_H
#define _DRIERMOTORS_H

/*Libreria creada para el uso de driver para motores 

V 2.0

Autor: Michael Vargas
1/04/2016
*/

#define SHORT_BRAKE	true
#define OFF_HIGH_IMPEDANCE	false
class DriverMotors{
  public: 
DriverMotors(unsigned char *pinsPWM,unsigned char *pinsControl,bool _brake=SHORT_BRAKE,unsigned char numMotors = 1); //Constructor dos motores modo 3 pines
		 DriverMotors(unsigned char *pinsControl,bool _brake=SHORT_BRAKE,unsigned char numMotors = 1); //Constructor dos motores modo 2 pines
		 void setSpeed(int speed,unsigned char motor=1); //Control de velocidad independiente para cada motor
         //Funciones para asignar la velocidad cuando son dos tipos de motores
		 void setSpeedLeft(int speed); 
         void setSpeedRight(int speed);
         void setSpeeds(int left,int right);
		 //Frenos
         void ShortBrake(); //Freno a VCC	
         void Stop(); //Freno a GND
		 void StopMode(bool newValue); //Cambia el tipo de freno aplicado
		 int version(void);

  private:
  unsigned char numPinsPWM,numPinsControl;
  unsigned char *_pinsPWM,*_pinsControl;
  unsigned char mode;
  bool brake;
  unsigned char i;


};

#endif

