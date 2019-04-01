#include "EncoderReadingThread.h"

#include <stdio.h>
#include <thread>
#include <wiringPi.h>
#include <unistd.h>

using namespace EncoderReadingThread;

void setInputs(int inputA, int inputB){
  AInput = inputA;
  BInput = inputB;
}

void encoderSetup() {
  wiringPiSetup();
  //wiringPiISR(AInput, INT_EDGE_RISING, interrupt);
  //wiringPiISR(BInput, INT_EDGE_RISING, interrupt);
  pinMode(AInput, INPUT);
  pinMode(BInput, INPUT);

  thread encoderRead_t (encoderValue);
  encoderRead_t.detach();
}
 
void encoderValue() {
  // read the input pin:
  while(true)
  {
    AState = digitalRead(AInput);
    BState = digitalRead(BInput) << 1;
    State = AState | BState;
   
    if (lastState != State){
      switch (State) {
        case 0:
          if (lastState == 2){
            steps++;
            cw = 1;
          }
          else if(lastState == 1){
            steps--;
            cw = -1;
          }
          break;
        case 1:
          if (lastState == 0){
            steps++;
            cw = 1;
          }
          else if(lastState == 3){
            steps--;
            cw = -1;
          }
          break;
        case 2:
          if (lastState == 3){
            steps++;
            cw = 1;
          }
          else if(lastState == 0){
            steps--;
            cw = -1;
          }
          break;
        case 3:
          if (lastState == 1){
            steps++;
            cw = 1;
          }
          else if(lastState == 2){
            steps--;
            cw = -1;
          }
          break;
      }
    }
   
    lastState = State;
    usleep(10000);
  }
}

int getEncoderSteps(){
	return steps;
}