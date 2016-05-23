/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include "hhkb_qmk.h"
#include "timer.h"
#include "action_layer.h"

#define BASE 0
#define HIDDEN 1
#define OS_LAYER 2
#define EMPTY 3

#define ______ KC_TRNS

#define MACRO_SFT_T_LPRN 0
#define MACRO_SFT_T_RPRN 1
#define MACRO_EMAIL 2
#define MACRO_HID_OS 3

#define SFT_T_LPRN M(MACRO_SFT_T_LPRN)
#define SFT_T_RPRN M(MACRO_SFT_T_RPRN)
#define M_EMAIL M(MACRO_EMAIL)
#define SCRNS3 LGUI(LCTL(LSFT(KC_3)))
#define SCRNS4 LGUI(LCTL(LSFT(KC_4)))


/* hhkb jp ~ layout
 * ,-----------------------------------------------------------.
 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9| 10|  -|  =|Yen|Bsp|
 * |-----------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |
 * |------------------------------------------------------` Ent|
 * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  `|    |
 * |-----------------------------------------------------------|
 * |Shft   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  \| Up|Sft|
 * |-----------------------------------------------------------|
 * |   ||Ctl|Alt|Cmd|   |   Spc   |Bsp|   |   |   ||Lft|Dwn|Rgh|
 * `-----------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = KEYMAP_JP(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_INS, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_GRV, KC_ENT,
    SFT_T_LPRN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,    KC_UP,  KC_RSFT,
    MO(HIDDEN),  KC_LCTL, KC_LALT, KC_LGUI, MO(HIDDEN),      KC_SPC ,  KC_BSPC, KC_AT, KC_RALT, M(MACRO_HID_OS),  KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [HIDDEN] = KEYMAP_JP(
    KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12, ______,  KC_DEL,
    ______, ______, ______, KC_EQL, ______, ______, ______, ______, ______, ______, KC_PIPE, KC_LPRN, KC_RPRN,
    ______, KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR, ______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ______, ______, ______, ______,
    SFT_T_RPRN, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_PGUP, ______,
    ______, ______, ______, ______, ______,     KC_UNDS    ,  KC_ENT, M_EMAIL, ______, ______, KC_HOME, KC_PGDN, KC_END
  ),

  [OS_LAYER] = KEYMAP_JP(
    ______, ______, ______, SCRNS3, SCRNS4, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______,     ______    , ______, ______, ______, ______, ______, ______, ______
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
    case MACRO_EMAIL: {
      if (record -> event.pressed) {
        return MACRO(
          I(7),
          T(R),
          T(O),
          T(B),
          T(B),
          T(I),
          T(E),
          D(LSFT),
          T(AT),
          U(LSFT),
          T(G),
          T(U),
          T(S),
          T(T),
          T(O),
          T(DOT),
          T(C),
          T(O),
          T(M),
          END
        );
      }
      break;
    }
    case MACRO_HID_OS: {
      if (record -> event.pressed) {
        layer_on(HIDDEN);
        layer_on(OS_LAYER);
      } else {
        layer_off(HIDDEN);
        layer_off(OS_LAYER);
      }
      break;
    }
  }
  return MACRO_NONE;
}

const uint16_t PROGMEM fn_actions[] = {

};
