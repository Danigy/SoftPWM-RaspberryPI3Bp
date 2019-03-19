# SoftPWM-RaspberryPI3Bp
Wall following robot Raspberry PI 3 B+ 
# Software PWM method
It is possible to use any GPIO PIN with this method. 
When compiling and building you must include:

```bash
-lwiringPi -lpthread
```

# Hardware PWM method
4 PWM pins of which GPIO.1 and GPIO.22 values are equal to each other, aswell GPIO.23 and GPIO.24.
For compiling only needed:

```bash
-lwiringPi
```
Running program that uses hardware PWM method you might need to run from terminal:
```bash
sudo ./PROGRAMNAME
```

 