
#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. 

//------ALL Pins DEFIN-------
const int OutputButtonPin = 8;
//const int InputButtonPin = 2;
const int LeftMotorForward = 4;
const int LeftMotorBackward = 5;
const int RightMotorForward = 3;
const int RightMotorBackward = 2;
int left_sensor = 7;
int right_sensor = 6;
 int a, b, c;
   int distanceRight = 0;
  int distanceLeft = 0;
#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

#define triger_pin A1 //analog input 1
#define echo_pin A2 //analog input 2
NewPing sonar(triger_pin, echo_pin, maximum_distance); //sensor function
Servo servoMotor; // servo name

//---------Pins DEclaration-
