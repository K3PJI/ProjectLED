#include <Arduino.h>
#include "system.h"
#include "state.h"

#define SCREEN_TIMEOUT 30000

void system_activity() {
    last_activity = millis();
}

void system_update() {
    if (millis() - last_activity() > SCREEN_TIMEOUT) {
        if (MODE != MODE_START) {
            mode = MODE_START;
        }
    }
}