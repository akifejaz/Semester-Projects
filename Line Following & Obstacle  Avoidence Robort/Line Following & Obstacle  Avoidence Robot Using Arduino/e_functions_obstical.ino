int readPing()
  {
    delay(70);
    int cm = sonar.ping_cm();
    if (cm == 0)
    {
      cm = 250;
    }
    return cm;
  }

int lookRight()

  {
    servoMotor.write(50);
    delay(500);
    int distance = readPing();
    delay(100);
    servoMotor.write(115);
    return distance;
  }

  int lookLeft() {
    servoMotor.write(170);
    delay(500);
    int distance = readPing();
    delay(100);
    servoMotor.write(115);
    return distance;
    delay(100);
  }

  void moveStop() {

    digitalWrite(RightMotorForward, LOW);
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(LeftMotorBackward, LOW);
  }

  void moveForward() {

    if (!goesForward) {

      goesForward = true;

      digitalWrite(LeftMotorForward, HIGH);
      digitalWrite(RightMotorForward, HIGH);

      digitalWrite(LeftMotorBackward, LOW);
      digitalWrite(RightMotorBackward, LOW);
    }
  }

  void moveBackward() {

    goesForward = false;

    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);

    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorForward, LOW);

  }

  void turnRight() {

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);

    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorForward, LOW);

    delay(500);

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);

    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);



  }

  void turnLeft() {

    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorForward, HIGH);

    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);

    delay(500);

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);

    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  }
  //------------
