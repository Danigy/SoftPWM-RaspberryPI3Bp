#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define PIN 29
int main(void)
{
	wiringPiSetup();		
	pinMode(PIN, OUTPUT);		
	softPwmCreate(PIN, 0, 100);		
	softPwmWrite(PIN, 100);
	while(true)
	delay(1000);
}
