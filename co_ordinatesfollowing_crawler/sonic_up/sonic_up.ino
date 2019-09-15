//libraries
#include <Servo.h>
#include <Wire.h>

//declaration
Servo servo8;
Servo servo9;
Servo myservo;
int x=0;

void receiveEvent(int bytes) 
{x = Wire.read();}    // read one character from the I2C

void moveArm() 
{
  //top-b servo
  Serial.println("1");
  for(int pos=180;pos>=110;pos--)
  {
    servo9.write(pos);
    delay(15);
  }
  delay(3000);
  
  //top-b servo
  Serial.println("2");
  for (int pos = 110; pos <= 180; pos += 1) 
  { 
    servo9.write(pos);              
    delay(15);                       
  }
  delay(3000);

  //mag-servo
  for (int pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(100);
  
  //bottom-b servo
  Serial.println("3");
  for (int pos1 = 0; pos1 <= 90; pos1 += 1) 
  {
    servo8.write(pos1);              
    delay(15);      
  }
  delay(3000);
  
  //bottom-b servo
  Serial.println("4");
  for(int pos1=90;pos1>=0;pos1--)
  {
    servo8.write(pos1);
    delay(15);
  }
  delay(3000);
}

void setup()
{
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  
  Serial.begin(9600);
  servo8.attach(8);
  servo8.write(0);
  delay(3000);
  
  servo9.attach(9);
  servo9.write(180);
  delay(3000);

  myservo.attach(10);
  myservo.write(0);
  delay(3000);
  //servo8.write(0);
  //delay(3000);
  
  //servo9.write(180);
  //delay(3000);
  
  //servo8.write(0);
  //delay(3000);
}

void loop()
{
  Serial.println("Hello");
  if(x == '1')
  {
    Serial.println("world");moveArm();
  while(1)
  {
  }
  }
}
