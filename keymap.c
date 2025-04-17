#include QMK_KEYBOARD_H

#include "debug.h"
#include "quantum.h"
#include "features/achordion.h"
#include "print.h"
#include "leader.h"
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum layers { BASEMOD, NAV, NAVMOD, SYM, MOUSE, FN };
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //    ┌──────┬───────────┬───────────┬───────────┬───────────┬─────────┐                             ┌─────────────────┬─────────────┬───────────┬───────────┬───────────┬──────┐
    //    │ S(,) │     q     │     w     │     e     │     r     │    t    │                             │        y        │      u      │     i     │     o     │     p     │ bspc │
    //    ├──────┼───────────┼───────────┼───────────┼───────────┼─────────┤                             ├─────────────────┼─────────────┼───────────┼───────────┼───────────┼──────┤
    //    │ f13  │ LCTL_T(a) │ LSFT_T(s) │ LGUI_T(d) │ LALT_T(f) │    g    │                             │        h        │  RALT_T(j)  │ RGUI_T(k) │ RSFT_T(l) │ RCTL_T(;) │ ent  │
    //    ├──────┼───────────┼───────────┼───────────┼───────────┼─────────┤                             ├─────────────────┼─────────────┼───────────┼───────────┼───────────┼──────┤
    //    │  '   │     z     │     x     │     c     │     v     │    b    │                             │        n        │      m      │     -     │     =     │     /     │  no  │
    //    └──────┴───────────┴───────────┴───────────┼───────────┼─────────┼──────────────┐       ┌──────┼─────────────────┼─────────────┼───────────┴───────────┴───────────┴──────┘
    //                                               │    no     │ MO(SYM) │ LT(NAV, spc) │       │ lsft │ LT(MOUSE, bspc) │ LT(FN, del) │
    //                                               └───────────┴─────────┴──────────────┘       └──────┴─────────────────┴─────────────┘
    [BASEMOD] = LAYOUT_split_3x6_3(S(KC_COMM), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_F13, LCTL_T(KC_A), LSFT_T(KC_S), LGUI_T(KC_D), LALT_T(KC_F), KC_G, KC_H, RALT_T(KC_J), RGUI_T(KC_K), RSFT_T(KC_L), RCTL_T(KC_SCLN), KC_ENT, KC_QUOT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_MINS, KC_EQL, KC_SLSH, KC_NO, KC_NO, MO(SYM), LT(NAV, KC_SPC), KC_LSFT, LT(MOUSE, KC_BSPC), LT(FN, KC_DEL)),

    //    ┌──────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                   ┌──────┬──────┬──────┬────┬──────┬─────┐
    //    │ S(,) │   esc   │ LCTL(z) │ LCTL(x) │ LCTL(v) │ LCTL(b) │                                   │  1   │  2   │  3   │ 4  │  5   │ no  │
    //    ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┤                                   ├──────┼──────┼──────┼────┼──────┼─────┤
    //    │ f13  │  lctl   │  lsft   │  lgui   │  lalt   │   no    │                                   │  no  │ left │ down │ up │ rght │ ent │
    //    ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┤                                   ├──────┼──────┼──────┼────┼──────┼─────┤
    //    │  '   │ LCTL(s) │   no    │   no    │   tab   │   no    │                                   │  6   │  7   │  8   │ 9  │  0   │  /  │
    //    └──────┴─────────┴─────────┴─────────┼─────────┼─────────┼──────────────┐       ┌────────────┼──────┼──────┼──────┴────┴──────┴─────┘
    //                                         │         │ MO(SYM) │ LT(NAV, spc) │       │ MO(NAVMOD) │ bspc │ del  │
    //                                         └─────────┴─────────┴──────────────┘       └────────────┴──────┴──────┘
    [NAV] = LAYOUT_split_3x6_3(S(KC_COMM), KC_ESC, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_V), LCTL(KC_B), KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_F13, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENT, KC_QUOT, LCTL(KC_S), KC_NO, KC_NO, KC_TAB, KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SLSH, _______, MO(SYM), LT(NAV, KC_SPC), MO(NAVMOD), KC_BSPC, KC_DEL),

    //    ┌──────┬────────────┬────────────┬────────────┬────────────┬────────────┐                             ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    //    │ S(,) │    esc     │ S(LCTL(z)) │ S(LCTL(x)) │ S(LCTL(v)) │ S(LCTL(b)) │                             │ LSFT(1) │ LSFT(2) │ LSFT(3) │ LSFT(4) │ LSFT(5) │   no    │
    //    ├──────┼────────────┼────────────┼────────────┼────────────┼────────────┤                             ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    //    │ f13  │    aCL0    │    wh_d    │    wh_u    │    aCL2    │     g      │                             │  S(-)   │  home   │  pgdn   │  pgup   │   end   │ LSFT(4) │
    //    ├──────┼────────────┼────────────┼────────────┼────────────┼────────────┤                             ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    //    │  '   │ S(LCTL(s)) │     no     │     no     │   S(tab)   │     no     │                             │ LSFT(6) │ LSFT(7) │ LSFT(8) │ LSFT(9) │ LSFT(0) │    /    │
    //    └──────┴────────────┴────────────┴────────────┼────────────┼────────────┼──────────────┐       ┌──────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
    //                                                  │            │  MO(SYM)   │ LT(NAV, spc) │       │ lsft │  bspc   │   del   │
    //                                                  └────────────┴────────────┴──────────────┘       └──────┴─────────┴─────────┘
    [NAVMOD] = LAYOUT_split_3x6_3(S(KC_COMM), KC_ESC, S(LCTL(KC_Z)), S(LCTL(KC_X)), S(LCTL(KC_V)), S(LCTL(KC_B)), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), KC_NO, KC_F13, KC_ACL0, KC_WH_D, KC_WH_U, KC_ACL2, KC_G, S(KC_MINS), KC_HOME, KC_PGDN, KC_PGUP, KC_END, LSFT(KC_4), KC_QUOT, S(LCTL(KC_S)), KC_NO, KC_NO, S(KC_TAB), KC_NO, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_SLSH, _______, MO(SYM), LT(NAV, KC_SPC), KC_LSFT, KC_BSPC, KC_DEL),

    //    ┌──────┬───────────────┬───────────────┬───────────────┬───────────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    //    │ S(,) │      esc      │    LCTL(z)    │    LCTL(x)    │    LCTL(v)    │ LCTL(b) │                    │   no    │  S(2)   │  S(3)   │  S(4)   │  S(5)   │   no    │
    //    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    //    │ f13  │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │ OSM(MOD_LGUI) │ OSM(MOD_LALT) │   no    │                    │    -    │  S(9)   │  S([)   │    [    │  S(,)   │ LSFT(=) │
    //    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    //    │  '   │      no       │      no       │      no       │      tab      │   no    │                    │ LSFT(6) │ LSFT(7) │ LSFT(8) │ LSFT(9) │ LSFT(0) │    /    │
    //    └──────┴───────────────┴───────────────┴───────────────┼───────────────┼─────────┼─────┐       ┌──────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
    //                                                           │               │         │     │       │ lsft │  bspc   │   del   │
    //                                                           └───────────────┴─────────┴─────┘       └──────┴─────────┴─────────┘
    [SYM] = LAYOUT_split_3x6_3(S(KC_COMM), KC_ESC, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_V), LCTL(KC_B), KC_NO, S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_NO, KC_F13, OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LALT), KC_NO, KC_MINS, S(KC_9), S(KC_LBRC), KC_LBRC, S(KC_COMM), LSFT(KC_EQL), KC_QUOT, KC_NO, KC_NO, KC_NO, KC_TAB, KC_NO, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_SLSH, _______, _______, _______, KC_LSFT, KC_BSPC, KC_DEL),

    //    ┌──────┬──────┬──────┬──────┬──────┬─────────┐                     ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    //    │ S(,) │ esc  │ btn3 │ btn2 │ btn1 │   no    │                     │ LSFT(1) │ LSFT(2) │ LSFT(3) │ LSFT(4) │ LSFT(5) │   no    │
    //    ├──────┼──────┼──────┼──────┼──────┼─────────┤                     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    //    │ f13  │ aCL0 │ wh_d │ wh_u │ aCL2 │    g    │                     │  S(-)   │  ms_l   │  ms_d   │  ms_u   │  ms_r   │ LSFT(4) │
    //    ├──────┼──────┼──────┼──────┼──────┼─────────┤                     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
    //    │  '   │  no  │  no  │  no  │ tab  │   no    │                     │ LSFT(6) │ LSFT(7) │ LSFT(8) │ LSFT(9) │ LSFT(0) │    /    │
    //    └──────┴──────┴──────┴──────┼──────┼─────────┼──────┐       ┌──────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
    //                                │      │ MO(SYM) │ aCL2 │       │ lsft │  bspc   │   del   │
    //                                └──────┴─────────┴──────┘       └──────┴─────────┴─────────┘
    [MOUSE] = LAYOUT_split_3x6_3(S(KC_COMM), KC_ESC, KC_BTN3, KC_BTN2, KC_BTN1, KC_NO, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), KC_NO, KC_F13, KC_ACL0, KC_WH_D, KC_WH_U, KC_ACL2, KC_G, S(KC_MINS), KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, LSFT(KC_4), KC_QUOT, KC_NO, KC_NO, KC_NO, KC_TAB, KC_NO, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_SLSH, _______, MO(SYM), KC_ACL2, KC_LSFT, KC_BSPC, KC_DEL),

    //    ┌──────┬─────────┬─────────┬──────┬─────────┬─────────┐                    ┌──────┬─────┬─────┬─────┬─────┬─────┐
    //    │ mute │ RGB_VAD │ RGB_VAI │ bRID │  bRIU   │  mnxt   │                    │  no  │ f5  │ f6  │ f7  │ f8  │ no  │
    //    ├──────┼─────────┼─────────┼──────┼─────────┼─────────┤                    ├──────┼─────┼─────┼─────┼─────┼─────┤
    //    │ volu │  lctl   │  lsft   │ lgui │  lalt   │  mply   │                    │  no  │ f1  │ f2  │ f3  │ f4  │ ent │
    //    ├──────┼─────────┼─────────┼──────┼─────────┼─────────┤                    ├──────┼─────┼─────┼─────┼─────┼─────┤
    //    │ vold │   no    │   no    │  no  │ SGUI(d) │  mprv   │                    │  no  │ f9  │ f10 │ f11 │ f12 │ no  │
    //    └──────┴─────────┴─────────┴──────┼─────────┼─────────┼─────┐       ┌──────┼──────┼─────┼─────┴─────┴─────┴─────┘
    //                                      │         │ MO(SYM) │ f20 │       │ lsft │ bspc │ del │
    //                                      └─────────┴─────────┴─────┘       └──────┴──────┴─────┘
    [FN] = LAYOUT_split_3x6_3(KC_MUTE, RGB_VAD, RGB_VAI, KC_BRID, KC_BRIU, KC_MNXT, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_VOLU, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_MPLY, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_ENT, KC_VOLD, KC_NO, KC_NO, KC_NO, SGUI(KC_D), KC_MPRV, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, _______, MO(SYM), KC_F20, KC_LSFT, KC_BSPC, KC_DEL)};

tap_dance_action_t tap_dance_actions[] = {[0] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_9), LSFT(KC_0)), [1] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_LBRC), LSFT(KC_RBRC)), [2] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC), [3] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_COMM), LSFT(KC_DOT))};

enum combo_events {
    CAPS_LOCK_COMBO,
    /* SHIFT_GUI_COMBO, */
    /* CTRL_SHIFT_COMBO, */
    /* CTRL_GUI_COMBO, */
    CTRL_R_COMBO,
    NAV_SHIFT_COMBO, // New combo
    LEADER,
    ERE_COMBO, // k+i+r for direct combo
    RALT_COMBO,
    COMBO_LENGTH
};

// Define the key combinations
const uint16_t PROGMEM combo_g_h[] = {KC_G, KC_H, COMBO_END};
/* const uint16_t PROGMEM combo_lsft_lgui[] = {OSM(MOD_LSFT), OSM(MOD_LGUI), COMBO_END}; */
/* const uint16_t PROGMEM combo_lctl_lsft[] = {OSM(MOD_LCTL), OSM(MOD_LSFT), COMBO_END}; */
/* const uint16_t PROGMEM combo_lctl_lgui[] = {OSM(MOD_LCTL), OSM(MOD_LGUI), COMBO_END}; */

/* const uint16_t PROGMEM combo_lctrl_r[]   = {LCTL_T(KC_A), LSFT_T(KC_S), COMBO_END}; */
const uint16_t PROGMEM combo_lt_shift[] = {LT(NAV, KC_SPC), KC_LSFT, COMBO_END}; // New combo

const uint16_t PROGMEM leader_combo[] = {LALT_T(KC_F), KC_R, COMBO_END};
const uint16_t PROGMEM ere_combo[]    = {LALT_T(KC_F), KC_R, LSFT_T(KC_S), COMBO_END};
const uint16_t PROGMEM ralt_combo[]   = {RALT_T(KC_J), KC_U, COMBO_END};

// Define the combo actions
combo_t key_combos[COMBO_LENGTH] = {[CAPS_LOCK_COMBO] = COMBO(combo_g_h, KC_CAPS),
                                    /* [SHIFT_GUI_COMBO] = COMBO(combo_lsft_lgui, OSM(MOD_LSFT | MOD_LGUI)), */
                                    /* [CTRL_SHIFT_COMBO] = COMBO(combo_lctl_lsft, OSM(MOD_LCTL | MOD_LSFT)), */
                                    /* [CTRL_GUI_COMBO] = COMBO(combo_lctl_lgui, OSM(MOD_LCTL | MOD_LGUI)), */
                                    /* [CTRL_R_COMBO] = COMBO(combo_lctrl_r, LCTL(LSFT(KC_NO))), */
                                    [NAV_SHIFT_COMBO] = COMBO(combo_lt_shift, MO(NAVMOD)),
                                    [LEADER]          = COMBO(leader_combo, QK_LEAD),
                                    [ERE_COMBO]       = COMBO_ACTION(ere_combo),
                                    [RALT_COMBO]      = COMBO(ralt_combo, KC_RALT)};

static bool ik_ralt_pressed = false; // For combo to layer NAVMOD
bool        combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
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

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    // Sequence: HU combo (as leader) then 'r' -> ère
    // Note: Since keyboard is in US QWERTY but OS is in Colemak-DH
    // S in QWERTY = 'R' in Colemak-DH
    if (leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_RALT("s") "ksk"); // ère  On macOS, use SS_LOPT instead of SS_LALT
    }
}

#define KC_LBRACKET KC_LBRC
#define KC_RBRACKET KC_RBRC
#define KC_BSLASH KC_BACKSLASH

// ' "
const key_override_t override_quote_ast   = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_QUOTE, S(KC_8), 0xFFFF, 0);
const key_override_t override_quote_grave = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_QUOTE, KC_GRAVE, 0xFFFF, 0);

// ({[]})
const key_override_t override_shift_9_0               = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_9), S(KC_0), 0xFFFF, 0);
const key_override_t override_shift_lbracket_rbracket = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_LBRACKET), S(KC_RBRACKET), 0xFFFF, 0);
const key_override_t override_lbracket_rbracket       = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LBRACKET, KC_RBRACKET, 0xFFFF, 0);

// < > = ~
const key_override_t override_shift_comma_equal = ko_make_with_layers_and_negmods(MOD_MASK_SA, S(KC_COMMA), KC_EQUAL, 0xFFFF, 0);
const key_override_t override_shift_comma_dot   = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_COMMA), S(KC_DOT), 0xFFFF, 0);
const key_override_t override_shift_comma_grave = ko_make_with_layers_and_negmods(MOD_MASK_ALT, S(KC_COMMA), S(KC_GRAVE), 0xFFFF, 0);

// /\&|
const key_override_t override_slash_shift7       = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_SLASH, S(KC_7), 0xFFFF, 0);
const key_override_t override_slash_bslash_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_SLASH, KC_BSLASH, 0xFFFF, 0);
const key_override_t override_slash_bslash_ag    = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_SLASH, S(KC_BSLASH), 0xFFFF, 0);

// .,?!
const key_override_t override_f13_shift1      = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_F13, S(KC_1), 0xFFFF, 0);
const key_override_t override_f13_comma       = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_F13, KC_COMMA, 0xFFFF, 0);
const key_override_t override_f13_shift_slash = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_F13, S(KC_SLASH), 0xFFFF, 0);
const key_override_t override_f13_dot         = ko_make_basic(0, KC_F13, KC_DOT);

const key_override_t override_ralt_b = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_T, RALT(KC_D), 0xFFFF, 0);

// Create an array of pointers to the key overrides
const key_override_t *key_overrides[] = {
    &override_quote_ast,
    &override_quote_grave,
    &override_shift_9_0,
    &override_shift_lbracket_rbracket,
    &override_lbracket_rbracket,
    &override_shift_comma_equal,
    &override_shift_comma_dot,
    &override_slash_shift7,
    &override_slash_bslash_shift,
    &override_slash_bslash_ag,
    &override_shift_comma_grave,
    &override_f13_shift1,
    &override_f13_comma,
    &override_f13_shift_slash,
    &override_f13_dot,
    &override_ralt_b,
    NULL // Null terminate the array
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    /* if (record->event.key.row * MATRIX_COLS + record->event.key.col == IK_RALT) { */
    /*     ik_ralt_pressed = record->event.pressed; */
    /* } */
    /* #ifdef CONSOLE_ENABLE */
    /*     print("active modif "); */
    /*     dprint("Debug enabled") */
    /*     uprintf("%s active_modifiers" , active_modifiers); */
    /* #endif */
    /* active_modifiers = get_mods() | get_oneshot_mods() ;  */
    /* dprintf("\n\n\npressed kc: 0x%04X\n", keycode); */
    /* dprintf("LCTL_T: 0x%04X, RCTL_T: 0x%04X, LCTL: 0x%04X\n", LCTL_T(KC_A),RCTL_T(KC_SCLN), KC_LCTL); */
    /*     dprintf("LSFT_T(KC_S): 0x%04X, kc_s: 0x%04X\n\n\n", LSFT_T(KC_S), KC_S); */
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // To change tap term per key
    return TAPPING_TERM;
    /* switch (keycode) { */
    /*     case SFT_T(KC_SPC): */
    /*         return TAPPING_TERM + 1250; */
    /*     case LT(1, KC_GRV): */
    /*         return 130; */
    /*     default: */
    /*         return TAPPING_TERM; */
    /* } */
}
void matrix_scan_user(void) {
    achordion_task();
}
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 7:
            rgb_matrix_sethsv(HSV_LAYOUT_7);
            /* rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0); */
            break;
        case 6:
            rgb_matrix_sethsv(HSV_LAYOUT_6);
            /* rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0); */
            break;
        case 5:
            rgb_matrix_sethsv(HSV_LAYOUT_5);
            /* rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0); */
            break;
        case 4:
            rgb_matrix_sethsv(HSV_LAYOUT_4);
            /* rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0); */
            break;
        case 3:
            rgb_matrix_sethsv(HSV_LAYOUT_3); // Cyan
            /* rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0); */
            break;
        case 2:
            /* rgb_matrix_set_color(i, RGB_BLUE); */
            rgb_matrix_sethsv(HSV_LAYOUT_2); // Red
            /* rgb_matrix_set_color(HOME_KEY_LED_INDEX, RGB_LAYOUT_0); */
            break;
        case 1:
            /* rgb_matrix_set_color(i, RGB_YELLOW); */
            rgb_matrix_sethsv(HSV_LAYOUT_1); // Green
            /* rgb_matrix_set_color(IK_INSERT, RGB_LAYOUT_0); */
            break;
        case 0:
            /* rgb_matrix_set_color(i, RGB_GREEN); */
            rgb_matrix_sethsv(HSV_LAYOUT_0); // Purple
            /* rgb_matrix_set_color(IK_INSERT, RGB_LAYOUT_1); */
            break;
        default:
            break;
    }
    for (uint8_t i = led_min; i < led_max; i++) {
        if (host_keyboard_led_state().caps_lock) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 255, 255, 255);
            }
        }
    }
    return false;
}
#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C
