#include "combos.h"
#include "features/achordion.h"

// Define the key combinations
const uint16_t PROGMEM combo_g_h[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM combo_lt_shift[] = {LT(NAV, KC_SPC), KC_LSFT, COMBO_END};
const uint16_t PROGMEM leader_combo[] = {LALT_T(KC_F), KC_R, COMBO_END};
const uint16_t PROGMEM ere_combo[] = {LALT_T(KC_F), KC_R, LSFT_T(KC_S), COMBO_END};
const uint16_t PROGMEM ralt_combo[] = {RALT_T(KC_J), KC_U, COMBO_END};
const uint16_t PROGMEM f13_ques_combo[] = {LALT_T(KC_F), KC_F13, COMBO_END};

// Define the combo actions
combo_t key_combos[COMBO_LENGTH] = {
    [CAPS_LOCK_COMBO] = COMBO(combo_g_h, KC_CAPS),
    [NAV_SHIFT_COMBO] = COMBO(combo_lt_shift, MO(NAVMOD)),
    [LEADER] = COMBO(leader_combo, QK_LEAD),
    [ERE_COMBO] = COMBO_ACTION(ere_combo),
    [RALT_COMBO] = COMBO(ralt_combo, KC_RALT),
    [F13_QUES_COMBO] = COMBO(f13_ques_combo, KC_QUES)
};

bool ik_ralt_pressed = false; // For combo to layer NAVMOD

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case NAV_SHIFT_COMBO:
            if (!ik_ralt_pressed) {
                return false;
            }
            break;
    }
    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case ERE_COMBO:
            if (pressed) {
                SEND_STRING(SS_RALT("s") "ksk"); // ère  On macOS, use SS_LOPT instead of SS_LALT
                break;
            }
    }
}
