#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include <iostream>
#include <ctime>
#include <fstream>

#define PINOUT 1
#define PININ 2
#define RANGE 100
#define CLOCK 1920

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
	//fstream fs;
	//fs.open ("test.txt", fstream::out);
	while (true)
	{	
		
		highCounter = 0;		
		if(risingIndi)
		{
			//clock_t start = clock();
			for(int stop = 0; stop<RANGE; stop++ )
			{
				if(digitalRead(PININ) == 1)					
					highCounter++;
					
				usleep(100);
			}
			//clock_t end = clock();
					
			duty = (float)highCounter/(float)RANGE*100;
			risingIndi = false;
			
			//printf("\033[2J\033[1;1H");			
			//cout << highCounter;
			//printf("%3.3f    ",duty);
			//cout << (double)(end-start)/CLOCKS_PER_SEC << endl;
			
			//delayMicroseconds(19.2*1000000/CLOCK);
		}
		usleep(500);
	}	
	//fs.close();
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
	
