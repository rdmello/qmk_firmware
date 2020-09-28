/* Copyright 2019 Takuya Urakawa (dm9records.com)
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

enum plaid_layers {
    _DVORAK,
    _QWERTY,
    _MODIFIER,
    _RAISE,
    _LOWER,
    _ADJUST,
};

#define DVORAK DF(_DVORAK)
#define QWERTY DF(_QWERTY)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define TRANSPARENT_ROW \
     _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,

#define GUIESC LGUI_T(KC_ESC)
#define SFTENT KC_SFTENT
// #define SFTENT LSFT_T(KC_ENT)
[_DVORAK] = { 
    { KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC}, 
    { GUIESC,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_SLSH},
    {KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  SFTENT},
    {TRANSPARENT_ROW}
},

[_QWERTY] = { 
    { KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC},
    { GUIESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT},
    {KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SFTENT},
    {TRANSPARENT_ROW}
},

#define CTLSPC  LCTL_T(KC_SPC)
#define GUISPC  LGUI_T(KC_SPC)
[_MODIFIER] = {
    {TRANSPARENT_ROW},
    {TRANSPARENT_ROW},
    {TRANSPARENT_ROW},
    { ADJUST,   RAISE,   LOWER, KC_LGUI,   LOWER,  CTLSPC,      KC_SPC,   RAISE, KC_LALT, _______, _______, _______},
},

#define CAPSLCK KC_CAPSLOCK
[_RAISE] = { 
    {KC_TAB,  KC_BTN2, KC_MS_U, KC_BTN1, KC_PGUP, KC_HOME,      KC_GRV, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,  KC_DEL},
    {KC_LGUI, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN,  KC_END,     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSLS, CAPSLCK},
    {KC_LSFT,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ENT},
    {TRANSPARENT_ROW}
},

[_LOWER] = { 
    {KC_TAB,  KC_BTN2, KC_WH_U, KC_BTN1, _______, _______,     KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_DEL},
    {KC_ESC,  KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,     KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_PIPE, CAPSLCK},
    {KC_LSFT, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_ENT},
    {TRANSPARENT_ROW}
},

#define EERESET EEPROM_RESET
#define TGLCTLG MAGIC_TOGGLE_CTL_GUI
[_ADJUST] = {
    {_______, KC_MUTE, KC_VOLU, _______,  DVORAK, _______,     _______, _______, _______, TGLCTLG, EERESET,   RESET},
    {_______, KC_BRID, KC_VOLD, KC_BRIU,  QWERTY, _______,     _______, CAPSLCK, _______, _______, _______,  KC_F12},
    {_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11},
    {TRANSPARENT_ROW}
},
};
// clang-format on

// Caps Lock indicator!
// From: https://docs.qmk.fm/#/custom_quantum_functions?id=led-control
#define CAPS_OFF 0
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock == CAPS_OFF) {
        writePinLow(LED_GREEN);
    } else {
        writePinHigh(LED_GREEN);
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    state |= (1 << _MODIFIER);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }
