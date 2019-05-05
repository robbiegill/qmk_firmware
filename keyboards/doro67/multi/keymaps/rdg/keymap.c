/* Copyright 2019 ShadeDream
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
#include "rdg.h"

// #define _______ KC_TRNS
//
// enum {
//  ZER,
//  HDN,
//  NUM,
//  HD2,
//  OSY
// };
//
//
// #define CTL_ESC CTL_T(KC_ESC)
// #define SFT_BSP SFT_T(KC_BSPC)
// #define BPS_HD2 LT(HD2, KC_BSPC)
// #define SPC_HD2 LT(HD2, KC_SPC)
// #define MOD_CAG LCAG_T(KC_NO)
// #define MOD_AG (QK_LGUI | QK_LALT)
//
// #define SCRNS3 LGUI(LCTL(LSFT(KC_3)))
// #define SCRNS4 LGUI(LCTL(LSFT(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ZER] = LAYOUT_split_space_wrapper(
    KC_GESC, __NUM_ROW_12______________________________________________________________________________________________, KC_BSPC, CMD_CTL_1,
    KC_TAB , __Q_ROW_12________________________________________________________________________________________________, KC_BSLS, CMD_CTL_2,
    CTL_ESC, __A_ROW_11_______________________________________________________________________________________, KC_ENT,  CMD_CTL_3,
    KC_LSFT, __Z_ROW_10______________________________________________________________________________, KC_RSFT, KC_UP, CMD_CTL_4,
    MOD_CAG, KC_LALT, KC_LGUI, MO(HDN),  SPC_HD2,  SPC_HD2,  KC_BSPC, MO(OSY), KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [HDN] = LAYOUT_split_space_wrapper(
     KC_GRV, __F_ROW_12________________________________________________________________________________________________,  KC_DEL, _______,
    _______, __SHIFTED_NUM_ROW_10____________________________________________________________________, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_BSPC, KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR,  KC_GRV, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  KC_ENT, KC_BSLS, KC_LBRC, KC_RBRC, KC_PIPE, _______, _______,
    _______, _______, _______, _______, KC_UNDS, KC_UNDS, _______, _______, _______, _______, _______
  ),
  [HD2] = LAYOUT_split_space_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, __NUM_ROW_12______________________________________________________________________________________________, _______, _______,
    _______, _______, _______, _______, _______, _______, __ARROW_ROW_4_____________________, _______, _______, _______, _______,
    _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [OSY] = LAYOUT_split_space_wrapper(
    _______, _______, _______,  SCRNS3,  SCRNS4, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, __VOL_ROW_3______________, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


};
