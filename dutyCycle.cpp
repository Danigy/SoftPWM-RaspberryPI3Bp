#include <stdio.h>
#include <wiringPi.h>

#define PINOUT 1
#define PININ 2

int main(void)
{
	wiringPiSetup();
	pinMode(PINOUT,PWM_OUTPUT);	
	pinMode(PININ,INPUT);
	
	pwmWrite(PINOUT,1024);
	int i = 0;
	int u = 0;
	for(int stop = 0; stop<1024; stop++ )
	{
		if(digitalRead(PININ) == 1)
			i++;
		else
			u++;		
	}
	printf("%d\n", i);
}
	
