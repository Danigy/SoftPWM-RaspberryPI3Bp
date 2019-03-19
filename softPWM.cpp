#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define PINA 28
#define PINB 29

int main(void)
{
	wiringPiSetup();		
	pinMode(PINA, OUTPUT);		
	pinMode(PINB, OUTPUT);		
	softPwmCreate(PINA, 0, 100);	
	softPwmCreate(PINB, 0, 100);
	
	while(true)
	{	
		for(int i=0; i<5; i++)
		{		
			softPwmWrite(PINA, 100 - i*25);
			softPwmWrite(PINB, 0 + i*25);
			delay(2000);
		}
	}
}
