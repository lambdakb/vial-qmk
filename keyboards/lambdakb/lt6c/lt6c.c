// Copyright 2025 JP Roemer (@0rax)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void keyboard_pre_init_kb(void) {
    // Disable onboard user LED
    gpio_set_pin_output(GP25);
    gpio_write_pin_high(GP25);
    gpio_set_pin_output(GP16);
    gpio_write_pin_high(GP16);
    gpio_set_pin_output(GP17);
    gpio_write_pin_high(GP17);

    // Enable internal addressable RGB led (NeoPixel)
    gpio_set_pin_output(XIAO_RP2040_RGB_POWER_PIN);
    gpio_write_pin_high(XIAO_RP2040_RGB_POWER_PIN);

    // Call user pre init code
    keyboard_pre_init_user();
}
