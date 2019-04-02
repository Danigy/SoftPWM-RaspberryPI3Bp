#include "EncoderReading.h"

#include <stdio.h>
#include <pthread.h>
#include <wiringPi.h>
#include <unistd.h>
#include <iostream>

using namespace EncoderReading;

void EncoderReading::setInputs(int inputA, int inputB){
  AInput = inputA;
  BInput = inputB;
}

void EncoderReading::encoderSetup() {
  wiringPiSetup();
  //wiringPiISR(AInput, INT_EDGE_RISING, interrupt);
  //wiringPiISR(BInput, INT_EDGE_RISING, interrupt);
  pinMode(AInput, INPUT);
  pinMode(BInput, INPUT);

  pthread_t encoderRead_t;
  cout<< "ecoderSetup() : Creating encoderRead thread" << endl;
  er_t = pthread_create(&encoderRead_t, NULL, encoderValue, (void));
  if(er_t){
  	cout<< "Error : unable to create thread, " << er_t << endl;
  }
}
 
static void *EncoderReading::encoderValue(void) {
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
  return NULL;
}

int EncoderReading::getEncoderSteps(){
	return steps;
}