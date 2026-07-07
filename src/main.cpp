#define _LCD_TYPE 1

#include <Arduino.h>
#include <LCD_1602_RUS_ALL.h>

LCD_1602_RUS lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

}

void loop() {

}