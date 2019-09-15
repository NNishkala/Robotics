/*     Arduino Project - Color Sorting Machine
 *
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *
 */
#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

Servo topServo;
Servo bottomServo;

int frequencyR = 0;
int frequencyG = 0;
int frequencyB = 0;
int color=0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  topServo.attach(7);
  bottomServo.attach(8);

  Serial.begin(9600);
}

void loop() {

  topServo.write(115);
  delay(500);
  
  for(int i = 115; i > 65; i--) {
    topServo.write(i);
    delay(2);
  }
  delay(500);
  
  color = readColor();
  delay(10);  

  switch (color) {
    case 1:  
    //Serial.println("RED");
    bottomServo.write(142);
    break;

    case 3:
    //Serial.println("GREEN");
    bottomServo.write(117);
    break;

    case 4:
    //Serial.println("YELLOW");
    bottomServo.write(67);
    break;

    case 6:
    //Serial.println("BLUE");
    bottomServo.write(92);
    break;
    
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 65; i > 29; i--) {
    topServo.write(i);
    delay(2);
  } 
  delay(200);
  
  for(int i = 29; i < 115; i++) {
    topServo.write(i);
    delay(2);
  }
  color=0;
}

// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequencyR = pulseIn(sensorOut, LOW);
  int R = frequencyR;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequencyR);//printing RED color frequency
  Serial.print("  ");
  delay(50);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequencyG = pulseIn(sensorOut, LOW);
  int G = frequencyG;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequencyG);//printing RED color frequency
  Serial.print("  ");
  delay(50);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequencyB = pulseIn(sensorOut, LOW);
  int B = frequencyB;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequencyB);//printing RED color frequency
  Serial.println("  ");
  delay(50);

  if(R<50 & R>40 & G<60 & G>50){
    color = 1; // Red
  }
  if(R<50 & R>40 & G<50 & G>35){
    color = 3; // Green
  }
  if(R< & R> & G< & G>){
    color = 4; // Yellow/orange
  }
  if (G< & G> & B< &B>){
    color = 6; // Blue
  }
  Serial.println(color);
  return color;  
}

//if(G<55 & G>43 & B<47 &B>35){
    //color = 2; // Orange
  //}

//if(R<56 & R>46 & G<65 & G>55){
    //color = 5; // Brown
  //}


    //case 2:
    //Serial.println("ORANGE");
    //bottomServo.write(75);
    //break;

    //case 5:
    //Serial.println("BROWN");
    //bottomServo.write(150);
    //break;
