#ifndef ENCODER_H
#define ENCODER_H

class EncoderReading{
    
  public:

    void encoderSetup(int inputA, int inputB);
    int getEncoderSteps(void);

  private: 

    int AInput = 6;
    int BInput = 7; 	
    int steps = 0;
    int lastState = 0;    
    int  cw = 0;
    int AState = 0;
    int BState = 0;
    int State = 0;
    void encoderValue(void);
};

#endif
