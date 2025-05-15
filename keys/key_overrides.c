#include "key_overrides.h"

// ' "
const key_override_t override_quote_ast = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_QUOTE, S(KC_8), 0xFFFF, 0);
const key_override_t override_quote_grave = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_QUOTE, KC_GRAVE, 0xFFFF, 0);

// ({[]})
const key_override_t override_shift_9_0 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_9), S(KC_0), 0xFFFF, 0);
const key_override_t override_shift_lbracket_rbracket = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_LBRC), S(KC_RBRC), 0xFFFF, 0);
const key_override_t override_lbracket_rbracket = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC, 0xFFFF, 0);

// < > = ~
const key_override_t override_shift_comma_equal = ko_make_with_layers_and_negmods(MOD_MASK_SA, S(KC_COMMA), KC_EQUAL, 0xFFFF, 0);
const key_override_t override_shift_comma_dot = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(KC_COMMA), S(KC_DOT), 0xFFFF, 0);
const key_override_t override_shift_comma_grave = ko_make_with_layers_and_negmods(MOD_MASK_ALT, S(KC_COMMA), S(KC_GRAVE), 0xFFFF, 0);

// /\&|
#define KC_BSLASH KC_BACKSLASH
const key_override_t override_slash_shift7 = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_SLASH, S(KC_7), 0xFFFF, 0);
const key_override_t override_slash_bslash_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_SLASH, KC_BSLASH, 0xFFFF, 0);
const key_override_t override_slash_bslash_ag = ko_make_with_layers_and_negmods(MOD_MASK_ALT, KC_SLASH, S(KC_BSLASH), 0xFFFF, 0);

// .,?!
const key_override_t override_f13_exlm = ko_make_with_layers_and_negmods(MOD_MASK_SA, KC_F13, KC_EXLM, 0xFFFF, 0);
const key_override_t override_f13_comma = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_F13, KC_COMMA, 0xFFFF, 0);
const key_override_t override_f13_ques = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_F13, KC_QUES, 0xFFFF, 0, ko_option_activation_trigger_down);
const key_override_t override_f13_dot = ko_make_basic(0, KC_F13, KC_DOT);

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
    &override_f13_exlm,
    &override_f13_comma,
    &override_f13_ques,
    &override_f13_dot,
    &override_ralt_b,
    /* NULL // Null terminate the array */
};
