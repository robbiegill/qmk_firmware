/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb_qmk.h"
#include "timer.h"

#define BASE 0
#define HIDDEN 1
#define EMPTY 2

#define ______ KC_TRNS

#define MACRO_SFT_T_LPRN 0
#define SFT_T_LPRN M(MACRO_SFT_T_LPRN)
#define MACRO_SFT_T_RPRN 1
#define SFT_T_RPRN M(MACRO_SFT_T_RPRN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0:
   * ,-----------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9| 10|  -|  =|Yen|Bsp|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |
   * |------------------------------------------------------` Ent|
   * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  \|    |
   * |-----------------------------------------------------------|
   * |Shft   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO| Up|Sft|
   * |-----------------------------------------------------------|
   * |   ||Ctl|Alt|Cmd|   |   Spc   |Bsp|   |   |   ||Lft|Dwn|Rgh|
   * `-----------------------------------------------------------'
   */
  [BASE] = KEYMAP_JP(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_JYEN,KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_GRV, KC_ENT,
    SFT_T_LPRN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,    KC_UP,  KC_RSFT,
    MO(HIDDEN),  KC_LCTL, KC_LALT, KC_LGUI, MO(HIDDEN),      KC_SPC ,   KC_BSPC, KC_KANA, KC_RALT, KC_UP,  KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [HIDDEN] = KEYMAP_JP(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,
    ______, ______, ______, KC_EQL, ______, ______, ______, ______, ______, ______, KC_PIPE, KC_LPRN, KC_RPRN,
    ______, KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR, ______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ______, ______, ______, ______,
    SFT_T_RPRN, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_PGUP, KC_HOME,
    ______, ______, ______, ______, ______,   KC_UNDS     , KC_ENT, ______, ______, ______, ______, KC_PGDN, KC_END
  ),

  [EMPTY] = KEYMAP_JP(
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______,     ______    , ______, ______, ______, ______, ______, ______, ______
  )
};

static uint16_t key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t macro_id, uint8_t opt) {
  switch (macro_id) {
    case MACRO_SFT_T_LPRN: {
      if (record -> event.pressed) {
        key_timer = timer_read();
        register_code(KC_LSFT);
      } else {
        if (timer_elapsed(key_timer) < TAPPING_TERM) {
          register_code(KC_9);
          unregister_code(KC_9);
        }
        unregister_code(KC_LSFT);
      }
      break;
    }
    case MACRO_SFT_T_RPRN: {
      if (record -> event.pressed) {
        key_timer = timer_read();
        register_code(KC_LSFT);
      } else {
        if (timer_elapsed(key_timer) < TAPPING_TERM) {
          register_code(KC_0);
          unregister_code(KC_0);
        }
        unregister_code(KC_LSFT);
      }
      break;
    }
  }
  return MACRO_NONE;
}

const uint16_t PROGMEM fn_actions[] = {

};
