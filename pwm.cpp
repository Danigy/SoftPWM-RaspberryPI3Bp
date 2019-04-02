#include <stdio.h>
#include <wiringPi.h>


const int pwmpinA = 1;
const int pwmpinB = 23;

int main(void){
	wiringPiSetup();
	pinMode(pwmpinA,PWM_OUTPUT);
	pinMode(pwmpinB,PWM_OUTPUT);
	while(1){
	pwmWrite(pwmpinB,0);
	pwmWrite(pwmpinA,1024);
	delay(2000);
	pwmWrite(pwmpinB,0);
	pwmWrite(pwmpinA,512);
	delay(2000);
	pwmWrite(pwmpinB,0);
	pwmWrite(pwmpinA,256);
	delay(2000);
	pwmWrite(pwmpinB,0);
	pwmWrite(pwmpinA,100);
	delay(2000);
	pwmWrite(pwmpinA,0);
	pwmWrite(pwmpinB,1024);
	delay(2000);
	pwmWrite(pwmpinA,0);
	pwmWrite(pwmpinB,512);
	delay(2000);
	pwmWrite(pwmpinA,0);
	pwmWrite(pwmpinB,256);
	delay(2000);
	pwmWrite(pwmpinA,0);
	pwmWrite(pwmpinB,100);
	delay(2000);
	}
}
