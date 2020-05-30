#include QMK_KEYBOARD_H

enum dz60rgb_layers {
  _QWERTY,
  _FUNCT,
  _RGB
};

#define FUNCT MO(_FUNCT)
#define RGB MO(_RGB)

enum custom_keycodes {
  QMK_RACE = SAFE_RANGE,
  QMK_WINSCP,
  QMK_BUILD,
  QMK_LAYERS,
  QMK_HGPULL,
  QMK_SLEEP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
   KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
	 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
	 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
	 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, MO(RGB),
	 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(FUNCT), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
	
	[_FUNCT] = LAYOUT(
   RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
	 _______, _______, QMK_WINSCP, _______, QMK_RACE, _______, _______, _______, KC_INS, _______, KC_PSCR, _______, _______, _______, 
	 _______, _______, QMK_SLEEP, _______, _______, _______, QMK_HGPULL, _______, _______, _______, _______, _______, _______, 
	 _______, _______, _______, _______, _______, QMK_BUILD, _______, _______, _______, _______, _______, KC_PGUP, _______, 
	 _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),
	
	[_RGB] = LAYOUT(
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______, _______, _______, _______,
	 _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, _______, _______, _______, _______,
	 _______, _______, _______, _______, _______, _______, _______, _______, RGB_RMOD, RGB_MOD, _______, _______, _______,
	 _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMK_RACE:
        if (record->event.pressed) {
        SEND_STRING("./RaceBuilder.cgi serial=SUB0100001 manuf=subaru vehid=SUBA_US_WRX_02 model=2002_USDM_WRX  name=Customer_Name email=michael.sessions@cobbtuning.com DEBUG=ToBeTested project=tuner");
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