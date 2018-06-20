void motor_setup(){
  pinMode(LPWM,OUTPUT);
  pinMode(RPWM,OUTPUT);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  
}


void setleftmotor(int lspeed){
  if(lspeed >0){
    if(lspeed>255){
      lspeed = 255;
    }
    digitalWrite(L1,HIGH);digitalWrite(L2,LOW);
    analogWrite(LPWM,lspeed);
  }else{
    if(lspeed <-255){
      lspeed = -255;
    }
    digitalWrite(L1,LOW);digitalWrite(L2,HIGH);
    analogWrite(LPWM,-lspeed);
  }
}



void setrightmotor(int rspeed){
  if(rspeed >0){
    if(rspeed>255){
      rspeed = 255;
    }
    digitalWrite(R1,HIGH);digitalWrite(R2,LOW);
    analogWrite(RPWM,rspeed);
  }else{
    if(rspeed <-255){
      rspeed = -255;
    }
    digitalWrite(R1,LOW);digitalWrite(R2,HIGH);
    analogWrite(RPWM,-rspeed);
  }
}


void setspeeds(int lspeed,int rspeed){
  setleftmotor(lspeed);
  setrightmotor(rspeed);
  
}

void setbrakes(int lbrake,int rbrake){
  digitalWrite(L1,LOW);digitalWrite(L2,LOW);
  analogWrite(LPWM,lbrake);
  digitalWrite(R1,LOW);digitalWrite(R2,LOW);
  analogWrite(RPWM,rbrake);
}

