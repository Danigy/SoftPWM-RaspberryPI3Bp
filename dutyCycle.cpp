#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

#define PINOUT 1
#define PININ 2
#define RANGE 1024

int i = 0;
int u = 0;
int z = 1;
float debilizmas = 0;
float duty =0;
	
int main(void)
{
	wiringPiSetup();
	pinMode(PINOUT,PWM_OUTPUT);	
	pinMode(PININ,INPUT);
	pwmSetRange(RANGE);
	pwmWrite(PINOUT,200);
	
	while(true)
	{
		//system("CLS");
		i = 0;
		u = 0;
		for(int stop = 0; stop<RANGE; stop++ )
		{
			if(digitalRead(PININ) == 1)
				i++;
			else
				u++;		
		}
		debilizmas +=i;
		duty = debilizmas/z;
		duty =(duty/(RANGE)*100);
		printf("\033[2J\033[1;1H");
		printf("%3.3f",duty);
		printf("   %d\n",i);
		z++;
	}
}
	