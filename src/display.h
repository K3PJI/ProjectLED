#pragma once

void display_update();

void display_init();

void display_prepare();

void show_preview();

void show_menu();

void show_ceiling();

void show_monitor();

void show_ceiling_brightness();

void show_ceiling_green();

void show_ceiling_blue();

void show_ceiling_red();

void show_monitor_brightness();

void show_monitor_color();

void printLine(uint8_t row, const char *text);

void printNum(uint8_t row, int value);

void printPercent(uint8_t row, int value);