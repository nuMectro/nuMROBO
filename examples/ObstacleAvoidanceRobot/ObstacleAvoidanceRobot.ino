#include <nuMROBO.h> //including nuMROBO library 


nuMROBO myRobo; //creating instance 'myRobo'

void setup() {
  // put your setup code here, which is used for initialization purpose & run once during starting:
  myRobo.activateUltrasonic();  //method to activate ultrasonic sensor module
  myRobo.activateMotors();  //method to initialize & setup motors
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int distance; //Declaring integer variable 'distance' to store the distance from obstacle measured by ultrasonic sensor

  distance = myRobo.getDistance(); //Reading the distance from obstacle measured by ultrasonic sensor module and storing it into 'distance' variable

  if(distance>15){ 
    //if distance from obstacle is greater than 15cm, move forward by using following commands:
    myRobo.leftMotorForward(100); //Move left motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    myRobo.rightMotorForward(100); //Move right motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100   
  }
  else if(distance<=15){
    //if distance from obstacle is less than or equal to 15cm move back for 1 second & then move left for 800 milli seconds, using following commands to avoid obstacle:
    
    //move back for 1 seconds, using following commands:
    myRobo.leftMotorReverse(100); //Move left motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    myRobo.rightMotorReverse(100); //Move right motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    delay(1000); //delay for 1 seconds, before executing further program
    myRobo.stopAllMotors(); //Stop all motors

    //rotate left for 800 milli seconds, using following commands:
    myRobo.leftMotorReverse(100); //Move left motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    myRobo.rightMotorForward(100); //Move right motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    delay(800); //delay for 800 milli seconds   
       
  }

}
