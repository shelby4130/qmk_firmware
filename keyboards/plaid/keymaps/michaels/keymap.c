#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum plaid_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCT
};

enum plaid_keycodes {
  QWERTY = SAFE_RANGE
};

enum custom_keycodes {
  QMK_RACE = SAFE_RANGE,
  QMK_WINSCP,
  QMK_BUILD,
  QMK_LAYERS,
  QMK_HGPULL
};


enum {
  TD_SHIFT_CAPS = 0
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCT)


qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Funct| Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_plaid_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    TD(TD_SHIFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, FUNCT, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | HOME | PG-  | PG+  | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_plaid_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_plaid_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |EEPROM| Reset|ClckTg|RGBTog|RGBMod|RGBHui|RGBHud|RGBSai|RGBSad|RGBVai|RGBVad|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Mu Mod|Aud on|Audoff|      |      |Qwerty|      |LAYERS|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_plaid_grid(
    EEP_RST, RESET, CK_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD, AU_ON, AU_OFF,  _______, _______, QWERTY,  _______,  QMK_LAYERS,  _______,  _______,
    _______, MUV_DE,  MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Function Layer
 * ,-----------------------------------------------------------------------------------.
 * |PRNTSC|      |WINSCP|      | RACE |      |      |PAUSE |   +  |   7  |   8  |   9  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |SLEEP |      |      |      |HGPULL|INSERT|   *  |   4  |   5  |   6  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |BUILD |      |      |   /  |   1  |   2  |   3  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   -  |   =  |   0  |   .  |
 * `-----------------------------------------------------------------------------------'
 */

[_FUNCT] = LAYOUT_plaid_grid(
    KC_PSCR, _______, QMK_WINSCP, _______, QMK_RACE, _______, _______, KC_PAUS, KC_PPLS, KC_7, KC_8, KC_9,
    _______, _______, KC_SYSTEM_SLEEP, _______, _______, _______, QMK_HGPULL, KC_INS, KC_PAST, KC_4, KC_5, KC_6,
    _______, _______, _______, _______, _______, QMK_BUILD, _______, _______, KC_PSLS, KC_1, KC_2, KC_3,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_EQL, KC_0, KC_DOT
)

};


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


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
    case QMK_LAYERS:
        if (record->event.pressed) {
            SEND_STRING("Qwerty\n");
            SEND_STRING("| Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |\n");
            SEND_STRING("\n");
            SEND_STRING("| Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |\n");
            SEND_STRING("\n");
            SEND_STRING("| Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |\n");
            SEND_STRING("\n");
            SEND_STRING("| Ctl  | Funct| Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |\n");
            SEND_STRING("\n");
            SEND_STRING("\n");
            SEND_STRING("Lower\n");
            SEND_STRING("|   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |     |   (  |   )  | Bksp |\n");
            SEND_STRING("\n");
            SEND_STRING("| Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |      |      |      |      |             |      | HOME | PG-  | PG+  | END  |\n");
            SEND_STRING("\n");
            SEND_STRING("\n");
            SEND_STRING("Raise\n");
            SEND_STRING("|   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |\n");
            SEND_STRING("\n");
            SEND_STRING("| Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |BkSlsh|\n");
            SEND_STRING("\n");
            SEND_STRING("|      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |\n");
            SEND_STRING("\n");
            SEND_STRING("\n");
            SEND_STRING("Adjust (Lower + Raise)\n");
            SEND_STRING("|      | Reset|ClckTg|RGBTog|RGBMod|RGBHui|RGBHud|RGBSai|RGBSad|RGBVai|RGBVad|  Del |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |      |Mu Mod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |LAYERS|      |      |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermON|TermOF|      |      |      |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |      |      |      |      |             |      |      |      |      |      |\n");
            SEND_STRING("\n");
            SEND_STRING("\n");
            SEND_STRING("Function Layer\n");
            SEND_STRING("|PRNTSC|      |WINSCP|      | RACE |      |      |PAUSE |   +  |   7  |   8  |   9  |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |      |SLEEP |      |      |      |      |INSERT|   *  |   4  |   5  |   6  |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |      |      |      |      |BUILD |      |      |   /  |   1  |   2  |   3  |\n");
            SEND_STRING("\n");
            SEND_STRING("|      |      |      |      |      |             |      |   -  |   =  |   0  |   .  |\n");
          ;
        }
        return false;
        break;
    
  }
  return true;
}
