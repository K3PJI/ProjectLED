#pragma once

enum Mode {
    MODE_START,
    MODE_PREVIEW,
    MODE_MENU,
    MODE_CEILING,
    MODE_MONITOR
};

enum MonitorState {
    MONITOR_OFF,
    MONITOR_A,
    MONITOR_B
};

struct RGB {
    int r;
    int g;
    int b;
};

enum RGBChannel {
    CHANNEL_RED,
    CHANNEL_GREEN,
    CHANNEL_BLUE
};

enum CeilingMenuItem {
    CEILING_BRIGHTNESS,
    CEILING_COLOR
}

extern Mode mode;

extern int ceiling_brightness;
extern RGB ceiling_color;
extern RGBChannel rgb_channel;
extern CeilingMenuItem ceiling_menu_item;

extern MonitorState monitor_state;
extern int monitor_brightness;

extern int screen_page;
extern int selected_menu_item; 