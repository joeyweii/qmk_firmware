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

#include "config.h"
#include QMK_KEYBOARD_H

enum custom_keycodes {
    TMUX_1 = SAFE_RANGE,
    TMUX_2,
    TMUX_3,
    TMUX_4,
    TMUX_5,
    TMUX_C,
    TMUX_D,
    TMUX_F,
    TMUX_V,
    TMUX_H,
    TMUX_J,
    TMUX_K,
    TMUX_L,
    TMUX_S,
    VIMTAB1,
    VIMTAB2,
    VIMTAB3,
    VIMTAB4,
    VIMTAB5,
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_ENT:
            return 0;
        default:
            return 200;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_ENT:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(3),   MO(1), CTL_SPC,    SFT_ENT,   MO(2), XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  TMUX_1,  TMUX_2,  TMUX_3,  TMUX_4,  TMUX_5,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, VIMTAB1, VIMTAB2, VIMTAB3, VIMTAB4, VIMTAB5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, CTL_SPC,    SFT_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, CTL_SPC,    SFT_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  TMUX_S,  TMUX_D,  TMUX_F, XXXXXXX,                       TMUX_H,  TMUX_J,  TMUX_K,  TMUX_L, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,  TMUX_C,  TMUX_V, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, CTL_SPC,    SFT_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"1");
            } else {
            }
            break;
        case TMUX_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"2");
            } else {
            }
            break;
        case TMUX_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"3");
            } else {
            }
            break;
        case TMUX_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"4");
            } else {
            }
            break;
        case TMUX_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"5");
            } else {
            }
            break;
        case TMUX_C:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"c");
            } else {
            }
            break;
        case TMUX_D:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"d");
            } else {
            }
            break;
        case TMUX_F:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"-");
            } else {
            }
            break;
        case TMUX_V:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"|");
            } else {
            }
            break;
        case TMUX_H:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"h");
            } else {
            }
            break;
        case TMUX_J:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"j");
            } else {
            }
            break;
        case TMUX_K:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"k");
            } else {
            }
            break;
        case TMUX_L:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"l");
            } else {
            }
            break;
        case TMUX_S:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a")"[");
            } else {
            }
            break;
        case VIMTAB1:
            if (record->event.pressed) {
                SEND_STRING("1gt");
            } else {
            }
            break;
        case VIMTAB2:
            if (record->event.pressed) {
                SEND_STRING("2gt");
            } else {
            }
            break;
        case VIMTAB3:
            if (record->event.pressed) {
                SEND_STRING("3gt");
            } else {
            }
            break;
        case VIMTAB4:
            if (record->event.pressed) {
                SEND_STRING("4gt");
            } else {
            }
            break;
        case VIMTAB5:
            if (record->event.pressed) {
                SEND_STRING("5gt");
            } else {
            }
            break;
    }
    return true;
};
