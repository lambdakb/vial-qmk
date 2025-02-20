// Copyright 2025 JP Roemer (@0rax)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "oled.h"

#if defined(OLED_ENABLE)

void render_title(size_t x, size_t y, const char PROGMEM icon[2][7]) {
    for (size_t i = 0 ; i != 2 ; i++) {
        oled_set_cursor(x, y+i);
        oled_write_P(icon[i], false);
    }
}

void render_icon(size_t x, size_t y, const char PROGMEM icon[2][5]) {
    for (size_t i = 0 ; i != 2 ; i++) {
        oled_set_cursor(x, y+i);
        oled_write_P(icon[i], false);
    }
}

void render_logo(void) {
    static const char PROGMEM logo[4][6] = {
        { 0x80, 0x81, 0x82, 0x83, 0x84, 0x00 },
        { 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0x00 },
        { 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0x00 },
        { 0x85, 0x86, 0x87, 0x88, 0x89, 0x00 }
    };

    for (size_t i = 0 ; i != 4 ; i++) {
        oled_write_ln_P(logo[i], false);
    }
}

void render_state(void) {
    static const char PROGMEM kb_title[2][7] = {
        { 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0x00 },
        { 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0x00 }
    };
    static const char PROGMEM numlock_state[2][2][5] = {
        [0] = {
            { 0xB1, ' ', ' ', 0xBE, 0x00 },
            { 0xD1, ' ', ' ', 0xDE, 0x00 }
        },
        [1] = {
            { 0xB1, 0xBC, 0xBD, 0xBE, 0x00 },
            { 0xD1, 0xDC, 0xDD, 0xDE, 0x00 }
        },
    };
    uint16_t num_lock = 0;
    if (host_keyboard_led_state().num_lock) {
        num_lock = 1;
    }
    render_title(7, 0, kb_title);
    render_icon(17, 0, numlock_state[num_lock]);

    static const char PROGMEM layer_title[2][7] = {
        { 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0x00 },
        { 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0x00 },
    };
    static const char PROGMEM layer_text[4][2][5] = {
        [0] = {
            { 0xB1, 0xB2, 0xB3, 0xBE, 0x00 },
            { 0xD1, 0xD2, 0xD3, 0xDE, 0x00 }
        },
        [1] = {
            { 0xB1, 0xB4, 0xB5, 0xBE, 0x00 },
            { 0xD1, 0xD4, 0xD5, 0xDE, 0x00 }
        },
        [2] = {
            { 0xB1, 0xB6, 0xB7, 0xBE, 0x00 },
            { 0xD1, 0xD6, 0xD7, 0xDE, 0x00 }
        },
        [3] = {
            { 0xB1, 0xB8, 0xB9, 0xBE, 0x00 },
            { 0xD1, 0xD8, 0xD9, 0xDE, 0x00 }
        },
    };
    uint16_t layer = get_highest_layer(layer_state);
    render_title(7, 2, layer_title);
    render_icon(17, 2, layer_text[layer]);
}

#endif
