#include <Arduino.h>
#include <LCD_1602_RUS_ALL.h>

#include "state.h"
#include "display.h"

LCD_1602_RUS lcd(0x27, 16, 2);

void display_init() {
    lcd.init();
    lcd.backlight();
}

void display_update() {

    switch (mode)
    {
    case MODE_IDLE:
        lcd.noBacklight();
        break;
    
    case MODE_PREVIEW:
    lcd.backlight();
    

    default:
        break;
    }

}