/*
 * INF351 Example Code 
 * Timesharing computer 
 * Fall 2019
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

#define BUTTON_A  9
#define BUTTON_B  6
#define BUTTON_C  5

int state = 1; 

void setup() {
  Serial.begin(9600);

  Serial.println("OLED FeatherWing test");
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  Serial.println("OLED begun");

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  Serial.println("IO test");

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);

  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("INF351 Test code ");
  display.setCursor(0,0);
  display.display(); // actually display all of the above
}

void loop() {
  if(!digitalRead(BUTTON_A)) {
    state = 1;
  }else if(!digitalRead(BUTTON_B)) {
    state = 2; 
  }else if(!digitalRead(BUTTON_C)) {
    state = 3;  
  }else state = 0; 
  
  display.display();

switch (state) {
    case 1:    
      Serial.println("state1");
      display.print("state 1");
      display.display();
      delay(1000); 
      display.clearDisplay();
      display.setCursor(0,0);
      break;
    case 2:    
      Serial.println("state2");
      display.print("state 2");
      display.display(); 
      delay(1000); 
      display.clearDisplay();
      display.setCursor(0,0);
      break;
    case 3:    
      Serial.println("state3");
      display.print("state 3");
      display.display();
      delay(1000); 
      display.clearDisplay();
      display.setCursor(0,0); 
      break;
  }
  
}
