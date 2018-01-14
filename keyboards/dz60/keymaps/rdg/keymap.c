#include "dz60.h"

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

#define SCRNS3 LGUI(LCTL(LSFT(KC_3)))
#define SCRNS4 LGUI(LCTL(LSFT(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ZER] = LAYOUT_2_shifts(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  KC_INS, KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
    MOD_AG,  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,     KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,   KC_UP, KC_RSFT,
    MOD_CAG, KC_LALT, KC_LGUI,    MO(HDN),  SPC_HD2,  SPC_HD2,                                KC_BSPC, MO(OSY), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [HDN] = LAYOUT_2_shifts(
    KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  KC_DEL,
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR,  KC_GRV, _______,
    _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_ENT, KC_BSPC, KC_LBRC, KC_RBRC, KC_PIPE, KC_PGUP, _______,
    _______, _______, _______, _______, KC_UNDS,     KC_UNDS                                , _______, _______, KC_HOME, KC_PGDN, KC_END
  ),

  [HD2] = LAYOUT_2_shifts(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
    _______, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______    , _______, _______, _______, _______, _______
  ),

  [OSY] = LAYOUT_2_shifts(
    _______, _______, _______,  SCRNS3,  SCRNS4, _______, RGB_TOG, RGB_SMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,  RESET,
    _______, _______, _______,  SCRNS3,  SCRNS4, _______,  BL_DEC,  BL_TOGG,  BL_INC, BL_STEP, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,  KC_PWR, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______    ,  _______, _______, _______, _______, _______
  )
};

const uint16_t PROGMEM fn_actions[] = {

};

