int lmt1=10;
int lmt2=11;//slow rigtht
int rmt1=7;
int rmt2=8;
int ls=4;
int cs=6;
int rs=5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lmt1,OUTPUT);
  pinMode(lmt2,OUTPUT);
  pinMode(rmt1,OUTPUT);
  pinMode(rmt2,OUTPUT);
  pinMode(ls,INPUT);
  pinMode(rs,INPUT);
  pinMode(cs,INPUT);
  

}

void forward()
{
  for(int i=0;i<20000;i++){
  analogWrite(lmt1,0);
  analogWrite(lmt2,255);
  analogWrite(rmt1,0);
  analogWrite(rmt2,130);
  }
  delay(100);
}

void reverse()
{
  for(int i=0;i<15000;i++){
  analogWrite(lmt1,255);
  analogWrite(lmt2,0);
  analogWrite(rmt1,0);
  analogWrite(rmt2,255);
  }
  delay(100);
}
void rightturn(){

  for(int i=0;i<5000;i++){
  analogWrite(lmt1,255);
  analogWrite(lmt2,0);
  analogWrite(rmt1,0);
  analogWrite(rmt2,0);
  }
  delay(100);
}

void leftturn(){
  for(int i=0;i<5000;i++){
  analogWrite(lmt1,0);
  analogWrite(lmt2,255);
  analogWrite(rmt1,0);
  analogWrite(rmt2,0);
  }
  delay(100);
}
void rest(){
  analogWrite(lmt1,0);
  analogWrite(lmt2,0);
  analogWrite(rmt1,0);
  analogWrite(rmt2,0);
}
void loop(){
  int Sensorleft=digitalRead(ls);
  int Sensorcenter=digitalRead(cs);
  int Sensorright=digitalRead(rs);
//  forward();
//  if(Sensorleft==1)
//  Serial.println("left");
//  if(Sensorright==1)
//    Serial.println("right");
//  if(Sensorcenter==1)
//    Serial.println("center");
//  Serial.println("left: "+Sensorleft);
//  Serial.println("right: "+Sensorright);
 // Serial.println("center: "+Sensorcenter);
  // forward();

  if(Sensorleft==1){
  Serial.println("left");
    //rightturn();
    leftturn();
    //delay(100);
   }

 else if(Sensorright==1){
 Serial.println("right");
  rightturn();
  //delay(100);
  }
    else if(Sensorright==1 && Sensorleft==1)
  {
   Serial.println("Back");
    reverse();
    //delay(100);
  }
  else if(Sensorcenter==1){
  Serial.println("center");
  forward();
  //delay(100);
  }  
  else
    rest();
  }
