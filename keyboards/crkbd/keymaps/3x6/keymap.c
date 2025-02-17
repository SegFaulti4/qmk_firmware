/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "features/achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    return true;
}

void housekeeping_task_user(void) {
    achordion_task();
}

bool achordion_chord(
    uint16_t tap_hold_keycode,
    keyrecord_t* tap_hold_record,
    uint16_t other_keycode,
    keyrecord_t* other_record
) {
    switch (tap_hold_keycode) {
        case LT(1, KC_SPC):
            return true;
        case LT(2, KC_BSPC):
            return true;
    }
    return achordion_opposite_hands(tap_hold_record, other_record);
}

const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(rt_combo, KC_HOME),
    COMBO(vb_combo, KC_END),

    COMBO(yu_combo, KC_PGUP),
    COMBO(nm_combo, KC_PGDN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_split_3x6_3(
      KC_NO, KC_Q, LALT_T(KC_W), KC_E,         KC_R,         KC_T, /*****************/ KC_Y, KC_U,         KC_I,         RALT_T(KC_O),   KC_P,    KC_NO,
      KC_NO, KC_A, LGUI_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, /*****************/ KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RGUI_T(KC_L),   KC_SCLN, KC_NO,
      KC_NO, KC_Z, KC_X,         KC_C,         KC_V,         KC_B, /*****************/ KC_N, KC_M,         KC_COMM,      KC_DOT,         KC_SLSH, KC_NO,
                             KC_LCTL,    KC_TAB,    LT(1, KC_SPC), /*****************/ LT(2, KC_BSPC),    KC_ENT,    KC_ESC
   ),
   [1] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_1, KC_2, KC_3,  KC_4, /******************/ KC_GRV,  KC_MINS, KC_UP,   KC_EQL,   KC_NO, KC_NO,
      KC_NO, KC_NO, KC_5, KC_6, KC_7,  KC_8, /******************/ KC_BSLS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_9, KC_0, KC_NO, KC_NO, /*****************/ KC_NO,   KC_QUOT, KC_LBRC, KC_RBRC,  KC_NO, KC_NO,
                 KC_NO,    KC_NO,    KC_TRNS, /*****************/ MO(3),    KC_NO,    KC_NO
   ),
   [2] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), /*****************/ RSFT(KC_GRV),  RSFT(KC_MINS), KC_UP,         RSFT(KC_EQL),  KC_NO, KC_NO,
      KC_NO, KC_NO, LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), /*****************/ RSFT(KC_BSLS), KC_LEFT,       KC_DOWN,       KC_RIGHT,      KC_NO, KC_NO,
      KC_NO, KC_NO, LSFT(KC_9), LSFT(KC_0), KC_NO,      KC_NO, /**********************/ KC_NO,         RSFT(KC_QUOT), RSFT(KC_LBRC), RSFT(KC_RBRC), KC_NO, KC_NO,
                                         KC_NO,    KC_NO,    MO(3), /*****************/ KC_TRNS,    KC_NO,    KC_NO
   ),
   [3] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_F1, KC_F2,  KC_F3,  KC_F4, /******************/ KC_INS, KC_PSCR, KC_CAPS, KC_RALT, KC_NO, DF(4),
      KC_NO, KC_NO, KC_F5, KC_F6,  KC_F7,  KC_F8, /******************/ KC_DEL, KC_RCTL, KC_RSFT, KC_RGUI, KC_NO, DF(4),
      KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, /*****************/ KC_NO,  KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, DF(4),
                      KC_NO,    KC_NO,    KC_TRNS, /*****************/ KC_TRNS,    KC_NO,    KC_NO
   ),
   [4] = LAYOUT_split_3x6_3(
      KC_T, KC_TAB,  KC_Q, KC_W, KC_E, KC_R, /*****************/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,    DF(0),
      KC_G, KC_LSFT, KC_A, KC_S, KC_D, KC_F, /*****************/ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, DF(0),
      KC_B, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, /*****************/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, DF(0),
              KC_ESC,    KC_LALT,    KC_SPC, /*****************/ KC_BSPC,    KC_ENT,    KC_LGUI
   )
};
