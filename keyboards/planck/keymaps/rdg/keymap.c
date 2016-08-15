// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum {
  ZER,
  HDN,
  NUM,
  HD2,
  OSY
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define CTL_ESC CTL_T(KC_ESC)
#define SFT_GRV SFT_T(KC_GRV)
#define BPS_HD2 LT(HD2, KC_BSPC)
#define MOD_CAG LCAG_T(KC_NO)

#define SCRNS3 LGUI(LCTL(LSFT(KC_3)))
#define SCRNS4 LGUI(LCTL(LSFT(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Zero
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |  HDN |    Space    |  Del |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ZER] = {
  {  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC },
  { CTL_ESC,    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT },
  { KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SFT_GRV },
  {  M(OSY), MOD_CAG, KC_LALT, KC_LGUI, MO(HDN), KC_SPC,  KC_SPC, BPS_HD2, KC_LEAD,  KC_DEL,  KC_INS, KC_BSLS }
},

/* Hidden
 * ,-----------------------------------------------------------------------------------.
 * |   [  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  ]   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Underscore |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[HDN] = {
  { KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RBRC },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_ENT, _______, KC_LBRC, KC_RBRC, _______ },
  { _______, _______, _______, _______, _______, KC_UNDS, KC_UNDS, _______, _______, _______, _______, _______ }
},
[NUM] = {
  { _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______ },
  { _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},
[HD2] = {
  {_______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______ },
  {_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______ },
  {_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______ },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},
[OSY] = {
  {_______, _______, _______,  SCRNS3,  SCRNS4, _______, _______, _______, _______, _______, _______, _______ },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  {_______, KC_VOLD, KC_VOLU, KC_MUTE,  KC_PWR, _______, _______, _______, _______, _______,   KC_UP, _______ },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT }
}

};

const uint16_t PROGMEM fn_actions[] = {

};

#ifdef AUDIO_ENABLE
  float tone_startup[][2]    = SONG(STARTUP_SOUND);
  float tone_encounters[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
    startup_user();
  #endif
}

#ifdef AUDIO_ENABLE
void startup_user()
{
  _delay_ms(20); // gets rid of tick
  PLAY_NOTE_ARRAY(tone_startup, false, 0);
}
#endif

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
    SEQ_TWO_KEYS (KC_C, KC_V) {
      PLAY_NOTE_ARRAY(tone_encounters, false, 0);
    }
  }
}
