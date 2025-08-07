#include QMK_KEYBOARD_H

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};

const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM CD_combo[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[] = {
    COMBO(we_combo, KC_SPC),
    COMBO(xc_combo, KC_TAB),

    COMBO(io_combo, KC_BSPC),
    COMBO(CD_combo, KC_ENT),

    COMBO(qw_combo, KC_ESC),
    COMBO(zx_combo, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_split_3x6_3(
      KC_NO, KC_Q, KC_W,         KC_E,         LALT_T(KC_R), KC_T, /*****************/ KC_Y, RALT_T(KC_U), KC_I,         KC_O,         KC_P,    KC_NO,
      KC_NO, KC_A, LGUI_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, /*****************/ KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RGUI_T(KC_L), KC_SCLN, KC_NO,
      KC_NO, KC_Z, KC_X,         KC_C,         LT(4, KC_V),  KC_B, /*****************/ KC_N, LT(5, KC_M),  KC_COMM,      KC_DOT,       KC_SLSH, KC_NO,
                                        KC_NO,    TT(1),    KC_NO, /*****************/ KC_NO,    TT(2),    KC_NO
   ),
   [1] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO,      MS_WHLL,    MS_WHLR,    KC_LALT,    KC_NO,      /*****************/ KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO,
      KC_NO, LCTL(KC_A), KC_LGUI,    KC_LSFT,    KC_LCTL,    KC_NO,      /*****************/ KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO,
      KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B), /*****************/ KC_NO, KC_7, KC_8, KC_9, KC_0,  KC_NO,
                                            KC_NO,    TG(1),    KC_NO, /*****************/ KC_NO,    MO(3),    KC_NO
   ),
   [2] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO,  MS_WHLD, KC_UP,   MS_WHLU,  KC_NO, /*****************/ KC_NO, KC_RALT, MS_WHLL, MS_WHLR, KC_NO, KC_NO,
      KC_NO, KC_NO,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, /*****************/ KC_NO, KC_RCTL, KC_RSFT, KC_RGUI, KC_NO, KC_NO,
      KC_NO, KC_END, KC_PGDN, KC_PGUP, KC_HOME,  KC_NO, /*****************/ KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
                             KC_NO,    MO(3),    KC_NO, /*****************/ KC_NO,    TG(2),    KC_NO
   ),
   [3] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_NO, /*****************/ KC_NO, KC_F10, KC_F11,  KC_F12,  KC_PSCR, KC_NO,
      KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_NO, /*****************/ KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_VOLU, KC_NO,
      KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, /*****************/ KC_NO, KC_DEL, KC_END,  KC_PGDN, KC_VOLD, KC_NO,
                   KC_NO,    KC_TRNS,    KC_NO, /*****************/ KC_NO,    KC_TRNS,    KC_NO
   ),
   [4] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, /*****************/ KC_NO, RSFT(KC_MINS), RSFT(KC_QUOT), RSFT(KC_EQL), RSFT(KC_BSLS), KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, /*****************/ KC_NO, KC_MINS,       KC_QUOT,       KC_EQL,       KC_BSLS,       KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, /*****************/ KC_NO, RSFT(KC_LBRC), KC_LBRC,       KC_RBRC,      RSFT(KC_RBRC), KC_NO,
                       KC_NO,    KC_NO,    KC_NO, /*****************/ KC_NO,    KC_NO,    KC_NO
   ),
   [5] = LAYOUT_split_3x6_3(
      KC_NO, LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_NO, /*****************/ KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_GRV,       LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_NO, /*****************/ KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, LSFT(KC_0),   LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_NO, /*****************/ KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,
                                           KC_NO,    KC_NO,    KC_NO, /*****************/ KC_NO,    KC_NO,    KC_NO
   )
   //[X] = LAYOUT_split_3x6_3(
   //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   //   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /*****************/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   //                  KC_NO,    KC_NO,    KC_NO, /*****************/ KC_NO,    KC_NO,    KC_NO
   //),
};
