/*Ejemplo para el uso de la libreria Driver Motors */
#include <DriverMotors.h>
                        //PWM pins           //Control pin    INA INB...
DriverMotors motors((unsigned char []){9,10},(unsigned char []){8 ,6 ,5 ,13});

void setup() {

}

void loop() {
  for(int i=-255;i<256;i+=10){
  motors.setSpeeds(i,i); //Da reversa y luego gira los motores hacia adelante
  // o tambien se puede usar los motores por separado
 // motors.setSpeedLeft(i);
  //motors.setSpeedRight(i):
  delay(200);
  }
  //Frenos
  motors.Brake(); //Deja girando libre los motores 
  delay(2000);
  motors.Stop();
  delay(500);
}