#include "mouse_control.h"

uint8_t  current_accel_level = 0; // 0=slow, 1=medium, 2=fast
uint16_t current_grid_size   = GRID_SIZE_DEFAULT;

void send_repeated_movement(int8_t x, int8_t y) {
    report_mouse_t report  = {0};
    uint8_t        repeats = 1;

    // Determine number of repeats based on acceleration level
    if (current_accel_level == 1) {
        repeats = 3; // Triple for medium speed
    } else if (current_accel_level == 2) {
        repeats = 6; // 6x for fast speed
    }

    report.x = x;
    report.y = y;

    // Send the report multiple times based on acceleration level
    for (uint8_t i = 0; i < repeats; i++) {
        pointing_device_set_report(report);
        pointing_device_send();
        // Small delay to ensure reports are processed
        wait_ms(10);
    }
}

bool process_mouse_keycode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MS_ACL0:
                current_accel_level = 0;
                return true;
            case MS_ACL1:
                current_accel_level = 1;
                return true;
            case MS_ACL2:
                current_accel_level = 2;
                return true;
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
                send_repeated_movement(-current_grid_size, 0);
                return false;
            case MS_GRID_RIGHT:
                send_repeated_movement(current_grid_size, 0);
                return false;
            case MS_GRID_UP:
                send_repeated_movement(0, -current_grid_size);
                return false;
            case MS_GRID_DOWN:
                send_repeated_movement(0, current_grid_size);
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
