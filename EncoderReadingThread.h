class EncoderReadingThread{
  public:
    int AInput = 6;
    int BInput = 7;

    void setInpus(int inputA, int inputB);
    void encoderSetup(void);
    int getEncoderSteps(void);

  private:  	
    int steps = 0;
    byte lastState = 0;    
    int  cw = 0;
    byte AState = 0;
    byte BState = 0;
    byte State = 0;
    void encoderValue(void);
}