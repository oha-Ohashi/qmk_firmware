/* Copyright 2021 Ohashi
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
#define ___ _______

const uint16_t PROGMEM top[MATRIX_ROWS][MATRIX_COLS] = 
    LAYOUT(
        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, 
                          _______, _______, _______,     _______, _______, _______
    )
;

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _eucalyn,
    _N,         //Number Layer
    _M,         //Marks Layer
    _C,         //Corsur Layer
    _MD,        //controlling Media
    _RGB
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_eucalyn] = LAYOUT(
        LT(_C, KC_ESC),  LT(_C, KC_W), KC_B,         KC_F,        LGUI_T(KC_COMM),       LT(_C, KC_M),  KC_R,   LT(_C, KC_D), KC_Y,  LT(_MD,KC_P),
        KC_A,            KC_O,         KC_E,         KC_U,        KC_I,                  KC_G,          KC_T,   KC_K,         KC_N,  LT(_C,KC_S),
        LCTL_T(KC_Z),    LSFT_T(KC_X), LALT_T(KC_C), KC_V,        LCTL_T(KC_TAB),        KC_BSPC,       KC_H,   KC_J,         KC_L,  LT(_RGB,KC_Q),
                                       _______, LT(_N, KC_F15),   LSFT_T(KC_SPC),        LT(_M,KC_ENT), LT(_N,KC_F16), _______
    ),
    //Marks
    [_N] = LAYOUT(
        KC_EXLM, KC_QUES, KC_AMPR, KC_PIPE, KC_BSLS,     KC_COMM, KC_7, KC_8, KC_9, KC_PLUS,
        KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______,     KC_DOT,  KC_4, KC_5, KC_6, KC_ASTR,
        KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_SLSH,     KC_0,    KC_1, KC_2, KC_3, KC_SLSH,
        _______,                   _______, _______,     _______, KC_0,             _______
    ),
    [_M] = LAYOUT(
        KC_GRAVE,_______, KC_DQUO, KC_QUOT, KC_DOT,       _______, KC_AMPR, KC_ASTR,KC_LPRN, _______,
        KC_COLN, KC_EQL,  KC_UNDS, KC_MINS, KC_TILD,      _______, KC_DLR,  KC_PERC,KC_CIRC, _______,
        KC_SCLN, _______, _______,_______,  KC_SLSH,      _______, KC_EXLM, KC_AT,  KC_HASH, _______,
        _______,                  _______,   _______,      _______, _______,                   _______
    ),
    //Cursor
    [_C] = LAYOUT(
        _______, KC_BSPC, KC_UP,   KC_DEL,   KC_ENT,       KC_F12, KC_F7, KC_F8, KC_F9, _______,
        KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,       KC_F11, KC_F4, KC_F5, KC_F6, _______,
        _______, _______, KC_PGDN, KC_PGUP,  _______,      KC_F10, KC_F1, KC_F2, KC_F3, RESET,
        _______,                   _______,  _______,      _______, _______,            _______
    ),
    //Media
    [_MD] = LAYOUT(
        _______, _______, _______, KC_WH_U, _______,       _______, _______, _______, KC_MUTE, _______, 
        _______, _______, _______, KC_WH_D, _______,       _______, KC_WHOM, KC_WBAK, KC_WFWD, KC_VOLU, 
        _______, KC_WH_L, KC_WH_R, _______, _______,       _______, _______, _______, _______, KC_VOLD, 
        _______,                   _______, _______,       _______, _______,           ___
    ),
    //RGB
    [_RGB] = LAYOUT(
        _______, RGB_M_P, RGB_M_B, RGB_M_R,_______,       RGB_TOG,          RGB_HUI, RGB_SAI, RGB_VAI, _______,
        _______, RGB_M_SW,RGB_M_SN,RGB_M_K,_______,       RGB_MODE_FORWARD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
        _______, RGB_M_X, RGB_M_G, RGB_M_T,_______,       RGB_MODE_REVERSE, _______, _______, _______, _______,
        _______,           _______, _______,       _______, _______,           ___
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
