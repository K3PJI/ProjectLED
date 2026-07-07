#include <EncButton.h>
#include "input.h"
#include "state.h"

EncButton enc(2, 7, 8);

void input_update() {
    enc.tick();

    if (enc.click()) {
        encoder_click();
    } else if (enc.hold()) {
        encoder_hold();
    }

    if (enc.right()) {
        encoder_rotate(1);
    }

    if (enc.left()) {
        encoder_rotate(-1);
    }
}

void encoder_click() {
    switch (mode) {
    case MODE_START:
        mode = MODE_PREVIEW;
        break;
    
    case MODE_MENU:
        if (selected_menu_item == 0) {
            mode = MODE_CEILING;
        } else if (selected_menu_item == 1) {
            mode = MODE_MONITOR;
        }
        break;

    default:
        break;
    }
}

void encoder_hold() {
    switch (mode) {
    case MODE_PREVIEW:
        mode = MODE_START;
        break;

    case MODE_MENU:
        mode = MODE_PREVIEW;
        break;

    case MODE_CEILING:
        mode = MODE_MENU;
        break;

    case MODE_MONITOR:
        mode = MODE_MENU;
        break;

    default:
        break;
    }
}

void encoder_rotate(int direction) {

}

