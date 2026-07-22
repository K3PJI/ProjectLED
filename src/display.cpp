#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "state.h"
#include "display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void display_init()
{
    lcd.init();
    lcd.backlight();
}

void display_prepare()
{
    lcd.backlight();
    lcd.cursor_off();
}

void printLine(uint8_t row, const char *text)
{
    lcd.setCursor(0, row);
    lcd.print("                ");
    lcd.setCursor(0, row);
    lcd.print(text);
}

void printNum(uint8_t row, int value)
{
    lcd.setCursor(0, row);
    lcd.print("                ");
    lcd.setCursor(0, row);
    lcd.print(value);
}

void printPercent(uint8_t row, int value)
{
    lcd.setCursor(0, row);
    lcd.print("                ");
    lcd.setCursor(0, row);
    lcd.print(value);
    lcd.print("%");
}

void display_update()
{

    switch (mode)
    {
    case MODE_IDLE:
        lcd.noBacklight();
        break;

    case MODE_PREVIEW:
        show_preview();
        break;

    case MODE_MENU:
        show_menu();
        break;

    case MODE_CEILING:
        show_ceiling();
        break;

    case MODE_CEILING_BRIGHTNESS:
        show_ceiling_brightness();
        break;

    case MODE_CEILING_RED:
        show_ceiling_red();
        break;

    case MODE_CEILING_GREEN:
        show_ceiling_green();
        break;

    case MODE_CEILING_BLUE:
        show_ceiling_blue();
        break;

    case MODE_MONITOR:
        show_monitor();
        break;

    case MODE_MONITOR_BRIGHTNESS:
        show_monitor_brightness();
        break;

    case MODE_MONITOR_COLOR:
        show_monitor_color();
        break;

    default:
        break;
    }
}

void show_preview()
{
    display_prepare();

    lcd.setCursor(0, 0);
    lcd.print("MON:");
    if (monitor_state == MONITOR_OFF)
    {
        lcd.setCursor(5, 0);
        lcd.print("     ");
        lcd.setCursor(5, 0);
        lcd.print("OFF");
    }
    else if (monitor_state == MONITOR_A)
    {
        lcd.setCursor(5, 0);
        lcd.print("     ");
        lcd.setCursor(5, 0);
        lcd.print("BLUE");
    }
    else if (monitor_state == MONITOR_B)
    {
        lcd.setCursor(5, 0);
        lcd.print("     ");
        lcd.setCursor(5, 0);
        lcd.print("WHITE");
    }
    lcd.setCursor(0, 1);
    lcd.print("TOP:");
    if (ceiling_enabled == false)
    {
        lcd.setCursor(5, 1);
        lcd.print("   ");
        lcd.setCursor(5, 1);
        lcd.print("OFF");
    }
    else if (ceiling_enabled == true)
    {
        lcd.setCursor(5, 1);
        lcd.print("   ");
        lcd.setCursor(5, 1);
        lcd.print("ON");
    }
}

void show_menu()
{
    display_prepare();

    if (selected_menu_item == 0)
    {
        printLine(0, "> TOP");
        printLine(1, "  MON");
    }
    else
    {
        printLine(0, "  TOP");
        printLine(1, "> MON");
    }
}

void show_ceiling()
{
    display_prepare();

    if (selected_menu_item == 0)
    {
        printLine(0, "> ON/OFF");
        printLine(1, "  Bright");
    }
    else if (selected_menu_item == 1)
    {
        printLine(0, "  ON/OFF");
        printLine(1, "> Bright");
    }
    else if (selected_menu_item == 2)
    {
        printLine(0, "> Color");
        printLine(1, "");
    }
}

void show_monitor()
{
    display_prepare();

    if (selected_menu_item == 0)
    {
        printLine(0, "> ON/OFF");
        printLine(1, "  Bright");
    }
    else if (selected_menu_item == 1)
    {
        printLine(0, "  ON/OFF");
        printLine(1, "> Bright");
    }
    else if (selected_menu_item == 2)
    {
        printLine(0, "> Color");
        printLine(1, "");
    }
}

void show_ceiling_brightness()
{
    display_prepare();

    printLine(0, "Brightness");
    printPercent(1, ceiling_brightness);
}

void show_ceiling_green()
{
    display_prepare();

    printLine(0, "Green");
    printNum(1, ceiling_color.g);
}

void show_ceiling_blue()
{
    display_prepare();

    printLine(0, "Blue");
    printNum(1, ceiling_color.b);
}

void show_ceiling_red()
{
    display_prepare();

    printLine(0, "Red");
    printNum(1, ceiling_color.r);
}

void show_monitor_brightness()
{
    display_prepare();

    printLine(0, "Brightness");
    printPercent(1, monitor_brightness);
}

void show_monitor_color()
{
    display_prepare();

    if (selected_menu_item == 0)
    {
        printLine(0, "> White");
        printLine(1, "  Blue");
    }
    else if (selected_menu_item == 1)
    {
        printLine(0, "  White");
        printLine(1, "> Blue");
    }
}