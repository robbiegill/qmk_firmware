#pragma once
#include "quantum.h"

#define _______ KC_TRNS

enum {
 ZER,
 HDN,
 NUM,
 HD2,
 OSY
};

#define CTL_ESC CTL_T(KC_ESC)
#define SFT_BSP SFT_T(KC_BSPC)
#define BPS_HD2 LT(HD2, KC_BSPC)
#define SPC_HD2 LT(HD2, KC_SPC)
#define MOD_CAG LCAG_T(KC_NO)
#define MOD_AG (QK_LGUI | QK_LALT)

#define CMD_CTL_1 LGUI(LCTL(KC_1))
#define CMD_CTL_2 LGUI(LCTL(KC_2))
#define CMD_CTL_3 LGUI(LCTL(KC_3))
#define CMD_CTL_4 LGUI(LCTL(KC_4))

#define SCRNS3 LGUI(LCTL(LSFT(KC_3)))
#define SCRNS4 LGUI(LCTL(LSFT(KC_4)))

#define LAYOUT_split_space_wrapper(...) LAYOUT_split_space(__VA_ARGS__)
#define LAYOUT_ca66_wrapper(...) LAYOUT(__VA_ARGS__)
//          1        2        3        4        5        6       7         8        9       10       11       12       13       14       15
//      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
#define __F_ROW_12________________________________________________________________________________________________ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12
#define __NUM_ROW_12______________________________________________________________________________________________ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL
#define __SHIFTED_NUM_ROW_10____________________________________________________________________ KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define __Q_ROW_12________________________________________________________________________________________________ KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC
#define __A_ROW_11_______________________________________________________________________________________ KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
#define __Z_ROW_10______________________________________________________________________________ KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH
#define __ARROW_ROW_4_____________________ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
#define __VOL_ROW_3______________ KC_VOLD, KC_VOLU, KC_MUTE
#define __RGB_ROW_9____________________________________________________________________ RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_M_P
