//speed of robot is 0.2335mps
//time taken for one rotation is 3.684
//time taken for one degree is 0.01023
//360deg-6.2832rad=3.684sec
//180deg-3.1416rad=1.842sec
//90deg-1.5708rad=0.921sec
//45deg-0.7854rad=0.4605sec

#include <math.h>
#include <Wire.h>
#include "Arduino.h"
#include "DCMDriverL293D.h"
#include "NewPing.h"

int enableA=  2;
int inputA1= 4;
int inputA2= 5;
int enableB= 3;
int inputB1= 6;
int inputB2= 7;
int x=0;
double refer_angle;
double speed1=23.35;
double rottime=0.01023;

double getDist(double x1,double x2,double y1,double y2)
{
  double d1=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
  double dist=sqrt(d1);
  return dist;
}
double getAngl(double x1,double x2,double y1,double y2)
{
  if(x1==x2 && y1>y2)
    return 270;
  else if(x1==x2 && y1<y2)
    return 90;
  else if(x1>x2 && y1==y2)
    return 180;
  else if(x1<x2 && y1==y2)
    return 0;
  else
  {
    double x=x1-x2;
    double y=y1-y2;
    double d=y/x;
    Serial.println(d);
    double aa=atan(d);
    double bb=(aa*180)/3.1415;
    if(x1<x2 && y1<y2)//first quad
      return bb;
    else if(x1>x2 && y1>y2)//third quad
      return 180+bb;
    else if(x1>x2 && y1<y2)//second quad
      return 180+bb;
    else if(x1<x2 && y1>y2)//fourth quad
      return 360+bb;
  }
}

void botMove(double gd)
{
  
  Serial.println("In bot move");
  double timing=(gd)/speed1;
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH); 
  delay (150);
  digitalWrite (inputA1, LOW);
  digitalWrite (inputA2, HIGH);
  digitalWrite (inputB1, LOW);
  digitalWrite (inputB2, HIGH);
  delay(timing*1000);
  Serial.println("Done with botmove");
}
void botTurn(double ga)
{
  Serial.println("In bot turn");
  double turnby=refer_angle-ga;
  Serial.print("Turned by:");
  Serial.println(turnby);
  double timing=turnby*rottime;
  Serial.print("before Reference angle:");
  Serial.println(refer_angle);
  //Serial.println(timing);
  if(timing<0)
    timing=(-1)*timing;
  if(turnby<0)
    turnby=(-1)*turnby;
  if((ga>=refer_angle && ga<=(refer_angle+180)))
  {
    if(turnby>180)
    {
      double turnby1=180-ga;
      double timing1=turnby*rottime;
      Serial.print("Actual turn by");
      Serial.println(turnby1);
      Serial.println("Turned left1");
      digitalWrite (enableA, HIGH);
      digitalWrite (enableB, LOW); 
      delay (150);
      digitalWrite (inputA1, LOW);
      digitalWrite (inputA2, HIGH);//The right motor should turn and not the left so as to turn left
      delay(timing1*1000);
    }
    else
    {
      Serial.println("Turned left");
      digitalWrite (enableA, HIGH);
      digitalWrite (enableB, LOW); 
      delay (150);
      digitalWrite (inputA1, LOW);
      digitalWrite (inputA2, HIGH);//The left motor should turn and not the right so as to turn right
      delay(timing*1000);
    }
  }
  else
  {
    if(turnby>180 and refer_angle<=180)
    {
      double turnby1=360-turnby;
      double timing1=turnby1*rottime;
      Serial.print("Actual turn by");
      Serial.println(turnby1);
      Serial.println("Turned right1");
      digitalWrite (enableA, LOW);
      digitalWrite (enableB, HIGH); 
      delay (150);
      digitalWrite (inputB1, LOW);
      digitalWrite (inputB2, HIGH);//The right motor should turn and not the left so as to turn left
      delay(timing1*1000);
    }
    else if(turnby>180 and refer_angle>180)
    {
      double turnby1=360-turnby;
      double timing1=turnby1*rottime;
      Serial.print("Actual turn by");
      Serial.println(turnby1);
      Serial.println("Turned left2");
      digitalWrite (enableA, HIGH);
      digitalWrite (enableB, LOW); 
      delay (150);
      digitalWrite (inputA1, LOW);
      digitalWrite (inputA2, HIGH);//The right motor should turn and not the left so as to turn left
      delay(timing1*1000);
    }
    else
    {
      Serial.println("Turned right");
      digitalWrite (enableA, LOW);
      digitalWrite (enableB, HIGH); 
      delay (150);
      digitalWrite (inputB1, LOW);
      digitalWrite (inputB2, HIGH);//The right motor should turn and not the left so as to turn left
      delay(timing*1000);
    }
  }
  refer_angle=ga;
  Serial.print("current Reference angle:");
  Serial.println(refer_angle);
}

void transmit()
{
  Serial.println("in transmit");
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(1);              // sends x 
  Wire.endTransmission();    // stop transmitting
}
void control(double x1,double x2,double y1,double y2)
{
  double gd=getDist(x1,x2,y1,y2);
  double ga=getAngl(x1,x2,y1,y2);
  Serial.print("Dist:");
  Serial.println(gd);
  Serial.print("Angle:");
  Serial.println(ga);
  botTurn(ga);
  digitalWrite (enableA, LOW);
  digitalWrite (enableB, LOW);
  botMove(gd);
  digitalWrite (enableA, LOW);
  digitalWrite (enableB, LOW);
  Serial.println();
}
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  pinMode (enableA, OUTPUT);
  pinMode (inputA1, OUTPUT);
  pinMode (inputA2, OUTPUT);
  pinMode (enableB, OUTPUT);
  pinMode (inputB1, OUTPUT);
  pinMode (inputB2, OUTPUT);
  Serial.println("Hello");
}
//{{0,0},{15,15},{30,15},{30,30},{40,30},{40,0},{50,50}}
//{{0,0},{-1,-1},{1,0},{0,1},{1,0}}
//{{0,0},{-1,1},{0,2},{1,1},{0,0}}
void loop()
{
  refer_angle=90;
  double co[][2]={{0,0},{15,15},{30,15},{30,30},{40,30},{40,0},{50,45}};
  int c=7;
  Serial.println(c);
for(int i=0;i<c-1;i++)
{
  double x1=co[i][0];
  double y1=co[i][1];
  double x2=co[i+1][0];
  double y2=co[i+1][1];
  Serial.print("x1:");
  Serial.println(x1);
  Serial.print("y1:");
  Serial.println(y1);
  Serial.print("x2:");
  Serial.println(x2);
  Serial.print("y2:");
  Serial.println(y2);
  control(x1,x2,y1,y2);
}
  while(1)
  {
    transmit();
  }
}
