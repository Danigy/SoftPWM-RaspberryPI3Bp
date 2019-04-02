#include <stdio.h>
#include <wiringPi.h>
#include "EncoderReading.h"


const int pwmpinA = 1;
const int pwmpinB = 23;

int main(void){
	wiringPiSetup();
	pinMode(pwmpinA,PWM_OUTPUT);
	pinMode(pwmpinB,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(1920);
	pwmSetRange(100);
	EncoderReading.setInput(2, 3);
	EncoderReading.encoderSetup();
	
	while(true)
	{
		pwmWrite(pwmpinA,50);
		pwmWrite(pwmpinB,50);
		
		delayMicroseconds(1000000);
		printf("%d", EncoderReading.getEncoderSteps());
		
		pwmWrite(pwmpinA, 0);
		pwmWrite(pwmpinB, 0);
		
		delayMicroseconds(1000000);
		printf("%d", EncoderReading.getEncoderSteps());
		
		pwmWrite(pwmpinB,50);
		pwmWrite(pwmpinA,50);
		
		delayMicroseconds(1000000);
		printf("%d", EncoderReading.getEncoderSteps());
		
		pwmWrite(pwmpinB, 0);
		pwmWrite(pwmpinA, 0);
		
		delayMicroseconds(1000000);
		printf("%d", (EncoderReading.getEncoderSteps()));
	}
}
