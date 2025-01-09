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

const uint16_t PROGMEM qa_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM ws_combo[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM ed_combo[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM rf_combo[] = {KC_R, KC_F, COMBO_END};

const uint16_t PROGMEM uj_combo[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM ik_combo[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM ol_combo[] = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM pS_combo[] = {KC_P, KC_SCLN, COMBO_END};

const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

const uint16_t PROGMEM asdf_combo[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jklS_combo[] = {KC_J, KC_K, KC_L, KC_SCLN, COMBO_END};

const uint16_t PROGMEM edik_combo[] = {KC_E, KC_D, KC_I, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(qa_combo, KC_LALT),
    COMBO(ws_combo, KC_LGUI),
    COMBO(ed_combo, KC_LSFT),
    COMBO(rf_combo, KC_LCTL),

    COMBO(uj_combo, KC_RCTL),
    COMBO(ik_combo, KC_RSFT),
    COMBO(ol_combo, KC_RGUI),
    COMBO(pS_combo, KC_RALT),

    COMBO(rt_combo, KC_HOME),
    COMBO(fg_combo, KC_END),
    COMBO(vb_combo, KC_DEL),

    COMBO(yu_combo, KC_PGUP),
    COMBO(hj_combo, KC_PGDN),
    COMBO(nm_combo, KC_INS),

    COMBO(asdf_combo, KC_NO),
    COMBO(jklS_combo, KC_NO),

    COMBO(edik_combo, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_split_3x6_3(
      KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,        KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_NO,
      KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_NO,
      KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
            KC_ESC, KC_TAB, LT(1, KC_SPC),        LT(2, KC_BSPC), KC_ENT, KC_ESC

   ),
   [1] = LAYOUT_split_3x6_3(
      KC_NO, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),        KC_NO, LSFT(KC_MINS), LSFT(KC_EQL),  LSFT(KC_LBRC), LSFT(KC_RBRC), KC_NO,
      KC_NO, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),        KC_NO, KC_LEFT,       KC_DOWN,       KC_UP,         KC_RIGHT,      KC_NO,
      KC_NO, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,             KC_NO, LSFT(KC_GRV),  LSFT(KC_QUOT), LSFT(KC_BSLS), KC_NO,         KC_NO,
                                                  KC_NO, KC_NO, KC_TRNS,        MO(3), KC_NO, KC_NO
   ),
   [2] = LAYOUT_split_3x6_3(
      KC_NO, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,         KC_NO, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,  KC_NO,
      KC_NO, KC_6,  KC_7,  KC_8,  KC_9,  KC_0,         KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_GRV,  KC_QUOT, KC_BSLS, KC_NO,    KC_NO,
                           KC_NO, KC_NO, MO(3),        KC_TRNS, KC_NO, KC_NO
   ),
   [3] = LAYOUT_split_3x6_3(
      KC_NO, KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NO, KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10,        KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_PSCR, KC_NO,
      KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                           KC_NO, KC_NO, KC_TRNS,         KC_TRNS, KC_NO, KC_NO
   )
};
