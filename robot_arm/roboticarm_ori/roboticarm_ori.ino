++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Include Libraries
#include "Arduino.h"
#include "Servo.h"


// Pin Definitions
#define SERVO9G_1_PIN_SIG  2
#define SERVO9G_2_PIN_SIG 3
#define SERVO9G_3_PIN_SIG 4
#define SERVO9G_4_PIN_SIG 5



// Global variables and defines
const int servo9g_1RestPosition   = 20;  //Starting position
const int servo9g_1TargetPosition = 150; //Position when event is detected
const int servo9g_2RestPosition   = 20;  //Starting position
const int servo9g_2TargetPosition = 150; //Position when event is detected
const int servo9g_3RestPosition   = 20;  //Starting position
const int servo9g_3TargetPosition = 150; //Position when event is detected
const int servo9g_4RestPosition   = 20;  //Starting position
const int servo9g_4TargetPosition = 150; //Position when event is detected
// object initialization
Servo servo9g_1;
Servo servo9g_2;
Servo servo9g_3;
Servo servo9g_4;



// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    servo9g_1.attach(SERVO9G_1_PIN_SIG);
    servo9g_1.write(servo9g_1RestPosition);
    delay(100);
    servo9g_1.detach();
    servo9g_2.attach(SERVO9G_2_PIN_SIG);
    servo9g_2.write(servo9g_2RestPosition);
    delay(100);
    servo9g_2.detach();
    servo9g_3.attach(SERVO9G_3_PIN_SIG);
    servo9g_3.write(servo9g_3RestPosition);
    delay(100);
    servo9g_3.detach();
    servo9g_4.attach(SERVO9G_4_PIN_SIG);
    servo9g_4.write(servo9g_4RestPosition);
    delay(100);
    servo9g_4.detach();
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // 9g Micro Servo #1 - Test Code
    // The servo will rotate to target position and back to resting position with an interval of 500 milliseconds (0.5 seconds) 
    servo9g_1.attach(SERVO9G_1_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo9g_1.write(servo9g_1TargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(500);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servo9g_1.write(servo9g_1RestPosition);    // 4. turns servo back to rest position. Modify initial position by modifying the 'ServoRestPosition' definition above.
    delay(500);                              // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servo9g_1.detach();                    // 6. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '2') {
    // 9g Micro Servo #2 - Test Code
    // The servo will rotate to target position and back to resting position with an interval of 500 milliseconds (0.5 seconds) 
    servo9g_2.attach(SERVO9G_2_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo9g_2.write(servo9g_2TargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(500);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servo9g_2.write(servo9g_2RestPosition);    // 4. turns servo back to rest position. Modify initial position by modifying the 'ServoRestPosition' definition above.
    delay(500);                              // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servo9g_2.detach();                    // 6. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '3') {
    // 9g Micro Servo #3 - Test Code
    // The servo will rotate to target position and back to resting position with an interval of 500 milliseconds (0.5 seconds) 
    servo9g_3.attach(SERVO9G_3_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo9g_3.write(servo9g_3TargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(500);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servo9g_3.write(servo9g_3RestPosition);    // 4. turns servo back to rest position. Modify initial position by modifying the 'ServoRestPosition' definition above.
    delay(500);                              // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servo9g_3.detach();                    // 6. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '4') {
    // 9g Micro Servo #4 - Test Code
    // The servo will rotate to target position and back to resting position with an interval of 500 milliseconds (0.5 seconds) 
    servo9g_4.attach(SERVO9G_4_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo9g_4.write(servo9g_4TargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(500);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servo9g_4.write(servo9g_4RestPosition);    // 4. turns servo back to rest position. Modify initial position by modifying the 'ServoRestPosition' definition above.
    delay(500);                              // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servo9g_4.detach();                    // 6. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    
    
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) 9g Micro Servo #1"));
    Serial.println(F("(2) 9g Micro Servo #2"));
    Serial.println(F("(3) 9g Micro Servo #3"));
    Serial.println(F("(4) 9g Micro Servo #4"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {
            if(c == '1') 
          Serial.println(F("Now Testing 9g Micro Servo #1"));
        else if(c == '2') 
          Serial.println(F("Now Testing 9g Micro Servo #2"));
        else if(c == '3') 
          Serial.println(F("Now Testing 9g Micro Servo #3"));
        else if(c == '4') 
          Serial.println(F("Now Testing 9g Micro Servo #4"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/
