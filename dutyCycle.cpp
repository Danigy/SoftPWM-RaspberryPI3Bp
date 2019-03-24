#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include <iostream>
#include <ctime>

#define PINOUT 1
#define PININ 2
#define RANGE 1024
#define CLOCK 192

using namespace std;

bool risingIndi = false;
float duty = 0;
int highCounter = 0;

void risingCounterInterrupt (void)
{ 
	risingIndi = true;
}

void dutyCycle (void)
{
	while (true)
	{	
		highCounter = 0;		
		if(risingIndi)
		{
			clock_t start = clock();
			for(int stop = 0; stop<RANGE; stop++ )
				if(digitalRead(PININ) == 1)					
					highCounter++;
			clock_t end = clock();
					
			duty = (float)highCounter/(float)RANGE*100;
			risingIndi = false;
			
			//printf("\033[2J\033[1;1H");			
			printf("%d    ",highCounter);
			printf("%3.3f    ",duty);
			cout << (double)(end-start)/CLOCKS_PER_SEC << endl;
			
			delayMicroseconds(1000);			
		}
		usleep(500);
	}
}

int main(void)
{
	wiringPiSetup();
	wiringPiISR(PININ, INT_EDGE_RISING, risingCounterInterrupt);	
	pinMode(PININ,INPUT);
	thread cycleLength_t (dutyCycle);
	cycleLength_t.joinable();
	int f;
	cin >> f;
	
}
	
