#include <iostream>
#include <motor.h>
motor motorController;
void setup()
{
    Serial.begin (9600);
motorController.setup(pins[4], channels[4]); 
motorController.rotateMotor(channels[4], resolution, frequency);
}
void loop()
{
     for (int frequency = 0; frequency<= 255; frequency++) 
     {

     ledcWrite(channels[4], frequency);
     delay(7);
         
     }
 
  for (int frequency= 255; frequency >= 0; frequency--) {
    ledcWrite(channels[4], frequency);
    delay(7);
  }


}

