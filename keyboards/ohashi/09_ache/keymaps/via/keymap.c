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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _eucalyn,
    _N,         //Number Layer
    _M,         //Marks Layer
    _C,         //Corsur Layer
    _WF,         //Wheel and Functions
    _MD,          //controlling Media and 9keys like INS
    _SK         //shortcuts
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*[_dvorak] = LAYOUT(
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,             KC_ESC,       KC_LGUI, KC_F, KC_G, KC_C, KC_R, KC_L,  LT(_O, KC_BSPC), 
        KC_LSFT, KC_A,    KC_O,    KC_E,   KC_U, KC_I,             KC_LALT,      KC_1,    KC_D, KC_H, KC_T, KC_N, KC_S,  KC_ENT, 
        KC_LCTL, KC_SCLN, KC_Q,    KC_J,   KC_K, LT(_qwe_N, KC_X), KC_SPC,       KC_3,    KC_B, KC_M, KC_W, KC_V, KC_Z,  KC_0
    ),
    [_qwe_N] = LAYOUT(
        KC_GRAVE, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    _______,       _______, _______, _______, _______, _______, _______, _______,
        KC_ENTER, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    _______,       _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______, ___ 
    ),
    [_qwerty] = LAYOUT(
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,             KC_ESC,       KC_LGUI, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    LT(_O, KC_BSPC), 
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,             KC_LALT,      KC_1,    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_ENT, 
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, LT(_qwe_N, KC_B), KC_SPC,       KC_3,    KC_N, KC_M, KC_COMM, KC_DOT,KC_SLSH,  KC_0
    ),*/
    [_eucalyn] = LAYOUT(
        LT(_C, KC_Q),    KC_W,         KC_B,         KC_F,        LGUI_T(KC_COMM),     LT(_C, KC_M),  KC_R,   LT(_C, KC_D), KC_Y,  LT(_SK,KC_P),
        KC_A,            KC_O,         KC_E,         KC_U,        KC_I,                KC_G,          KC_T,   KC_K,         KC_N,  LT(_WF,KC_S),
        LCTL_T(KC_Z),    LSFT_T(KC_X), LALT_T(KC_C), LT(_WF,KC_V),LCTL_T(KC_DOT),      LT(_M,KC_BSPC),KC_H,   KC_J,         KC_L,  LT(_MD,KC_ESC),
        KC_F15,                                 LT(_M, KC_TAB), LSFT_T(KC_SPC),        LT(_N,KC_ENT), LT(_M,KC_F16),               LALT(KC_GRAVE)
    ),
    [_N] = LAYOUT(
        _______, _______, KC_DQUO, KC_QUOT, KC_GRAVE,         KC_COMM, KC_7, KC_8, KC_9, KC_PLUS,
        KC_COLN, KC_EQL,  KC_UNDS, KC_MINS, KC_TILD,          KC_DOT,  KC_4, KC_5, KC_6, KC_ASTR,
        KC_SCLN, _______, _______,_______,  KC_SLSH,          KC_0,    KC_1, KC_2, KC_3, KC_SLSH,
        _______,                  KC_F15, LALT(KC_GRAVE),     KC_DOT, KC_0,             _______
    ),
    //Marks
    [_M] = LAYOUT(
        KC_EXLM, KC_QUES, KC_AMPR, KC_PIPE, KC_BSLS,         KC_COMM, KC_7, KC_8, KC_9, KC_PLUS,
        KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______,         KC_DOT,  KC_4, KC_5, KC_6, KC_ASTR,
        KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_SLSH,         KC_0,    KC_1, KC_2, KC_3, KC_SLSH,
        _______,                  KC_F15, LALT(KC_GRAVE),    KC_DOT, KC_0,             _______
    ),
    //Cursor
    [_C] = LAYOUT(
        _______,     KC_BSPC, KC_UP,   KC_DEL,   KC_ENT,       KC_PGUP, _______, _______, _______, _______,
        KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,       KC_PGDN, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
        _______,           _______, _______,       _______, _______,           _______
    ),
    //Wheel and Func
    [_WF] = LAYOUT(
        _______, _______,     _______,     KC_WH_U, _______,       KC_F12, KC_F7,KC_F8,KC_F9, _______,
        _______, _______,     _______,     KC_WH_D, _______,       KC_F11, KC_F4,KC_F5,KC_F6, _______,
        _______, KC_WH_L, KC_WH_R, _______,     _______,       KC_F10, KC_F1,KC_F2,KC_F3, _______,
        _______,                   _______,     _______,       _______,KC_F10,             _______
    ),
    //Media
    [_MD] = LAYOUT(
        _______, KC_PSCR,KC_SLCK, KC_PAUS, _______,       _______, _______, KC_MPRV, KC_MNXT, KC_VOLU,
        _______, KC_INS, KC_HOME, KC_PGUP, _______,       _______, _______, KC_MPLY, KC_MUTE, KC_VOLD,
        _______, KC_DEL, KC_END,  KC_PGDN, _______,       _______, _______, _______, _______, _______,
        _______,           _______, _______,       _______, _______,           _______
    ),
    //Shot Cut
    [_SK] = LAYOUT(
        TO(_eucalyn),TO(_maltron),TO(_qwerty),___, _______,       _______, _______, _______, _______, _______,
        _______,         _______,         _______,        _______, _______,       _______, KC_WHOM, KC_WBAK, KC_WFWD, _______,
        RESET,       _______,         _______,        _______, _______,       _______, _______, _______, _______, _______,
        _______,           _______, _______,       _______, _______,           _______
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
