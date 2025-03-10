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
    return achordion_opposite_hands(tap_hold_record, other_record);
}

const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM mC_combo[] = {KC_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(cv_combo, KC_SPC),
    COMBO(er_combo, KC_TAB),

    COMBO(mC_combo, KC_BSPC),
    COMBO(ui_combo, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_split_3x6_3(
      KC_NO, KC_Q, LALT_T(KC_W), KC_E,         KC_R,         KC_T, /*****************/ KC_Y, KC_U,         KC_I,         RALT_T(KC_O),   KC_P,    KC_NO,
      KC_NO, KC_A, LGUI_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, /*****************/ KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RGUI_T(KC_L),   KC_SCLN, KC_NO,
      KC_NO, KC_Z, LT(5, KC_X),  KC_C,         KC_V,         KC_B, /*****************/ KC_N, KC_M,         KC_COMM,      LT(6, KC_DOT),  KC_SLSH, KC_NO,
                                       KC_NO,    OSL(1),    KC_NO, /*****************/ KC_NO,    OSL(2),    KC_NO
   ),
   [1] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, OSM(MOD_LALT), KC_NO,         KC_NO,         KC_NO, /*****************/ KC_NO, MS_WHLL, KC_UP,   MS_WHLR,  MS_WHLU, KC_NO,
      KC_NO, KC_NO, OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_NO, /*****************/ KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, MS_WHLD, KC_NO,
      KC_NO, KC_NO, KC_NO,         KC_NO,         KC_NO,         KC_NO, /*****************/ KC_NO, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, KC_NO,
                                           KC_NO,    KC_TRNS,    KC_NO, /*****************/ KC_NO,    MO(3),    KC_NO
   ),
   [2] = LAYOUT_split_3x6_3(
      KC_NO, KC_CAPS, KC_1, KC_2, KC_3, KC_NO, /*****************/ KC_NO, KC_NO,         KC_NO,         OSM(MOD_RALT), KC_NO, KC_NO,
      KC_NO, KC_ESC,  KC_4, KC_5, KC_6, KC_NO, /*****************/ KC_NO, OSM(MOD_RCTL), OSM(MOD_RSFT), OSM(MOD_RGUI), KC_NO, KC_NO,
      KC_NO, KC_0,    KC_7, KC_8, KC_9, KC_NO, /*****************/ KC_NO, KC_NO,         KC_NO,         KC_NO,         KC_NO, KC_NO,
                    KC_NO,    MO(3),    KC_NO, /*****************/ KC_NO,    KC_TRNS,    KC_NO
   ),
   [3] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_NO, /*****************/ KC_NO, KC_F10, KC_F11,  KC_F12,  KC_PSCR, DF(4),
      KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_NO, /*****************/ KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_VOLU, DF(4),
      KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, /*****************/ KC_NO, KC_DEL, KC_END,  KC_PGDN, KC_VOLD, DF(4),
                   KC_NO,    KC_TRNS,    KC_NO, /*****************/ KC_NO,    KC_TRNS,    KC_NO
   ),
   [4] = LAYOUT_split_3x6_3(
      KC_T, KC_TAB,  KC_Q, KC_W, KC_E, KC_R, /*****************/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,    DF(0),
      KC_G, KC_CAPS, KC_A, KC_S, KC_D, KC_F, /*****************/ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, DF(0),
      KC_B, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, /*****************/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, DF(0),
              KC_ESC,    KC_LALT,    KC_SPC, /*****************/ KC_BSPC,    KC_ENT,    KC_LGUI
   ),
   [5] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, RSFT(KC_MINS), RSFT(KC_QUOT), RSFT(KC_EQL), RSFT(KC_BSLS), KC_NO,
      KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, KC_MINS,       KC_QUOT,       KC_EQL,       KC_BSLS,       KC_NO,
      KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, RSFT(KC_LBRC), KC_LBRC,       KC_RBRC,      RSFT(KC_RBRC), KC_NO,
                       KC_NO,    KC_NO,    KC_NO, /*****************/ KC_NO,    KC_NO,    KC_NO
   ),
   [6] = LAYOUT_split_3x6_3(
      KC_NO, LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,
      KC_NO, KC_GRV,       LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,
      KC_NO, LSFT(KC_0),   LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO,
                                           KC_NO,    KC_NO,    KC_NO, /*****************/ KC_NO,    KC_NO,    KC_NO
   )
   //[X] = LAYOUT_split_3x6_3(
   //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   //                  KC_NO,    KC_NO,    KC_NO, /*****************/ KC_NO,    KC_NO,    KC_NO
   //),
};
