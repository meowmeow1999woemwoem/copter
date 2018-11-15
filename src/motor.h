#ifndef MotorController_h
#define MotorController_h
#include "Arduino.h"

class MotorController 
{

private:

    uint8_t resolution;
    int frequency;
    

	struct motor 
	{
		uint8_t pin;
		uint8_t channel;
	};

	void setMotorsParametrs(uint8_t* pins, uint8_t* channels);

public:

	motor* MotorRightForward;
	motor* MotorLeftForward;
    motor* MotorRightBack;
    motor* MotorLeftBack;

	void setup(uint8_t pins[4], uint8_t channels[4], uint8_t resolution, int frequency);

	void rotateMotor(motor* rotationMotor, int speed);
};
#endif