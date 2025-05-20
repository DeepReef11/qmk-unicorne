#include "mouse_control.h"
#include "deferred_exec.h"
#include <stdint.h>

uint16_t current_grid_size = GRID_SIZE_DEFAULT;

uint32_t mouse_key_release(uint32_t trigger_time, void *cb_arg) {
    uint16_t keycode = (uint16_t)(uintptr_t)cb_arg;
    unregister_code16(keycode);
    return 0;
}

void send_mouse_tap(uint16_t keycode) {
    register_code16(keycode);
    uint32_t delay = (current_grid_size * 5);
    defer_exec(delay, mouse_key_release, (void *)(uintptr_t)keycode);
}

bool process_mouse_keycode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MS_STEP_UP:
                tap_code16(KC_MS_UP);
                return false;
            case MS_STEP_DOWN:
                tap_code16(KC_MS_DOWN);
                return false;
            case MS_STEP_LEFT:
                tap_code16(KC_MS_LEFT);
                return false;
            case MS_STEP_RIGHT:
                tap_code16(KC_MS_RIGHT);
                return false;
            case MS_GRID_LEFT:
                send_mouse_tap(KC_MS_LEFT);
                return false;
            case MS_GRID_RIGHT:
                send_mouse_tap(KC_MS_RIGHT);
                return false;
            case MS_GRID_UP:
                send_mouse_tap(KC_MS_UP);
                return false;
            case MS_GRID_DOWN:
                send_mouse_tap(KC_MS_DOWN);
                return false;
            case MS_GRID_SIZE_RESET:
                // Reset grid size to default
                current_grid_size = GRID_SIZE_DEFAULT;
                return false;
            case MS_GRID_SIZE_UP:
                // Increase grid size by the defined step, respecting maximum value
                if (current_grid_size < GRID_SIZE_MAX) {
                    current_grid_size = current_grid_size + GRID_SIZE_STEP;
                }
                return false;
            case MS_GRID_SIZE_DOWN:
                // Decrease grid size by the defined step, respecting minimum value
                if (current_grid_size > GRID_SIZE_MIN) {
                    current_grid_size = current_grid_size - GRID_SIZE_STEP;
                }
                return false;
        }
    }

    return true;
}
