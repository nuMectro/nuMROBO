#include "nuMROBO.h"

#include <SoftwareSerial.h>

SoftwareSerial btModule(12,13); //RX, TX


nuMROBO::nuMROBO() { 
  //Anything you need when instatiating your object goes here
}


void nuMROBO::activateBluetooth() {
  //code for activate bluetooth
  btModule.begin(9600);
  
}

void nuMROBO::activateMotors() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
}

void nuMROBO::activateUltrasonic() {
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);
  
}

void nuMROBO::activateIR() {
  pinMode(7,INPUT);
  
}

String nuMROBO::readBluetooth() {
  String inputString = "";

  btModule.flush();
  
  if(btModule.available()){
    inputString = (char)btModule.read();
  }
    
  return inputString;
  
}

int nuMROBO::getDistance() {
  int timepls;
  int distance;
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  timepls = pulseIn(4,HIGH);
  distance = (timepls * 0.034) / 2;
  return distance;
  
}

bool nuMROBO::getIRStatus() {
  
  return digitalRead(7);
  
}

void nuMROBO::leftMotorForward(int speedVal) {
  int realSpeed;
  realSpeed = map(speedVal,0,100,0,255);
  analogWrite(10,realSpeed);
  digitalWrite(9,LOW);
  //change pin numbers if opposite rotation
  
}

void nuMROBO::leftMotorReverse(int speedVal) {
  int realSpeed;
  realSpeed = map(speedVal,0,100,0,255);
  analogWrite(9,realSpeed);
  digitalWrite(10,LOW);
  //change pin numbers if opposite rotation
  
}

void nuMROBO::rightMotorForward(int speedVal) {
  int realSpeed;
  realSpeed = map(speedVal,0,100,0,255);
  digitalWrite(6,LOW);
  analogWrite(5,realSpeed);
  //change pin numbers if opposite rotation
  
}

void nuMROBO::rightMotorReverse(int speedVal) {
  int realSpeed;
  realSpeed = map(speedVal,0,100,0,255);
  digitalWrite(5,LOW);
  analogWrite(6,realSpeed);
  //change pin numbers if opposite rotation
  
}

void nuMROBO::stopAllMotors() {
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  
}

void nuMROBO::stopLeftMotor() {
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  
}

void nuMROBO::stopRightMotor() {
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);

}

bool nuMROBO::blackLinePresent() {
  return !(digitalRead(7));
  
}

bool nuMROBO::whiteLinePresent() {
  return (digitalRead(7));
}
 
