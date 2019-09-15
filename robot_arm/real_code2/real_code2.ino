#include <Servo.h>

int pos = 0;

int i = 0;

int j = 0;

Servo servo_8;

int counter;

Servo servo_9;

void setup()
{
  servo_8.attach(8);
  servo_9.attach(9);
  Serial.begin(9600);

}

void loop()
{
  for (i = 0; i <= 90; i += 1) {
    servo_8.write(i);delay(15);
  }
  Serial.println("Start");
  delay(300);
  for (counter = 0; counter < 10; ++counter) {
    for (pos = 0; pos <= 60; pos += 1) {
      // tell servo to go to position in variable 'pos'
      servo_9.write(pos);
      // wait 15 ms for servo to reach the position
      delay(15); // Wait for 15 millisecond(s)
    }
    for (pos = 60; pos >= 0; pos -= 1) {
      // tell servo to go to position in variable 'pos'
      servo_9.write(pos);
      // wait 15 ms for servo to reach the position
      delay(15); // Wait for 15 millisecond(s)
    }
    Serial.print("Dip:");Serial.println(counter);
  }
  for (i = 90; i >= 0; i -= 1) {
    servo_8.write(i);delay(15);
  }
  while(1)
  {Serial.println("stopped");}
}
