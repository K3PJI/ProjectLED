#include <Arduino.h>
#include "state.h"

// =====НАЧАЛЬНОЕ СОСТОЯНИЕ=====
Mode mode = MODE_PREVIEW;

// =====ПОТОЛОЧНАЯ ПОДСВЕТКА(ЯРКОСТЬ/RGB)=====
int ceiling_brightness = 50;
RGB ceiling_color = {0, 0, 0};

// =====МОНИТОРНАЯ ПОДСВЕТКА=====
MonitorState monitor_state = MONITOR_OFF;
int monitor_brightness = 50;

// =====ЭКРАН=====
int screen_page = 0;
int selected_menu_item = 0;

unsigned long last_activity = 0;