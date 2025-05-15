#pragma once

#include "keymap.h"
#include "pointing_device.h"

extern uint16_t current_grid_size;
extern uint8_t current_accel_level;

void send_repeated_movement(int8_t x, int8_t y);
bool process_mouse_keycode(uint16_t keycode, keyrecord_t *record);
