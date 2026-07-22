#pragma once

enum Mode
{
    MODE_IDLE,
    MODE_PREVIEW,
    MODE_MENU,

    MODE_CEILING,
    MODE_CEILING_BRIGHTNESS,
    MODE_CEILING_RED,
    MODE_CEILING_GREEN,
    MODE_CEILING_BLUE,

    MODE_MONITOR,
    MODE_MONITOR_BRIGHTNESS,
    MODE_MONITOR_COLOR
};

enum MonitorState
{
    MONITOR_OFF,
    MONITOR_A,
    MONITOR_B
};

struct RGB
{
    int r;
    int g;
    int b;
};

extern Mode mode;

extern int ceiling_brightness;
extern RGB ceiling_color;
extern bool ceiling_enabled;

extern MonitorState monitor_state;
extern int monitor_brightness;

extern int screen_page;
extern int selected_menu_item;

extern unsigned long last_activity;