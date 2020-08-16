#include <nuMROBO.h> //including nuMROBO library 


nuMROBO myRobo; //creating instance 'myRobo'

void setup() {
  // put your setup code here, which is used for initialization purpose & run once during starting:
  myRobo.activateIR();  //method to activate IR sensor module
  myRobo.activateMotors();  //method to initialize & setup motors
}

void loop() {
  // put your main code here, to run repeatedly:
  
  bool linePresent; //Declaring boolean variable 'linePresent' to store the distance from obstacle measured by IR sensor, which can store value in form of 'True' or 'False'

  linePresent = myRobo.blackLinePresent(); //checking if black line present by using IR sensor module and storing it into 'blackLinePresent' boolean variable in form of 'True' or 'False'

  if(linePresent){ 
    //if black line is present below IR sensor, move forward by sliding towards left side 
    myRobo.stopLeftMotor(); //Stop left side motor
    myRobo.rightMotorForward(100); //Move right motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100   
  }
  else{
    //if black line not present below IR sensor, move forward by sliding towards right side
    myRobo.stopRightMotor(); //Stop right side motor
    myRobo.leftMotorForward(100); //Move left motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100       
  }

}
