// Copyright 2025 JP Roemer (@0rax)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

#if defined(OLED_ENABLE)
#include <oled_driver.h>

void render_logo(void);
void render_state(void);

#endif // OLED_ENABLE
