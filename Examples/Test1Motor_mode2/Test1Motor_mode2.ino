#include <DriverMotors.h>

/*
  Ejemplo para el uso de la libreria Driver Motors Usando un solo motor y el modo 2 conexiones
  Powered by Michael Vargas © 2016

  More info about pin Modes conections:
  http://webbot.org.uk/WebbotLibDocs/42594.html

  (*)Stop mode:
  SHORT_BRAKE or OFF_HIGH_IMPEDANCE
  
  Cuando en la entrada de la funcion que asigna la velocidad al motor,
  su valor ingresado es igual a cero, activa el freno segun sea escogido ShortBrake o OFF(High-Impedance)
  Se puede cambiar el modo de frenado con la funcion StopMode():
  Ejemplo:
  motors.StopMode(SHORT_BRAKE);
*/

#define STOP_MODE	OFF_HIGH_IMPEDANCE


//Instanciar Objeto
                     //Control pin:   PWMA,PWMB
DriverMotors motors((unsigned char []) {9,10}, STOP_MODE);

void setup() {
  delay(2000);

}

void loop() {

  //Realiza un test al motor para observar su tiempo de respuesta en diferentes velocidades y con ambos tipos de freno
  //############## TEST SHORT_BRAKE ##########################
  for (int i = -255; i < 256; i += 5) {
    motors.setSpeed(i);//Da reversa y luego gira el motor hacia adelante
    delay(100);
  }
  motors.ShortBrake(); //Freno inmediato
  delay(2000); //Tiempo de espera para observar el frenado

  //############## TEST OFF(High-Impedance) ###################
  for (int i = -255; i < 256; i += 5) {
    motors.setSpeed(i); //Da reversa y luego gira el motor hacia adelante
    delay(100);
  }
  motors.Stop(); //Deja girando libre el motor
  delay(2000);//Tiempo de espera para observar el frenado
}