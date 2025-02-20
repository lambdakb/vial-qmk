// Copyright 2025 JP Roemer (@0rax)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _NUM,
    _NAV,
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_NUM] = {
    ENCODER_CCW_CW(KC_BRID, KC_BRIU), /* First encoder */
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU), /* Second encoder */
  },
  [_NAV] = {
    ENCODER_CCW_CW(KC_BRID, KC_BRIU), /* First encoder */
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU), /* Second encoder */
  }
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_DBL0:
        if (record->event.pressed) {
            tap_code16(KC_0);
            tap_code16(KC_0);
        }
        return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────┬────┬────┬────┐
     * │Esc │Tab │Pscr│TO1 │
     * └────┴────┴────┴────┘
     * ┌────┬────┬────┬────┐
     * │NumL│  / │  * │Bspc│
     * ├────┼────┼────┼────┤
     * │  7 │  8 │  9 │ -  │
     * ├────┼────┼────┼────┤
     * │  4 │  5 │  6 │ +  │
     * ├────┼────┼────┼────┤
     * │  1 │  2 │  3 │    │
     * ├────┼────┼────┤Entr│
     * │  0 │ 00 │  . │    │
     * └────┴────┴────┴────┘
     */
    [_NUM] = LAYOUT_numpad_6x4(
        KC_ESC,  KC_TAB,  KC_PSCR, TO(_NAV),
        KC_NUM,  KC_PSLS, KC_PAST, KC_BSPC,
        KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_DBL0, KC_PDOT, KC_PENT
    ),

    /*
     * ┌────┬────┬────┬────┐
     * │Rst │Tab │Pscr│TO0 │
     * └────┴────┴────┴────┘
     * ┌────┬────┬────┬────┐
     * │Prev│Play│Next│Mute│
     * ├────┼────┼────┼────┤
     * │Home│  ↑ │PgUo│    │
     * ├────┼────┼────┼────┤
     * │  ← │    │ →  │    │
     * ├────┼────┼────┼────┤
     * │End │  ↓ │PgDn│    │
     * ├────┼────┼────┤Entr│
     * │Ins │    │Del │    │
     * └────┴────┴────┴────┘
     */
    [_NAV] = LAYOUT_numpad_6x4(
        QK_BOOT, _______, _______, TO(_NUM),
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,
        KC_HOME, KC_UP,   KC_PGUP, XXXXXXX,
        KC_LEFT, XXXXXXX, KC_RGHT, XXXXXXX,
        KC_END,  KC_DOWN, KC_PGDN,
        KC_INS,  XXXXXXX, KC_DEL,  _______
    )
};

#if defined(OLED_ENABLE)
#include "lib/oled.h"
bool oled_task_user(void) {
    render_logo();
    render_state();
    return false;
}
#endif // OLED_ENABLE
