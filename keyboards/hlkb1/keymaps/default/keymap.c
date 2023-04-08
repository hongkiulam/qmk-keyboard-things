/* Copyright %YEAR% %YOUR_NAME%
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    IFSTATEMENT = SAFE_RANGE, // starts the enum at a safe range
    ARROWFUNC,
};

// Tap Dance declarations
enum {
	TD_H_LEFT,
	TD_J_DOWN,
	TD_K_UP,
	TD_L_RIGHT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_H_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_LEFT),
    [TD_J_DOWN] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_DOWN),
    [TD_K_UP] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_UP),
    [TD_L_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_RIGHT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

LAYOUT(
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
  KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MO(2), 
  KC_LCTL, KC_LGUI, KC_LALT, MO(3), KC_SPC, MO(1), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

LAYOUT(
  KC_CAPS, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, 
  KC_TRNS, KC_DLR, KC_PERC, KC_CIRC, KC_TRNS, KC_TRNS, KC_GRV, KC_MINS, KC_SCLN, KC_QUOT, KC_TRNS, 
  KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_SLSH, MO(4), 
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS),

LAYOUT(
  QK_BOOTLOADER, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, 
  KC_TRNS, KC_4, KC_5, KC_6, KC_0, KC_TRNS, KC_TILD, KC_UNDS, KC_COLN, KC_DQUO, KC_TRNS, 
  KC_TRNS, KC_1, KC_2, KC_3, KC_0, KC_TRNS, KC_TRNS, KC_LABK, KC_RABK, KC_QUES, KC_TRNS, 
  KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

LAYOUT(
    KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, IFSTATEMENT, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_VOLU, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, 
    KC_TRNS, KC_VOLD, KC_BRID, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ARROWFUNC, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case IFSTATEMENT:
            if (record->event.pressed) {
                SEND_STRING("if () {}"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            } else { // when keycode released
            }
            break;
        case ARROWFUNC:
            if (record->event.pressed) {
                SEND_STRING("() => {}"SS_TAP(X_LEFT));
            } else {
            }
            break;
    }
    return true;
}
