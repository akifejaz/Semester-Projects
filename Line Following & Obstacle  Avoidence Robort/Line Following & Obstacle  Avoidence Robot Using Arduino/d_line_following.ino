

void LineFollowing()
  {
    
  a= digitalRead( left_sensor );
  b= digitalRead( right_sensor );

  if ( a==0 && b==0 )
  {
    analogWrite( LeftMotorForward, 150 );
    analogWrite( RightMotorForward, 150 );
  }

  if ( a==1 && b==1 )
  {
    analogWrite( LeftMotorForward, 0 );
    analogWrite( RightMotorForward, 0 );
  }

if ( a==1 && b==0 )
  {
    analogWrite( LeftMotorForward, 0 );
    analogWrite( RightMotorForward, 100 );
  }
  if ( a==0 && b==1 )
  {
    analogWrite( LeftMotorForward, 100);
    analogWrite( RightMotorForward, 0);
  }
  
 
  }
