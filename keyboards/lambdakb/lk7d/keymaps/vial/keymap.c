// Copyright 2025 JP Roemer (@0rax)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
  },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────┬────┬────┐
     * │MUTE│    │MUTE│
     * ├────┼────┼────┤
     * │ M0 │ M1 │ M2 │
     * ├────┼────┼────┤
     * │ M3 │ M4 │ M5 │
     * └────┴────┴────┘
     */
    [0] = LAYOUT(
        KC_MUTE,          KC_MUTE,
        MC_0,    MC_1,    MC_2,
        MC_3,    MC_4,    MC_5
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
