#ifndef ENCODER_H
#define ENCODER_H

class EncoderReading{
    
  public:
    int AInput = 6;
    int BInput = 7;

    void setInputs(int inputA, int inputB);
    void encoderSetup(void);
    int getEncoderSteps(void);

  private:  	
    int steps = 0;
    int lastState = 0;    
    int  cw = 0;
    int AState = 0;
    int BState = 0;
    int State = 0;
    void encoderValue(void);
};

#endif
