/*
  Sweep

  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

int pos = 0;

int i = 0;

int j = 0;

Servo servo_5;

Servo servo_3;

Servo servo_4;

void setup()
{
  servo_5.attach(5);

  servo_3.attach(3);

  servo_4.attach(4);

}

void loop()
{
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 60; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_5.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  for (pos = 60; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_5.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  for (i = 0; i <= 90; i += 1) {
    servo_3.write(i);
  }
  for (j = 0; j <= 60; j += 1) {
    servo_4.write(j);
  }
}
