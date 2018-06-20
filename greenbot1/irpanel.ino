void ir_setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(12, INPUT);
}


int readIRLine(){
  //from left to right. Sensor output is high when white space is detected. Since we're seeking a black line,inputs are inverted
  sensor1 = !digitalRead(A1);
  sensor2 = !digitalRead(A2);
  sensor3 = !digitalRead(A3);
  sensor4 = !digitalRead(A4);
  sensor5 = !digitalRead(A5);
  sensor6 = !digitalRead(12);
  sensor7 = !digitalRead(A0);



  int sum = 0;

  sensorpanelVal = (sensor1 * 1) + (sensor2 * 2) + (sensor3 * 3) + (sensor4 * 4) + (sensor5 * 5);
  sum = (sensor1 + sensor2 + sensor3 + sensor4 + sensor5);

  if (sum == 0) {
    return lastval;
  } else {

    lastval = sensorpanelVal / sum;
    return lastval;
  }
}

