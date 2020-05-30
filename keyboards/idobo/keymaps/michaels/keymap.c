/* Copyright 2017 Wunder
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

extern keymap_config_t keymap_config;

enum idobo_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCT
};

enum custom_keycodes {
  QMK_RACE = SAFE_RANGE,
  QMK_WINSCP,
  QMK_BUILD,
  QMK_LAYERS,
  QMK_HGPULL,
  QMK_SLEEP
};

enum {
  TD_SHIFT_CAPS = 0,
  TD_VOLD_MUTE = 1
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCT)

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_VOLD_MUTE]  = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* QWERTY
	 * .--------------------------------------------------------------------------------------------------------------------------------------.
	 * | TILDE  | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |   -    |    BACKSPACE    |   +    |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | {      | }      | BSLSH  |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	 * | ESC    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |      ENTER      |PRNTSCRN|
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	 * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHFT  |  UP    |        | VOLUP  |
	 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	 * |  LCTL  | FUNCT  | LALT	  |	LGUI   | LOWER  |      SPACE      | RAISE  | RGUI   | RCTRL  | FUNCT  | LEFT   | DOWN   | RIGHT  | VOLDOWN|
	 * '--------------------------------------------------------------------------------------------------------------------------------------'
	 */

	[_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
		KC_TILD,  			KC_1,     KC_2,     KC_3,   KC_4,   KC_5, 	KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,    KC_BSPC,     KC_BSPC,  KC_EQL, \
		KC_TAB,   			KC_Q,     KC_W,     KC_E,   KC_R,   KC_T, 	KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,  _______, \
		KC_GESC,  			KC_A,     KC_S,     KC_D,  	KC_F,   KC_G, 	KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_ENT,	  KC_ENT,    KC_PSCR, \
		TD(TD_SHIFT_CAPS),  KC_Z,     KC_X,     KC_C,  	KC_V,   KC_B, 	KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,    KC_UP,      _______,    KC_VOLU, \
		KC_LCTL,         MO(FUNCT), KC_LALT,  KC_LGUI, MO(LOWER), KC_SPC, KC_SPC, MO(RAISE), KC_LGUI, KC_RCTL, MO(FUNCT), KC_LEFT, KC_DOWN,   KC_RIGHT, TD(TD_VOLD_MUTE) \
	),

	/* LOWER
	 * .--------------------------------------------------------------------------------------------------------------------------------------.
	 * |        |        |        |        |        |        |        |        |        |        |        |        |                 |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	 * |   ~    |   !    |   @    |   #    |   $    |   %    |   ^    |   &    |   *    |   (    |   )    |        |        |        |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	 * |        |        |        |        |        |        |        |   _    |   +    |   {    |   }    |    |   |                 |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
	 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	 * |  LCTL  | FUNCT  | LALT	  |	LGUI   | LOWER  |      SPACE      | RAISE  | RGUI   | RCTRL  | FUNCT  |        |        |        |        |
	 * '--------------------------------------------------------------------------------------------------------------------------------------'
	 */

	[_LOWER] = LAYOUT_ortho_5x15( /* LOWER */
		_______,  _______,  _______,  _______,  _______, _______,_______,_______,_______,  _______,  _______,  _______,    _______,    _______,  _______, \
		KC_TILD,   KC_EXLM, KC_AT,	  KC_HASH,  KC_DLR,  KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,    _______,    _______,  _______, \
		_______,  _______,  _______,  _______,  _______, _______,_______,KC_UNDS,KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,    _______,    _______,  _______, \
		_______,  _______,  _______,  _______,  _______, _______,_______,_______,_______,  _______,  _______,  _______,    _______,    _______,  _______, \
		KC_LCTL,  MO(FUNCT),KC_LALT,  KC_LGUI,	MO(LOWER),KC_SPC,KC_SPC,MO(RAISE),KC_LGUI, KC_RCTL,  MO(FUNCT),_______,    _______,    _______, _______ \
	),

    /* RAISE
	 * .--------------------------------------------------------------------------------------------------------------------------------------.
	 * |        |        |        |        |        |        |        |        |        |        |        |        |                 |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	 * |   `    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |        |        |        |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	 * |        |        |        |        |        |        |        |   -    |   =    |   [    |   ]    |   \    |                 |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
	 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	 * |  LCTL  | FUNCT  | LALT	  |	LGUI   | LOWER  |      SPACE      | RAISE  | RGUI   | RCTRL  | FUNCT  |        |        |        |        |
	 * '--------------------------------------------------------------------------------------------------------------------------------------'
	 */

	[_RAISE] = LAYOUT_ortho_5x15( /* RAISE */
		_______,  _______,  _______,  _______,  _______,_______,_______,_______,_______,  _______,  _______,  _______,    _______,    _______,  _______, \
		KC_TILD,  KC_1,     KC_2,     KC_3,     KC_4,   KC_5, 	KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     _______,    _______,    _______,  _______, \
		_______,  _______,  _______,  _______,  _______,_______,_______,KC_MINS,KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,    _______,    _______,  _______, \
		_______,  _______,  _______,  _______,  _______,_______,_______,_______,_______,  _______,  _______,  _______,    _______,    _______,  _______, \
		KC_LCTL,  MO(FUNCT),KC_LALT,  KC_LGUI,	MO(LOWER),KC_SPC,KC_SPC,MO(RAISE),KC_LGUI,KC_RCTL, 	MO(FUNCT),_______,    _______,    _______, _______ \
	),

  	/* ADJUST
	 * .--------------------------------------------------------------------------------------------------------------------------------------.
	 * | RESET  |        |        |        |        |        |        |        |        |        |        |        |                 |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	 * |        |        |        |        |        | RGB_TOG|        |        | INSERT |        |        |        |        |        |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
  	 * |        |        | RAINBOW| PLAIN  |BREATHE | SWIRL  | SNAKE  | KNIGHT |  XMAS  |GRADIENT|        |        |                 |        |
	 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	 * |        | INC    | DEC    | HUE I  | HUE D  | SAT I  | SAT D  |        |        |        |        |        | BRIGHT |        |        |
	 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	 * |        |        |        |        |        |                 |        |        |        |        |        |  DIM   |        |        |
	 * '--------------------------------------------------------------------------------------------------------------------------------------'
	 */

	[_ADJUST] = LAYOUT_ortho_5x15( /* ADJUST */
		RESET,  _______,  _______,  _______,  _______,_______,_______,_______,_______,  _______,  _______,  _______,    _______,    _______,  _______, \
  		_______, _______,   _______,  _______,   _______, RGB_TOG, _______, _______, KC_INS, _______, _______, _______, _______, _______, _______, \
  		_______, _______, 	RGB_MODE_RAINBOW,	RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT, _______, _______, _______, _______, _______, \
  		_______, RGB_VAI,   RGB_VAD,  			RGB_HUI,  		RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, KC_BRIU, _______, _______, \
		KC_LCTL,  MO(FUNCT),KC_LALT,  KC_LGUI,	MO(LOWER),KC_SPC,KC_SPC,MO(RAISE),KC_LGUI,KC_RCTL, 	MO(FUNCT),	  _______,    KC_BRID,    _______, _______ \
	),

	/* FUNCTION
	* .--------------------------------------------------------------------------------------------------------------------------------------.
	* |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    |     DELETE      | F12    |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
	* |        |        | WINSCP |        |  RACE  |        |        |        | INSERT |        |        |        |        |        |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
	* |        |        | SLEEP  |        |        |        | HGPULL |        |        |        |        |        |                 |        |
	* |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
	* |        |        |        |        |        | BUILD  |        |        |        |        |        |        |  PGUP  |        |        |
	* |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
	* |        | FUNCT  |        | LGUI   | LOWER  |      SPACE      | RAISE  |        |        |        |  HOME  |  PGDN  |  END   |        |
	* '--------------------------------------------------------------------------------------------------------------------------------------'
	*/

 	[_FUNCT] = LAYOUT_ortho_5x15( /* LIGHTING */
  		_______, KC_F1,     KC_F2,		KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_DEL, KC_DEL, KC_F12, \
  		_______, _______,   QMK_WINSCP,    _______, QMK_RACE, _______, _______, _______, KC_INS, _______, _______, _______, _______, _______, _______, \
  		_______, _______, 	QMK_SLEEP,	_______, _______, _______, QMK_HGPULL, _______, _______, _______, _______, _______, _______, _______, _______, \
  		_______, _______,   _______,  	_______, _______, QMK_BUILD, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, KC_BRIGHTNESS_UP, \
		KC_LCTL, MO(FUNCT),	KC_LALT,  	KC_LGUI, MO(LOWER),KC_SPC, KC_SPC,  MO(RAISE),KC_LGUI,KC_RCTL, MO(FUNCT),   KC_HOME, KC_PGDOWN, KC_END, KC_BRIGHTNESS_DOWN \
	)
 };


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMK_RACE:
        if (record->event.pressed) {
        SEND_STRING("./RaceBuilder.cgi serial=SUB0400001 manuf=subaru vehid=SUBA_US_WRXM_19 model=2019_USDM_WRXM name=Customer_Name email=michael.sessions@cobbtuning.com DEBUG=ToBeTested project=tuner");
        }
        return false;
        break;
    case QMK_WINSCP:
        if (record->event.pressed) {
        SEND_STRING("@Jan597tYu^!");
        }
        return false;
        break;
    case QMK_BUILD:
        if (record->event.pressed) {
        SEND_STRING("che7aj9b");
        }
        return false;
        break;
    case QMK_HGPULL:
        if (record->event.pressed) {
        SEND_STRING("hg pull && hg update -C ");
        }
        return false;
        break;
    case QMK_SLEEP:
        if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_X)SS_UP(X_LGUI)SS_TAP(X_U)SS_TAP(X_S));
        }
        return false;
        break;

  }
  return true;
}