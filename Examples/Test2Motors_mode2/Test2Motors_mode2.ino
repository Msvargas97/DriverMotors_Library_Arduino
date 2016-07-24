#include <DriverMotors.h>
/*

Ejemplo para el uso de la libreria Driver Motors  usando dos motores y el modo 2 conexiones
Powered by Michael Vargas © 2016

  More info about pin Modes conections:
  http://webbot.org.uk/WebbotLibDocs/42594.html

  (*)Stop mode:
  SHORT_BRAKE or OFF_STOP
  Cuando en la entrada de la funcion que asigna la velocidad al motor(es),
  su valor ingresado es igual a cero, activa el freno segun sea escogido ShortBrake o OFF(High-Impedance)
  Se puede cambiar el modo de frenado con la funcion StopMode():
  Ejemplo:
  motors.StopMode(SHORT_BRAKE);
*/

#define NUM_MOTORS 2 //Numero de motores a usar 
#define STOP_MODE SHORT_BRAKE //Tipo de freno aplicado cuando la velocidad sea igual a 0

//Instanciar Objetos
                                  //Control PWM pins - All pins must be PWM
DriverMotors motors((unsigned char []){9 ,10 ,13 ,5},STOP_MODE,NUM_MOTORS);

void setup() {
delay(2000);

}

void loop() {
  //Realiza un test al motor para observar su tiempo de respuesta en diferentes velocidades y con ambos tipos de freno
  //############## TEST SHORT_BRAKE ##########################
  for (int i = -255; i < 256; i += 5) {
    motors.setSpeeds(i,-i);//Giro sobre su propio eje
    /*
    //Tambien puede controlarse cada lado del motor independientemente con las funciones:
	motors.setSpeedRight(i);
	motors.setSpeedLeft(i);
	*/
    delay(100);
  }
  motors.ShortBrake(); //Freno inmediato
  delay(2000); //Tiempo de espera para observar el frenado

  //############## TEST OFF(High-Impedance) ###################
  for (int i = -255; i < 256; i += 5) {
    motors.setSpeeds(i,-i);//Giro sobre su propio eje
    delay(100);
  }
  motors.Stop(); //Deja girando libre el motor
  delay(2000);//Tiempo de espera para observar el frenado
}