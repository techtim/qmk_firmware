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

enum custom_keycodes {
    MACRO_CTL_ESC = SAFE_RANGE,
};

// #ifdef LAYOUT_split_3x6_3_ex2
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [0] = LAYOUT_split_3x6_3_ex2(
//   //,--------------------------------------------------------------.                ,--------------------------------------------------------------.
//        KC_TAB,    DE_Q,    DE_W,    DE_E,    DE_R,    DE_T, DE_LCTL,                  KC_RCTL,    DE_Z, UEMLAUT,    DE_I, OEMLAUT,   DE_P,  KC_BSPC,
//   //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
//       KC_LCTL,LGUI_T(AEMLAUT),LALT_T(DE_S),LSFT_T(DE_D),LCTL_T(DE_F),DE_G,KC_LALT,  KC_RALT,DE_H,LCTL_T(DE_J),LSFT_T(DE_K),RALT_T(DE_L),LGUI_T(EXCLM), KC_QUOT,
//   //|--------+--------+--------+--------+--------+--------+--------'           `--------+--------+--------+--------+--------+--------+--------|
//       KC_LSFT,    DE_Y,    DE_X,    KC_C,    KC_V,    KC_B,                               DE_N,    DE_M, INTRPKT,  BRACES, BRACES_CL,  KC_ESC,
//   //|--------+--------+--------+--------+--------+--------+--------.           ,--------+--------+--------+--------+--------+--------+--------|
//                                           KC_ESC, TL_LOWR,  KC_ENT,              KC_SPC, TL_UPPR, KC_BSPC
//                                       //`--------------------------'           `--------------------------'

//   ),

//   [1] = LAYOUT_split_3x6_3_ex2(
//   //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
//        KC_TAB,    DE_1,    DE_2,    DE_3,    DE_4,    DE_5, KC_LCTL,    KC_RCTL,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0, KC_BSPC,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//       KC_LCTL,LGUI_T(),LCTL_T(),LALT_T(),LSFT_T(), XXXXXXX, KC_LALT,    KC_RALT, XXXXXXX, RCTL_T(),RSFT_T(),RALT_T(), LGUI_T(), XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
//       KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
//                                           KC_ESC, _______,   KC_ENT,   KC_SPC, _______, KC_BSPC
//                                       //`--------------------------'  `--------------------------'
//   ),

//   [2] = LAYOUT_split_3x6_3_ex2(
//   //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
//        KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_LCTL,    KC_RCTL, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//       KC_LCTL,LGUI_T(),LALT_T(),LSFT_T(),LCTL_T(), XXXXXXX, KC_LALT,    KC_RALT, KC_MINS,RCTL_T(),RSFT_T(),RALT_T(),LGUI_T(),  KC_GRV,
//   //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
//       KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
//   //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
//                                           KC_ESC, _______,  KC_ENT,    KC_SPC, _______, KC_BSPC
//                                       //`--------------------------'  `--------------------------'
//   ),

//   [3] = LAYOUT_split_3x6_3_ex2(
//   //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
//       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,RCTL_T(),RSFT_T(),RALT_T(),LGUI_T(), XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
//       RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
//                                           KC_ESC, _______,  KC_ENT,     KC_SPC, _______, KC_BSPC
//                                       //`--------------------------'  `--------------------------'
//   )
// };

// #else

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MACRO_CTL_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  MT(MOD_LCTL, KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  MO(1),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_SPC, KC_ENT,     LT(MO(2), KC_ENT), KC_LBRC, KC_RBRC
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                      S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_HASH,  KC_AT,   KC_LPRN, KC_RPRN, KC_GRV,                      KC_PGUP, KC_LEFT, KC_UP,   KC_RGHT, KC_PIPE, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PGDN, KC_HOME, KC_DOWN, KC_END, S(KC_SLSH), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,    KC_LGUI, KC_SPC, QK_UNDERGLOW_TOGGLE
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_VOLU, KC_MPRV,  KC_F9,   KC_F10, KC_F11,  KC_F12,                      _______, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_VOLD, KC_MPLY,  KC_F5,   KC_F6,   KC_F7,   KC_F8,                       KC_EQL, KC_4,    KC_5,    KC_6,  S(KC_EQL),  KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MUTE, KC_MNXT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,                       KC_0,   KC_1,    KC_2,    KC_3,   KC_BSLS,  KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,    _______, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

// #endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_CTL_ESC:
            if (!record->event.pressed)
                break;

            if (keyboard_report->mods & MOD_BIT(KC_LCTL))
                tap_code16(C(KC_TAB));
            else if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_LALT) )
                tap_code16(KC_TILD);
            else
                tap_code16(KC_ESC);
            break;
    }
    return true;
}
