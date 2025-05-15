#include "rgb_indicators.h"

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 7:
            rgb_matrix_sethsv(HSV_LAYOUT_7);
            break;
        case 6:
            rgb_matrix_sethsv(HSV_LAYOUT_6);
            break;
        case 5:
            rgb_matrix_sethsv(HSV_LAYOUT_5);
            break;
        case 4:
            rgb_matrix_sethsv(HSV_LAYOUT_4);
            break;
        case 3:
            rgb_matrix_sethsv(HSV_LAYOUT_3); // Cyan
            break;
        case 2:
            rgb_matrix_sethsv(HSV_LAYOUT_2); // Red
            break;
        case 1:
            rgb_matrix_sethsv(HSV_LAYOUT_1); // Green
            break;
        case 0:
            rgb_matrix_sethsv(HSV_LAYOUT_0); // Purple
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
