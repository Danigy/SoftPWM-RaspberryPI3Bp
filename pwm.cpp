#include <stdio.h>
#include <wiringPi.h>

const int pwmpinAf = 1;
const int pwmpinBf = 23;
const int pwmpinAb = 24;
const int pwmpinBb = 26;


void movingMotor(int fwSpeedA, int fwSpeedB, int bwSpeedA, int bwSpeedB) // judinam motor paduodami srove skirtingais pinais.
{
		pwmWrite(pwmpinAb,fwSpeedA);
		pwmWrite(pwmpinBb,fwSpeedB);
		pwmWrite(pwmpinAf,bwSpeedA);
		pwmWrite(pwmpinBf,bwSpeedB);
}

int main(void){
	wiringPiSetup();
	pinMode(pwmpinAf,PWM_OUTPUT);
	pinMode(pwmpinBf,PWM_OUTPUT);
	pinMode(pwmpinAb,PWM_OUTPUT);
	pinMode(pwmpinBb,PWM_OUTPUT);
	//pwmSetMode(PWM_MODE_MS); - normaliai naudojamas Balanced rezimas, kuris isskirsto mazesniais impulsais, bet 2x dazniau.

	pwmSetClock(1920); // Ciklo daaznis = (19.2/Divisor)/Range
	pwmSetRange(100);
	
	while(true)
	{
		//------------forward 50%----------
		movingMotor(50, 50, 0, 0); // movingMotor(fwA, fwB, bwA, bwB)
		
		delayMicroseconds(1000000);

		//------------backward 50%----------
		movingMotor(0, 0, 50, 50);
		
		delayMicroseconds(1000000);	

 		//--------------break--------------
        movingMotor(0, 0, 0, 0);

	}
}


