/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum custom_keycodes {
  LOGOFF = SAFE_RANGE,
  SLEEP,
  QUIT
};

enum {
  TD_QUIT_SLEEP = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Quit, twice for Sleep
  [TD_QUIT_SLEEP]  = ACTION_TAP_DANCE_DOUBLE(QUIT, SLEEP)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      |                    |
        | Press: Mute       | Home | Brightness+        |
        | Hold: Layer 2     | Up   | Brightness-        |
        | Left              | Down | Logoff              |
     */
    [0] = LAYOUT(
        KC_MUTE, KC_PGUP, KC_BRIU,
        MO(1)  , KC_PGDOWN  , KC_BRID,
        TD(TD_QUIT_SLEEP), KC_MPLY, LOGOFF
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        KC_TRNS, BL_TOGG, BL_INC,
        _______, BL_BRTG, BL_DEC,
        RESET, KC_TRNS , KC_TRNS
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOGOFF:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LGUI)SS_TAP(X_Q)SS_UP(X_LSHIFT)SS_UP(X_LGUI));
        }
        return false;
        break;
    }
  switch (keycode) {
    case SLEEP:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)SS_TAP(X_MEDIA_EJECT)SS_UP(X_LALT)SS_UP(X_LGUI));
        }
        return false;
        break;
    }
  switch (keycode) {
    case QUIT:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_Q)SS_UP(X_LGUI));
        }
        return false;
        break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
