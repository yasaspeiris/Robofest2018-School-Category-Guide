#define LPWM 5
#define RPWM 6
#define L1 4
#define L2 2
#define R1 8
#define R2 7


int sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7 = 0; //Use arrays to do this in an easier way
bool foundleft, foundright, foundend = 0;


#define BaseSpeed 100
#define Kp 40
#define Kd 70

int sensorpanelVal = 0;
int lastval = 0;


int error = 0;
int lasterror = 0;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ir_setup();
  motor_setup();



}

void loop() {
  // put your main code here, to run repeatedly:
  linefollow();
//  if (sensor6 == 1) {
//    foundright = 1;
//  }
//  if (sensor7 == 1) {
//    foundleft = 1;
//  }
//
//  if (foundleft || foundright) {
//    for (int i = 0; i < 50; i++) {
//      if (sensor6 == 1) {
//        foundright = 1;
//      }
//      if (sensor7 == 1) {
//        foundleft = 1;
//      }
//    }
//    setbrakes(255,255);
//    if(foundleft && foundright){
//      turn(150);
//    }else if(foundleft&& !foundright){
//      turn(150);
//    }else if(!foundleft&&foundright){
//      turn(-150);
//    }
//    foundleft = 0; foundright = 0; foundend = 0;
//  }
}
