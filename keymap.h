#pragma once

#include QMK_KEYBOARD_H
#include "keymap_us.h"

#include "quantum_keycodes.h"

// Layer definitions
enum layers {
    BASEMOD,
    NAV,
    NAVMOD,
    SYM,
    MOUSE,
    FN
};

// Custom keycodes
enum custom_keycodes {
    // Mouse movement keycodes
    MS_STEP_UP = SAFE_RANGE,
    MS_STEP_DOWN,
    MS_STEP_LEFT,
    MS_STEP_RIGHT,
    MS_GRID_LEFT,
    MS_GRID_RIGHT,
    MS_GRID_UP,
    MS_GRID_DOWN,
    MS_GRID_SIZE_RESET,
    MS_GRID_SIZE_UP,
    MS_GRID_SIZE_DOWN,
};

// // Grid movement configuration
// #define GRID_SIZE_DEFAULT 60
// #define GRID_SIZE_STEP 20
// #define GRID_SIZE_MIN 20
// #define GRID_SIZE_MAX 120

// For shared state variables
extern bool ik_ralt_pressed;
