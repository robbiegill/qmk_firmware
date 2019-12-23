
#include QMK_KEYBOARD_H
#include "rdg.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ZER] = LAYOUT_gothic70_wrapper(
    KC_GESC, __NUM_ROW_12______________________________________________________________________________________________, KC_BSPC, KC_BSPC, CMD_CTL_1,
    KC_TAB , __Q_ROW_12________________________________________________________________________________________________, KC_BSLS,          CMD_CTL_2,
    CTL_ESC, __A_ROW_11_______________________________________________________________________________________, KC_ENT,  CMD_CTL_3,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, 
    MOD_CAG, KC_LALT, KC_LGUI, MO(HDN),  SPC_HD2,  SPC_HD2,  KC_BSPC, MO(OSY), KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [HDN] = LAYOUT_gothic70_wrapper(
     KC_GRV, __F_ROW_12________________________________________________________________________________________________,  KC_DEL,  KC_DEL, _______,
    _______, __SHIFTED_NUM_ROW_10____________________________________________________________________, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_BSPC, KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR,  KC_GRV, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_ENT, KC_BSLS, KC_LBRC, KC_RBRC, KC_PIPE, _______,
    _______, _______, _______, _______, KC_UNDS, KC_UNDS, _______, _______, _______, _______, _______
  ),
  [HD2] = LAYOUT_gothic70_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, __NUM_ROW_12______________________________________________________________________________________________, _______, _______,
    _______, _______, _______, _______, _______, _______, __ARROW_ROW_4_____________________, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [OSY] = LAYOUT_gothic70_wrapper(
    _______, _______, _______,  SCRNS3,  SCRNS4, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, __RGB_ROW_9____________________________________________________________________, _______, _______, _______, _______,
    _______, __VOL_ROW_3______________, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(F7);
  writePinLow(F7);
  // set NumLock LED to output and low
  setPinOutput(F6);
  writePinLow(F6);
  // set ScrollLock LED to output and low
  setPinOutput(F5);
  writePinLow(F5);
}

void matrix_scan_user(void) {

}


uint32_t layer_state_set_user(uint32_t state)
{
    if (state & (1<<1)) {
    writePinHigh(F5);
    } else if (state & (1<<2)) {
        writePinLow(F5);
        writePinHigh(F6);
    } else if (state & (1<<3)) {
        writePinHigh(F5);
        writePinHigh(F6);
    } else {
        writePinLow(F5);
        writePinLow(F6);
    }
    return state;
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(F7);
    } else {
        writePinLow(F7);
    }
}

