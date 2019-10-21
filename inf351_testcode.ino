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


switch (state) {
  case 0:
    oled.clearDisplay(); 
    state = menu(BUTTON_A,BUTTON_B); 
    break;
  case 1:
    oled.clearDisplay(); 
    oled.println("item 2");
    oled.display(); 
    delay(1000);
    break;
  case 2:
    oled.clearDisplay(); 
    oled.println("item 3");
    oled.display(); 
    delay(1000); 
    break;
}

}
