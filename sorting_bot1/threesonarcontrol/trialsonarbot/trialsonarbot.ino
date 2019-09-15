/*The robot consists of three ultrasonic sensors. The problem is it is unable to sense the object in front.*/
#include "Arduino.h"
#include "DCMDriverL293D.h"

int trigc=9;
int echoc=8;
int trigl=13;
int echol=12;
int trigr=11;
int echor=10;

#define DCMOTORDRIVER_PIN_ENABLE1  2
#define DCMOTORDRIVER_PIN_IN1 4
#define DCMOTORDRIVER_PIN_IN2 5
#define DCMOTORDRIVER_PIN_ENABLE2 3
#define DCMOTORDRIVER_PIN_IN3 6
#define DCMOTORDRIVER_PIN_IN4 7

DCMDriverL293D dcMotorDriver(DCMOTORDRIVER_PIN_ENABLE1,DCMOTORDRIVER_PIN_IN1,DCMOTORDRIVER_PIN_IN2,DCMOTORDRIVER_PIN_ENABLE2,DCMOTORDRIVER_PIN_IN3,DCMOTORDRIVER_PIN_IN4);

void setup() {
  pinMode(trigc,OUTPUT);
  pinMode(echoc,INPUT);
  pinMode(trigl,OUTPUT);
  pinMode(echol,INPUT);
  pinMode(trigr,OUTPUT);
  pinMode(echor,INPUT);
}

int sonarcenter()
{
  long durationc, Cmc;
  digitalWrite (trigc,LOW);
  delayMicroseconds(2);
  digitalWrite(trigc,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigc,LOW);
  
  durationc=pulseIn(echoc,HIGH);
  Cmc = microsecondsToCentimeters(durationc);
  return Cmc;
}

int sonarleft()
{
  long durationl, Cml;
  digitalWrite (trigl,LOW);
  delayMicroseconds(2);
  digitalWrite(trigl,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigl,LOW);
  
  durationl=pulseIn(echol,HIGH);
  Cml = microsecondsToCentimeters(durationl);
  return Cml;
}

int sonarright()
{
  long durationr, Cmr;
  digitalWrite (trigr,LOW);
  delayMicroseconds(2);
  digitalWrite(trigr,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigr,LOW);
  
  durationr=pulseIn(echor,HIGH);
  Cmr = microsecondsToCentimeters(durationr);
  return Cmr;
}

long microsecondsToCentimeters (long microseconds)
{
   return microseconds /29 /2;
}

void loop() 
{
  int distcenter=sonarcenter();
  delay(10);
  if (distcenter>=20)
  {
     dcMotorDriver.setMotorA(200,1);
     dcMotorDriver.setMotorB(200,0);
  }
  else
    {
        int distright = sonarright();
        delay(10);
        int distleft = sonarleft();
        delay(10);
        if (distright>=20)
        {
            dcMotorDriver.setMotorA(200,1);//The left motor should turn and not the right so as to turn right
            delay(5000);
            //dcMotorDriver.setMotorA(0,1);
            //dcMotorDriver.setMotorB(0,0);
        }
        else if (distleft>=20)
        {
            
            dcMotorDriver.setMotorB(200,0);//The right motor should turn and not the left so as to turn left
            delay(5000);
            //dcMotorDriver.setMotorA(0,1);
            //dcMotorDriver.setMotorB(0,0);
        }
        else
        {
            dcMotorDriver.stopMotors();
        }
   }
}
