// Copyright 2025 JP Roemer (@0rax)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
  [1] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
  [2] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
  [3] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
  [4] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
  [5] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
  [6] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE,          KC_MUTE,
        TO(1),   TO(2),   TO(3),
        TO(4),   TO(5),   TO(6)
    ),
    [1] = LAYOUT(
        KC_MUTE,          KC_MUTE,
        MC_0,    MC_1,    MC_2,
        MC_3,    MC_4,    TO(0)
    ),
    [2] = LAYOUT(
        KC_MUTE,          KC_MUTE,
        MC_5,    MC_6,    MC_7,
        MC_8,    MC_9,    TO(0)
    ),
    [3] = LAYOUT(
        KC_MUTE,          KC_MUTE,
        MC_10,   MC_11,   MC_12,
        MC_13,   MC_14,   TO(0)
    ),
    [4] = LAYOUT(
        KC_MUTE,          KC_MUTE,
        MC_15,   MC_16,   MC_17,
        MC_18,   MC_19,   TO(0)
    ),
    [5] = LAYOUT(
        KC_MUTE,          KC_MUTE,
        MC_20,   MC_21,   MC_22,
        MC_23,   MC_24,   TO(0)
    ),
    [6] = LAYOUT(
        KC_MUTE,          KC_MUTE,
        MC_25,   MC_26,   MC_27,
        MC_28,   MC_29,   TO(0)
    ),
};

#if defined(OLED_ENABLE)
#include "lib/oled.h"
bool oled_task_user(void) {
    render_logo();
    render_state();
    return false;
}
#endif // OLED_ENABLE
