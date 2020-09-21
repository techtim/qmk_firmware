/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#include "keycodes.h"

#ifdef ENCODER_ENABLE
#    include "encoder_utils.h"
#endif

#ifdef OLED_DRIVER_ENABLE
#    include "oled_utils.h"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |ESC/TAB |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | BSPC   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |LCTL/TAB|   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LSFT   |   Z  |   X  |   C  |   V  |   B  | Bspc | Raise|  |Adjust| Esc  |   N  |   M  | ,  < | . >  | /  ? | Lower  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Enc   | LALT |LGUI  |Space | Lower|  | Enter| Space| [ {  | ] }  |Raise |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
        MACRO_CTL_ESC,        KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        MT(MOD_LCTL, KC_TAB), KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,              KC_Z,   KC_X,   KC_C,   KC_V,    KC_B, KC_BSPC, MO(_RAISE), MO(_ADJUST), KC_ESC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_LOWER),
                                      ENC_MODE_L,  KC_LALT, KC_LGUI, KC_SPC,  MO(_LOWER), KC_ENT, KC_SPC, KC_LBRC, KC_RBRC,  MO(_RAISE)
    ),
/*
 * Lower Layer: Symbols, Navigation
 */
    [_LOWER] = LAYOUT(
      KC_TILD, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                                    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_DEL,
      _______, KC_HASH, KC_AT,   KC_LPRN, KC_RPRN, KC_GRV,                                     KC_PGUP, KC_LEFT, KC_UP,   KC_RGHT, KC_PIPE, KC_LSFT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_DEL, _______, _______, _______, KC_PGDN, KC_HOME, KC_DOWN, KC_END, S(KC_SLSH), _______,
                                 _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN, _______, _______, _______
    ),
/*
 * Raise Layer: Functions, Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      | F7   | F8   | F9   |      |                              |      | 7 &  | 8 *  | 9 (  | - _  |   *    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | F4   | F5   | F6   |      |                              |      | 4 *  | 5 %  | 6 ^  | = +  | RCTL   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | F1   | F2   | F3   |      |      |      |  |      |      |      | 1 !  | 2 @  | 3 #  | \ |  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      | 0 )  |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, KC_MPRV, KC_F7,   KC_F8,   KC_F9,   KC_VOLU,                                     _______, KC_7,    KC_8,    KC_9,    KC_MINS, KC_ASTR,
      _______, KC_MPLY, KC_F4,   KC_F5,   KC_F6,   KC_VOLD,                                     _______, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_RCTL,
      _______, KC_MNXT, KC_F1,   KC_F2,   KC_F3,   KC_MUTE, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_BSLASH, KC_LSFT,
                                 _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
 * CG_TOGG  Toggle Control and GUI swap on both sides
 * AG_TOGG Toggle Alt and GUI swap on both sides
 */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  AG_TOGG,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

void matrix_init_user(void) {
#ifdef ENCODER_ENABLE
    encoder_utils_init();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef ENCODER_ENABLE
        case ENC_MODE_L:
            if (record->event.pressed) {
                cycle_encoder_mode(true, false);
            }
            break;
        case ENC_MODE_R:
            if (record->event.pressed) {
                cycle_encoder_mode(false, false);
            }
            break;
#endif
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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void oled_task_user(void) { render_status(); }
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        encoder_action(get_encoder_mode(true), clockwise);
#    ifdef OLED_DRIVER_ENABLE
        oled_on();
#    endif
    } else if (index == 1) {
        encoder_action(get_encoder_mode(false), clockwise);
#    ifdef OLED_DRIVER_ENABLE
        oled_on();
#    endif
    }
}
#endif
