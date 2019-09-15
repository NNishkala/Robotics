#include "Arduino.h"
#include "DCMDriverL293D.h"
#define enableA  5
#define inputA1  2
#define inputA2  3
#define enableB  6
#define inputB1  4
#define inputB2  7
//DCMDriverL293D dcMotorDriverA(enableA,inputA1,inputA2,enableB,inputB1,inputB2);

#include <Servo.h>
int pos = 0;
int i = 0;
int j = 0;
Servo servo_8;
int counter;
Servo servo_9;

#include<SoftwareSerial.h>
SoftwareSerial bt(10,11); // assigning 10 as RX ans 11 as TX 

void setup() 
{
  servo_8.attach(8);
  servo_9.attach(9); 

  pinMode (enableA, OUTPUT);
  pinMode (inputA1, OUTPUT);
  pinMode (inputA2, OUTPUT);
  pinMode (enableB, OUTPUT);
  pinMode (inputB1, OUTPUT);
  pinMode (inputB2, OUTPUT); 

 while(!Serial){;} // waiting for serial communication to setup
 bt.begin(9600); // beginning the bluetooth connection
 Serial.begin(9600);
 Serial.println("Setup complete");
}

void loop() 
{
 bt.listen(); // listening to the bluetooth
 while(bt.available()) // till we are receiving the input continue in the loop
 {
    char co=bt.read();
    Serial.println(co);
    if(co=='f')
    {
      forward1();
    }
    else if(co=='b')
    {
      backward1();
    }
    else if(co=='l')
    {
      left1();
    }
    else if(co=='r')
    {
      right1();
    }
    else if(co=='d')
    {
      dip();
    }
    else
    {
      stop1();
    }
 }
}

void dip()
{
  for (i = 0; i <= 90; i += 1) {
    servo_8.write(i);delay(15);
  }
  Serial.println("Start");
  delay(300);
  for (counter = 0; counter < 10; ++counter) 
  {
    for (pos = 0; pos <= 60; pos += 1) 
    {
      servo_9.write(pos);
      delay(15); 
    }
    for (pos = 60; pos >= 0; pos -= 1) 
    {
      servo_9.write(pos);
      delay(15); 
    }
    //Serial.print("Dip:");Serial.println(counter);
  }
  for (i = 90; i >= 0; i -= 1) {
    servo_8.write(i);delay(15);
  }
  //Serial.println("stopped");
  while(1)
  {Serial.println(" ");}
}

void forward1()
{
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH); 
  delay (5);
  digitalWrite (inputA1, LOW);
  digitalWrite (inputA2, HIGH);
  digitalWrite (inputB1, LOW);
  digitalWrite (inputB2, HIGH);
  delay(150);
}

void backward1()
{
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH); 
  delay (5);
  digitalWrite (inputA1, HIGH);
  digitalWrite (inputA2, LOW);
  digitalWrite (inputB1, HIGH);
  digitalWrite (inputB2, LOW);
  delay(150);
}

void left1()
{
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, LOW); 
  delay (5);
  digitalWrite (inputA1, LOW);
  digitalWrite (inputA2, HIGH);
  delay(150);
}

void right1()
{
  digitalWrite (enableA, LOW);
  digitalWrite (enableB, HIGH); 
  delay (5);
  digitalWrite (inputB1, LOW);
  digitalWrite (inputB2, HIGH);
  delay(150);
}

void stop1()
{
  digitalWrite (enableA, LOW);
  digitalWrite (enableB, LOW);
}
