#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <cstdlib>
#include <iostream>
#include <thread>

#define PINA 28
#define PINB 29

using namespace std;

bool stop = false;

void loop()
{
	while(!stop)
	{	
		for(int i=0; i<5; i++)
		{		
			softPwmWrite(PINA, 100 - i*25);
			softPwmWrite(PINB, 0 + i*25);
			delay(2000);
		}
	}
}

int main(void)
{	
	thread first(loop);
	wiringPiSetup();		
	pinMode(PINA, OUTPUT);		
	pinMode(PINB, OUTPUT);		
	softPwmCreate(PINA, 0, 100);	
	softPwmCreate(PINB, 0, 100);
	
	first.joinable();
	cin.get();
	pinMode(PINA, INPUT);		
	pinMode(PINB, INPUT);
}	


