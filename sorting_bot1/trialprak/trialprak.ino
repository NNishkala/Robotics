/*The robotic arm. It uses one ir sensor and one ultrasonic sensor to check if the is an object is placed on the robotic arm and the ir sensor checks the color. Depending on the color, the base servo motor will turn buy a certain angle*/

#include <Servo.h>

int obstaclePin1= A0; //This is down ir
int hasObstacle1 = HIGH;
int LED=13;
int echo=11;
int trig=10;

Servo servo_6;//base
Servo servo_7;//base-up
Servo servo_8;//tiny

void setup() 
{
  pinMode(LED, OUTPUT); 
  pinMode(obstaclePin1, INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  servo_6.attach(6);
  servo_7.attach(7);
  servo_8.attach(8);
  Serial.begin(9600);
}

long sonar()
{
  long duration, Cm;
  digitalWrite (trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duration=pulseIn(echo,HIGH);
  Cm = microsecondsToCentimeters(duration);
  return Cm;
}

long microsecondsToCentimeters (long microseconds)
{
  return microseconds /29 /2;
}


void loop() 
{
  delay(7000);
  hasObstacle1=digitalRead(obstaclePin1);
  delay(600);
  long so=sonar();
  delay(500);
  if(1)
  {
    if(hasObstacle1==1)
      {
        //black
        Serial.println("In if2");
        servo_6.write(60);
        delay(400);
        servo_7.write(60);
        delay(300);
        servo_8.write(45);
        delay(200);
        servo_8.write(0);
        delay(100);
        servo_7.write(0); 
        delay(100);
        servo_6.write(0);
        delay(100);      
      }
      else
      {
        Serial.println("In else2");
        servo_6.write(0);
        delay(400);
        servo_7.write(60);
        delay(300);
        servo_8.write(45);
        delay(200);
        servo_8.write(0);
        delay(100);
        servo_7.write(0);
        delay(100);
      }
  }
  else
  {
    Serial.println("Nothing to hold");
    servo_8.write(0);
    servo_6.write(0);
    servo_7.write(0);
    delay(1000);
  }
}
