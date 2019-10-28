/*
 * INF351 Example Code 
 * Timesharing computer 
 * Fall 2019
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_FeatherOLED.h>
Adafruit_FeatherOLED oled = Adafruit_FeatherOLED();

#include "inf351.h" 

// integer variable to hold current counter value
int count = 0;
int state = 0; 

#define BUTTON_A  9
#define BUTTON_B  6
#define BUTTON_C  5
bool lastButtonStateA; 
bool buttonStateA; 
bool buttonStateB; 
bool buttonStateC; 

int userNum = 3; 
String users[] = {"Matt", "Tim", "Nick"}; 
String tasks[] = {"Wash dishes", "Vacuum floor", "Tidy living room"}; 

int userTask[3];

void setup()
{
  Serial.begin(115200);

oled.init();

pinMode(BUTTON_A, INPUT_PULLUP); 
pinMode(BUTTON_B, INPUT_PULLUP);
pinMode(BUTTON_C, INPUT_PULLUP);

}


void loop()
{

switch (state) {
  case 0:
    oled.clearDisplay(); 
    assignUsers(userNum, users, tasks); 
    state = 1;
    break;
  case 1:
    for (int i=0; i<userNum; i++) {
    oled.clearDisplay();
    oled.setCursor(0,0); 
    oled.print(users[i]);
    oled.print(" is assigned to task: ");
    oled.print(tasks[userTask[i]]); 
    oled.display(); 
    while (digitalRead(BUTTON_A) == HIGH) {delay(10);}
    while (digitalRead(BUTTON_A) == LOW) {delay(10);}
    }
    state =0; 
    break;
  case 2:
    //not in use 
    delay(1000); 
    break;
}
}

int assignUsers(int num, String users[], String tasks[]) {

for (int i=0; i<num; i++) {

oled.clearDisplay();
oled.setCursor(0,0); 
oled.print("select task for user:"); 
oled.print(users[i]);
oled.display(); 
delay(1000); 
userTask[i]=menu(BUTTON_A,BUTTON_B,tasks);
Serial.print(userTask[i]);   
}
}
