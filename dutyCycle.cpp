#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

#define PINOUT 1
#define PININ 2
#define RANGE 1024
#define CLOCK 2

int i = 0;
int u = 0;
int z = 1;
float sign = 0;
float duty =0;

void dutyCycle()
{
	duty = 0;
	i = 0;
	u = 0;
	for(int stop = 0; stop<RANGE; stop++ )
	{
		if(digitalRead(PININ) == 1)
			i++;	
	}
	sign +=i;
	duty = sign/z;
	duty =(duty/(RANGE)*100);
	printf("\033[2J\033[1;1H");
	printf("%3.3f",duty);
	printf("   %d\n",i);
	z++;
}
	
int main(void)
{
	wiringPiSetup();
	pinMode(PINOUT,PWM_OUTPUT);	
	pinMode(PININ,INPUT);
	pwmSetClock(CLOCK);
	//pwmSetRange(RANGE);
	pwmWrite(PINOUT,200);
	
	while(true)
	{
		int edge = wiringPIISR(PININ, INT_EDGE_RISING, dutyCycle);		
	}
}
	
