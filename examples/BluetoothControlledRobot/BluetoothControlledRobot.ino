#include <nuMROBO.h> //including nuMROBO library 


nuMROBO myRobo; //creating instance 'myRobo'

void setup() {
  // put your setup code here, which is used for initialization purpose & run once during starting:
  myRobo.activateBluetooth();  //method to activate bluetooth module
  myRobo.activateMotors();  //method to initialize & setup motors
}

void loop() {
  // put your main code here, to run repeatedly:
  
  String myMessage; //Declaring string variable 'myMessage' to store the incoming bluetooth message

  myMessage = myRobo.readBluetooth(); //Reading the input message from bluetooth, & assigning the received value to 'myMessage' string variable

  if(myMessage == "F"){ 
    //If message received from bluetooth is "F", move forward using following commands:
    myRobo.rightMotorForward(100); //Move right motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    myRobo.leftMotorForward(100); //Move left motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
  }
  else if (myMessage == "B"){
    //else if message received from bluetooth is "B", move backward using following commands:
    myRobo.rightMotorReverse(100); //Move right motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    myRobo.leftMotorReverse(100); //Move left motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
  }
  else if (myMessage == "R"){
    //else if message received from bluetooth is "R", rotate right using following commands:
    myRobo.rightMotorReverse(100); //Move right motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    myRobo.leftMotorForward(100); //Move left motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
  }
  else if (myMessage == "L"){
    //else if message received from bluetooth is "L", rotate left using following commands:
    myRobo.leftMotorReverse(100); //Move left motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
    myRobo.rightMotorForward(100); //Move right motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
  }
  else if (myMessage == "I"){
    //else if message received from bluetooth is "I", move forward right using following commands:
    myRobo.rightMotorForward(50); //Move right motor in forward direction at 50% speed, here '50' represent speed in %age you can choose desired value between 0-100
    myRobo.leftMotorForward(100); //Move left motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
  }
  else if (myMessage == "G"){
    //else if message received from bluetooth is "G", move forward left using following commands:
    myRobo.leftMotorForward(50); //Move left motor in forward direction at 50% speed, here '50' represent speed in %age you can choose desired value between 0-100
    myRobo.rightMotorForward(100); //Move right motor in forward direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
  }
  else if (myMessage == "J"){
    //else if message received from bluetooth is "J", move backward right using following commands:
    myRobo.rightMotorReverse(50); //Move right motor in reverse direction at 50% speed, here '50' represent speed in %age you can choose desired value between 0-100
    myRobo.leftMotorReverse(100); //Move left motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
  }
  else if (myMessage == "H"){
    //else if message received from bluetooth is "H", move backward left using following commands:
    myRobo.leftMotorReverse(50); //Move left motor in reverse direction at 50% speed, here '50' represent speed in %age you can choose desired value between 0-100
    myRobo.rightMotorReverse(100); //Move right motor in reverse direction at 100% speed, here '100' represent speed in %age you can choose desired value between 0-100
  }
  else if (myMessage =="S"){
    //else if message received from bluetooth is "S", stop all movements using following commands:
    myRobo.stopAllMotors(); //Stop all motors
  }

}
