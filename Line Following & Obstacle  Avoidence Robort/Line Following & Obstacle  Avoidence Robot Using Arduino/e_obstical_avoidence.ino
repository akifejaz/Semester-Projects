

void runObsticalAvoidence()
{
//  ----------------------------------
  if (distance <= 50)
  {
    moveStop();
    delay(300);
    moveBackward();
    delay(100);
    moveStop();
    delay(100);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distanceLeft <= distance  )
    {
      turnRight();
      moveStop();
    }
    else
    {
      turnLeft();
      moveStop();
    }
  }
  else
  {
    moveForward();
  }
  distance = readPing();
}
