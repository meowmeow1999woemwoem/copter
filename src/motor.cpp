#include "MotorController.h"                 
#include <SPI.h>                
#include "esp32-hal-ledc.h"  

void MotorController::setup(uint8_t pins[4], uint8_t channels[4], uint8_t resolutionSetup, int frequencySetup){

	MotorRightForward = new motor();
	MotorLeftForward = new motor();
    MotorRightBack = new motor();
    MotorLeftBack = new motor();

    MotorRightForward->pin =  pins[0];
	MotorLeftForward ->pin =  pins[1];
    MotorRightBack ->pin =  pins[2];
    MotorLeftBack ->pin =  pins[3];

    MotorRightForward ->channel = channels[0];
	MotorLeftForward ->channel = channels[1];
    MotorRightBack ->channel = channels[2];
    MotorLeftBack ->channel = channels[3];

    resolution = resolutionSetup;
    frequency = frequencySetup;

    ledcSetup(MotorRightForward->channel, frequency, resolution);
    ledcSetup(MotorLeftForward->channel, frequency, resolution);
    ledcSetup(MotorRightBack->channel, frequency, resolution);
    ledcSetup(MotorLeftBack->channel, frequency, resolution);

    ledcAttachPin(MotorRightForward->pin, MotorRightForward->channel );
    ledcAttachPin(MotorLeftForward->pin, MotorLeftForward->channel );
    ledcAttachPin(MotorRightBack->pin, MotorRightBack->channel );
    ledcAttachPin(MotorLeftBack->pin, MotorLeftBack->channel );
}
    speed=resolution*minspeed/maxspeed;


	void rotateMotor(motor* rotationMotor, int speed){

        uint8_t pwm = (2^resolution-1)*speed/maxspeed;
        ledcWrite(rotateMotor -> channel, pwm);
    
    }


