#include "hhkb.h"

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
#define MOD_CAG LCAG_T(KC_NO)

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
  [ZER] = KEYMAP_JP(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_INS,  KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,
    CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_GRV, KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,   KC_UP, KC_RSFT,
    MO(OSY),  MOD_CAG, KC_LALT, KC_LGUI, MO(HDN),      KC_SPC,    BPS_HD2,  KC_LEAD, KC_LSFT,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [HDN] = KEYMAP_JP(
    KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  KC_DEL,
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_ENT, _______, KC_LBRC, KC_RBRC, _______, KC_PGUP, _______,
    _______, _______, _______, _______, _______,     KC_UNDS     , _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
  ),

  [NUM] = KEYMAP_JP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______    , _______, _______, _______, _______, _______, _______, _______
  ),

  [HD2] = KEYMAP_JP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______, _______,
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______    , _______, _______, _______, _______, _______, _______, _______
  ),

  [OSY] = KEYMAP_JP(
    _______, _______, _______,  SCRNS3,  SCRNS4, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,  SCRNS3,  SCRNS4, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_VOLD, KC_VOLU, KC_MUTE,  KC_PWR, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______    , _______, _______, _______, _______, _______, _______, _______
  )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case OSY:
      if (record->event.pressed) {
        layer_on(HD2);
        layer_on(OSY);
      } else {
        layer_off(HD2);
        layer_off(OSY);
      }
      break;
  }
  return MACRO_NONE;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY (KC_E) {
      SEND_STRING(EMAIL);
    }
  }
}

const uint16_t PROGMEM fn_actions[] = {

};
