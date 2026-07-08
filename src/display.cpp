#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "state.h"
#include "display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

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

        break;

    case MODE_MENU:

        break;

    case MODE_CEILING:

        break;

    case MODE_CEILING_RED:

        break;

    case MODE_CEILING_GREEN:

        break;
        
    case MODE_CEILING_BLUE:

        break;

    case MODE_MONITOR:

        break;

    case MODE_MONITOR_BRIGHTNESS:

        break;

    case MODE_MONITOR_COLOR:
    
        break;

    default:
        break;
    }

}

void show_preview(MonitorState monitor_state, int monitor_brightness, int ceiling_brightness, RGB ceiling_color) {
    lcd.backlight();
    lcd.cursor_off();
    lcd.setCursor(0, 0);
    lcd.print("MS: ");
    if (monitor_state == MONITOR_OFF) {
        lcd.println("OFF");
    } else if (monitor_state == MONITOR_A) {
        lcd.println("BLUE");
    } else if (monitor_state == MONITOR_B) {
        lcd.println("WHITE");
    }
    lcd.setCursor(0, 1);
    lcd.print("CEILING: ")
}