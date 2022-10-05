/* Copyright 2020 Dennis Nguyen <u/nguyedt>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// layers
#define _BASE     0
#define _VIAL1    1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        _______, _______, KC_MUTE,
        _______, _______, MO(1)
    ),
    [_VIAL1] = LAYOUT(
        _______, _______, _______,
        _______, _______, _______
    ),
};

#ifdef RGBLIGHT_ENABLE
// Layer 0
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_TEAL}       // Light 3 LEDs, starting with LED 1
);

// Layer 1
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_CORAL}       // Light 3 LEDs, starting with LED 1
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer
);

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_TEAL);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// assign the rgb layers
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _VIAL1));
    return state;
}
#endif
