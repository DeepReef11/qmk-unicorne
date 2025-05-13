#include QMK_KEYBOARD_H
/* #include "pointing_device.h" */

// Initialize the pointing device
void pointing_device_init(void) {
    // No initialization needed for this driver
}

// Get the state of the pointing device
void pointing_device_task(void) {
    // Do nothing by default - movements only come from keycodes
}

// Custom handler to only allow intentional movement
void pointing_device_set_cpi(uint16_t cpi) {
    // No CPI to set
}

// When we don't have a real pointing device, report is only modified by keycodes
report_mouse_t pointing_device_get_report(void) {
    static report_mouse_t report = {0};
    return report;
}

// Called by our grid movement code to set the report
void pointing_device_set_report(report_mouse_t report) {
    // Actually send the movement
    host_mouse_send(&report);
}
