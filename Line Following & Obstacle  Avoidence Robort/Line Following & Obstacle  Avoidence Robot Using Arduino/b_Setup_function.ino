

void setup() { //------------Setup------------------

  //-------Mode Declaration------
  servoMotor.attach(10); //our servo pin
  pinMode( left_sensor, INPUT );
  pinMode( right_sensor, INPUT );
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  //----------------
    servoMotor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100); 
  //-----
  
  // Declaration------Mode of pins--------------------

}
