#ifndef nL
#define nL

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class nuMROBO {
  public:
    //public constructor
    nuMROBO();
    
    //public methods
    void activateBluetooth();  //method to activate bluetooth
    void activateMotors(); //method to activate base motors
    void activateUltrasonic(); //method to activate ultrasonic sensor
    void activateIR(); //method to activate IR sensor
    String readBluetooth(); //method to read serial bluetooth msg received
    int getDistance(); //method to get distance from ultrasonic sensor
    bool getIRStatus(); //method to get status of IR sensor
    void leftMotorForward(int speedVal=100); //method to run left motor in forward direction at a particular speed (speed entered in form of percentage between 0 to 100), default speed value 100 percent
    void leftMotorReverse(int speedVal=100); //method to run left motor in reverse direction at a particular speed (speed entered in form of percentage between 0 to 100), default speed value 100 percent
    void rightMotorForward(int speedVal=100); //method to run right motor in forward direction at a particular speed (speed entered in form of percentage between 0 to 100), default speed value 100 percent
    void rightMotorReverse(int speedVal=100); //method to run right motor in reverse direction at a particular speed (speed entered in form of percentage between 0 to 100), default speed value 100 percent
    void stopAllMotors(); //method to stop all motors
    void stopLeftMotor(); //method to stop left motor
    void stopRightMotor(); //method to stop right motor
    bool blackLinePresent(); //method to check if black line present in front of IR Sensor
    bool whiteLinePresent(); //method to check if white line present in front of IR Sensor



  private:
    //private methods & constructors
  
  
};
#endif
