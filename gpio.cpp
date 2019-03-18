#include <stdio.h>
#include <wiringPi.h>


const int pwmpinA = 1;
const int pwmpinB = 23;

int main(void){
	wiringPiSetupGpio();
	pinMode(pwmpinA,PWM_OUTPUT);
	pinMode(pwmpinB,PWM_OUTPUT);
	pwmWrite(pwmpinA,512);
		pwmWrite(pwmpinB,1024);
	while(1){
		delay(1000);
	}
}

