void linefollow() {
  int val = readIRLine();
  error = 3 - val;
  int delta = error - lasterror;
  int change = Kp * error + Kd * delta;
  lasterror = error;

  int leftMotorPWM = BaseSpeed - change;
  //constrain PWM
  if (leftMotorPWM > 255) {
    leftMotorPWM = 255;
  } else if (leftMotorPWM < 0) {
    leftMotorPWM = 0;
  }
  //constrain PWM
  int rightMotorPWM = BaseSpeed + change;
  if (rightMotorPWM > 255) {
    rightMotorPWM = 255;
  } else if (leftMotorPWM < 0) {
    rightMotorPWM = 0;
  }

  Serial.println(leftMotorPWM);
  setspeeds(leftMotorPWM, rightMotorPWM);

}



void turn(int turnspeed) {
  int val = 0;
  if (turnspeed > 0) {
    setleftmotor(-turnspeed); setrightmotor(turnspeed);
    sensor1 = 0;
    while (sensor1 == 0) {
      val = readIRLine();
    }
    setbrakes(255, 255);
    delay(100);


  } else if (turnspeed < 0) {
    setleftmotor(-turnspeed); setrightmotor(turnspeed);
    sensor5 = 0;
    while (sensor5 == 0) {
      val = readIRLine();
    }
    setbrakes(255, 255);
    delay(100);
  }
}

