@@ -0,0 +1,79 @@
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
//oled.clearDisplay();
/*
if(!digitalRead(BUTTON_A)) oled.print("A");
if(!digitalRead(BUTTON_B)) oled.print("B");
if(!digitalRead(BUTTON_C)) oled.print("C");

buttonStateA = digitalRead(BUTTON_A);
buttonStateB = digitalRead(BUTTON_B);
buttonStateC = digitalRead(BUTTON_C); 

// print the count value to the OLED
oled.print("count: ");
oled.println(count);

  // update the display with the new count
  oled.display();

 if (buttonStateA != lastButtonStateA) {
    if (buttonStateA == LOW) {
         count++;
        }
    } 
  lastButtonStateA = buttonStateA;

delay(100); 
*/
int item = menu(BUTTON_A,BUTTON_B); 

 if (item == 0) {
  Serial.println("item 1"); 
 }else if (item == 1){
  Serial.println("item 2");   
 }else if (item ==2) {
  Serial.println("item 3");
 }

}
