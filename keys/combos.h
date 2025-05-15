#pragma once

#include "keymap.h"

// Define combo events
enum combo_events {
    CAPS_LOCK_COMBO,
    CTRL_R_COMBO,
    NAV_SHIFT_COMBO,
    LEADER,
    ERE_COMBO,
    RALT_COMBO,
    F13_QUES_COMBO,
    COMBO_LENGTH
};

extern combo_t key_combos[COMBO_LENGTH];

void setup_combos(void);
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record);
void process_combo_event(uint16_t combo_index, bool pressed);
