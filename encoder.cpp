#include <stdio.h>
#include <pthread.h>
#include <wiringPi.h>
#include <unistd.h>
#include <iostream>
using namespace std;

uint8_t AInput = 6;
uint8_t BInput = 7; 
uint8_t CInput = 0;
uint8_t DInput = 2; 
uint8_t Rsteps = 0;
uint8_t  RlastState = 0;  
uint8_t Lsteps = 0;
uint8_t  LlastState = 0;  
 uint8_t AState = 0;
 uint8_t BState = 0;
 uint8_t CState = 0;
 uint8_t DState = 0;
 uint8_t RState = 0;
 uint8_t LState = 0;

static int *encoderRunner(void *arg) { //EncoderReading::
  
  int sleepLength = *((int *) arg);
  free (arg);

  while(true)
  {    
    AState = digitalRead(AInput);
    BState = digitalRead(BInput) << 1;
    RState = AState | BState;
    
    CState = digitalRead(CInput);
    DState = digitalRead(DInput) << 1;
    LState = CState | DState;
    
    if (RlastState != RState){
      switch (RState) {
        case 0:
          if (RlastState == 2){
            Rsteps++;
          }
          else if(RlastState == 1){
            Rsteps--;
          }
          break;
        case 1:
          if (RlastState == 0){
            Rsteps++;
          }
          else if(RlastState == 3){
            Rsteps--;
          }
          break;
        case 2:
          if (RlastState == 3){
            Rsteps++;
          }
          else if(RlastState == 0){
            Rsteps--;
          }
          break;
        case 3:
          if (RlastState == 1){
            Rsteps++;
          }
          else if(RlastState == 2){
            Rsteps--;
          }
          break;
      }
    }
    if (LlastState != LState){
      switch (LState) {
        case 0:
          if (LlastState == 2){
            Lsteps++;
          }
          else if(LlastState == 1){
            Lsteps--;
          }
          break;
        case 1:
          if (LlastState == 0){
            Lsteps++;
          }
          else if(LlastState == 3){
            Lsteps--;
          }
          break;
        case 2:
          if (LlastState == 3){
            Lsteps++;
          }
          else if(LlastState == 0){
            Lsteps--;
          }
          break;
        case 3:
          if (LlastState == 1){
            Lsteps++;
          }
          else if(LlastState == 2){
            Lsteps--;
          }
          break;
      }
    }
    usleep(sleepLength);
    RlastState = RState;
    LlastState = LState;
    cout << (int)Lsteps<<"  "<<(int)Rsteps<<endl;
  }
  return NULL;
}

int main(){
	wiringPiSetup();
  pthread_t encoder_t;
  er_t = pthread_create(&encoder_t, NULL, encoderValue, (void* )sleepLength);

  if(er_t){
    cout<< "Error : unable to create thread, encoder thread " << er_t << endl;
  }
}
