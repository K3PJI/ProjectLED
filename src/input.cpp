#include <Arduino.h>
#include <EncButton.h>
#include "input.h"
#include "state.h"

EncButton enc(2, 7, 8);

void input_update() {
    enc.tick();

    if (enc.click()) {
        encoder_click();
        system_activity();
    } else if (enc.hold()) {
        encoder_hold();
        system_activity();
    }

    if (enc.right()) {
        encoder_rotate(1);
        system_activity();
    }

    if (enc.left()) {
        encoder_rotate(-1);
        system_activity();
    }
}

void encoder_click() {
    switch (mode) {
    case MODE_IDLE:
        mode = MODE_PREVIEW;
        break;

    case MODE_PREVIEW:
        mode = MODE_MENU;
        break;
    
    case MODE_MENU:

        if (selected_menu_item == 0) {
            selected_menu_item = 0;
            mode = MODE_CEILING;
        } else if (selected_menu_item == 1) {
            selected_menu_item = 0;
            mode = MODE_MONITOR;
        }
        break;

    case MODE_CEILING:

        if (selected_menu_item == 0) {
            selected_menu_item = 0;
            mode = MODE_CEILING_BRIGHTNESS;
        } else if (selected_menu_item == 1) {
            selected_menu_item = 0;
            mode = MODE_CEILING_RED;
        }
        break;

    case MODE_CEILING_BRIGHTNESS:
        mode = MODE_CEILING;
        break;
    
    case MODE_CEILING_RED:
        mode = MODE_CEILING_GREEN;
        break;

    case MODE_CEILING_GREEN:
        mode = MODE_CEILING_BLUE;
        break;

    case MODE_CEILING_BLUE:
        mode = MODE_CEILING;
        break;

    case MODE_MONITOR:

        if (selected_menu_item == 0) {
            monitor_state = MONITOR_OFF;
        } else if (selected_menu_item == 1) {
            mode = MODE_MONITOR_BRIGHTNESS;
        } else if (selected_menu_item == 2) {
            selected_menu_item = 0;
            mode = MODE_MONITOR_COLOR;
        }
        break;

    case MODE_MONITOR_BRIGHTNESS:
        mode = MODE_MONITOR;
        break;

    case MODE_MONITOR_COLOR:

        if (selected_menu_item == 0) {
            monitor_state = MONITOR_A;
        } else if (selected_menu_item == 1) {
            monitor_state = MONITOR_B;
        }
        break;

    default:
        break;
    }
}

void encoder_hold() {
    switch (mode) {
    
    case MODE_IDLE:
        mode = MODE_PREVIEW;
        break;
    
    case MODE_PREVIEW:
        mode = MODE_IDLE;
        break;

    case MODE_MENU:
        mode = MODE_PREVIEW;
        break;

    case MODE_CEILING:
        mode = MODE_MENU;
        selected_menu_item = 0;
        break;

    case MODE_MONITOR:
        mode = MODE_MENU;
        selected_menu_item = 0;
        break;
    
    case MODE_CEILING_BRIGHTNESS:
        mode = MODE_CEILING;
        break;

    case MODE_CEILING_RED:
        mode = MODE_CEILING;
        break;

    case MODE_CEILING_GREEN:
        mode = MODE_CEILING;
        break;

    case MODE_CEILING_BLUE:
        mode = MODE_CEILING;
        break;

    case MODE_MONITOR_BRIGHTNESS:
        mode = MODE_MONITOR;
        break;
    
    case MODE_MONITOR_COLOR:
        mode = MODE_MONITOR;
        selected_menu_item = 0;
        break;

    default:
        break;
    }
}

void encoder_rotate(int direction) {
    switch (mode) {
    case MODE_MENU:
        selected_menu_item += direction;

        if (selected_menu_item < 0) {
            selected_menu_item = 0;
        } 

        if (selected_menu_item > 1) {
            selected_menu_item = 1;
        }

        break;
    
    case MODE_CEILING:
        selected_menu_item += direction;

        if (selected_menu_item < 0) {
            selected_menu_item = 0;
        }

        if (selected_menu_item > 1) {
            selected_menu_item = 1;
        }

        break;
    
    case MODE_CEILING_BRIGHTNESS:
        ceiling_brightness += direction * 10;
        
        if (ceiling_brightness < 0) {
            ceiling_brightness = 0;
        }

        if (ceiling_brightness > 100) {
            ceiling_brightness = 100;
        }

        break;

    case MODE_CEILING_RED:
        ceiling_color.r += direction * 5;

        if (ceiling_color.r < 0) {
            ceiling_color.r = 0;
        }

        if (ceiling_color.r > 255) {
            ceiling_color.r = 255;
        }

        break;  

    case MODE_CEILING_GREEN:
        ceiling_color.g += direction * 5;

        if (ceiling_color.g < 0) {
            ceiling_color.g = 0;
        }

        if (ceiling_color.g > 255) {
            ceiling_color.g = 255;
        }

        break;

    case MODE_CEILING_BLUE:
        ceiling_color.b += direction * 5;

        if (ceiling_color.b < 0) {
            ceiling_color.b = 0;
        }

        if (ceiling_color.b > 255) {
            ceiling_color.b = 255;
        }

        break;

    case MODE_MONITOR:
        selected_menu_item += direction;

        if (selected_menu_item < 0) {
            selected_menu_item = 0;
        } 
        
        if (selected_menu_item > 2) {
            selected_menu_item = 2;
        }

        break;

    case MODE_MONITOR_BRIGHTNESS:
        monitor_brightness += direction * 10;

        if (monitor_brightness < 0) {
            monitor_brightness = 0;
        }

        if (monitor_brightness > 100) {
            monitor_brightness = 100;
        }

        break;

    case MODE_MONITOR_COLOR:
        selected_menu_item += direction;

        if (selected_menu_item < 0) {
            selected_menu_item = 0;
        }

        if (selected_menu_item > 1) {
            selected_menu_item = 1;
        }

        break;

    default:
        break;
    }
}

