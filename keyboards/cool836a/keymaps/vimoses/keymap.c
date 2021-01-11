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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _vimose,
    _N,         //Number Layer
    _M,         //Marks Layer
    _C,         //Corsur Layer
    _MS,       //Mouse Controlling Layer
    _NULL       //Empty Leyer for creating new one
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_vimose] = LAYOUT(
        LT(_C, KC_TAB),  KC_G,             KC_J,          KC_K,         KC_H,         KC_L,                               KC_F,         KC_P,  KC_Y,   KC_D, KC_Z, LT(_MS, KC_BSPC), \
        CTL_T(KC_SCLN),  KC_I,             KC_O,          KC_T,         KC_U,         KC_N,                               CTL_T(KC_Q),  KC_A,  KC_E,   KC_M, KC_S, CTL_T(KC_MINS),    \
        LSFT_T(KC_ESC),  LT(_MS, KC_COMM), GUI_T(KC_DOT), LALT_T(KC_W), LT(_M, KC_R), LSFT_T(KC_SPC),   LT(_N, KC_ENTER), LT(_M, KC_B), KC_V,  KC_C,   KC_X,       LT(_C, KC_ENT)
    ),
    //number
    [_N] = LAYOUT(
        KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,   KC_9,    KC_0,   _______,\
        KC_LCBR,  KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_RCBR,             KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  _______,\
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      _______, _______, _______, _______,     KC_F11,  KC_F12
    ),
    //marks
    [_M] = LAYOUT(
        KC_GRAVE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_TILD, KC_CIRC, KC_DLR,  KC_LABK, KC_RABK, KC_DEL, \
        KC_COLN,  KC_PLUS, KC_MINS, KC_ASTR, KC_DQUO, KC_QUOT,             KC_UNDS, KC_HOME, KC_END,  KC_AMPR, KC_PIPE,  KC_EQL,\
        KC_BSLS,  KC_SLSH, KC_DOT,  KC_QUES, _______, KC_MUTE,    KC_MPLY, _______, KC_VOLD, KC_VOLU,      KC_MPRV,    KC_MNXT
    ),  
    //cursor
    [_C] = LAYOUT(
        _______, KC_BRID, KC_BRIU, _______,  KC_SLEP, KC_PWR,               _______, KC_PGUP, KC_PGDN, _______, _______, _______,\
        _______, KC_PSCR, KC_SLCK, KC_PAUSE, KC_INT5, _______,              _______, KC_INT4, KC_UP,   _______, _______, _______,\
        KC_CAPS, KC_INS,  _______, _______,  _______, _______,     _______, _______, KC_LEFT, KC_DOWN,     KC_RIGHT,     _______\
    ),
    //mouse1
    [_MS] = LAYOUT(
        _______, _______, KC_MS_BTN1, KC_MS_U, KC_MS_BTN1, KC_MS_BTN2,            _______, _______, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1, _______, \
        KC_WH_U, _______, KC_MS_L,    KC_MS_D, KC_MS_R,    _______,               _______, KC_WHOM, _______,    KC_MS_BTN4, KC_MS_BTN5, _______, \
        KC_WH_D, _______, KC_WH_L,    KC_WH_R, _______,    KC_ACL1,      _______, _______, _______,     _______,    KC_ACL1,   _______
    ),
    //Null
    [_NULL] = LAYOUT(
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______
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
