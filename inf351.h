int menu(int BUTTON_A, int BUTTON_B, String items[]) { 
  oled.clearDisplay(); 
  int buttonStateB;
  int lastButtonStateB; 
  int menuItem = 0;  
  oled.setCursor(0,0);
  oled.print(items[0]); 
  oled.setCursor(0,10);
  oled.print(items[1]); 
  oled.setCursor(0,20);
  oled.print(items[2]); 
  oled.drawRect(0,0,128,10,WHITE);
  oled.drawRect(0,20,128,10,BLACK);
  oled.display();
  //move up and down using button B and select with button a
  while (digitalRead(BUTTON_A) == HIGH) {
    buttonStateB = digitalRead(BUTTON_B);
    if (buttonStateB != lastButtonStateB) {
      if (buttonStateB == LOW) { 
        menuItem++;
      }
      if (menuItem>2) menuItem=0;   
        if (menuItem == 0) {
        oled.drawRect(0,0,128,10,WHITE);
        oled.drawRect(0,20,128,10,BLACK);
        oled.display();       
        }else if (menuItem == 1) { 
        oled.drawRect(0,10,128,10,WHITE); 
        oled.drawRect(0,0,128,10,BLACK); 
        oled.display(); 
        }else if (menuItem == 2) { 
        oled.drawRect(0,20,128,10,WHITE);
        oled.drawRect(0,10,128,10,BLACK); 
        oled.display();     
        }
      }
    lastButtonStateB = buttonStateB; 
    }
    while (digitalRead(BUTTON_A) == LOW) {}
return menuItem; 
}
