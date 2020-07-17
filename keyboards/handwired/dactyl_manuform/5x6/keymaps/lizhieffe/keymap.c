/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum custom_keycodes {
    VIM_CLANGFORMAT = SAFE_RANGE,
    GMAIL_DELETE,
    CHROME_LEFT_TAB,
    CHROME_RIGHT_TAB,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VIM_CLANGFORMAT:
        if (record->event.pressed) {
            // when keycode VIM_CLANGFORMAT is pressed
            SEND_STRING(SS_LSFT(";")"ClangFormat\n");
        } else {
            // when keycode VIM_CLANGFORMAT is released
        }
        break;
    case GMAIL_DELETE:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_LSFT("3"));
        } else {
            // when keycode is released
        }
        break;
    case CHROME_LEFT_TAB:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_DOWN(X_LGUI));
            SEND_STRING(SS_DOWN(X_LALT));
            SEND_STRING(SS_TAP(X_LEFT));
            SEND_STRING(SS_UP(X_LALT));
            SEND_STRING(SS_UP(X_LGUI));
        } else {
            // when keycode is released
        }
        break;
    case CHROME_RIGHT_TAB:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_DOWN(X_LGUI));
            SEND_STRING(SS_DOWN(X_LALT));
            SEND_STRING(SS_TAP(X_RIGHT));
            SEND_STRING(SS_UP(X_LALT));
            SEND_STRING(SS_UP(X_LGUI));
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // [_QWERTY] = LAYOUT_5x6(
  //    KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
  //    KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
  //    KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
  //    KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
  //                     KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
  //                                     RAISE,KC_SPC,                        KC_ENT, LOWER,
  //                                     KC_TAB,KC_HOME,                         KC_END,  KC_DEL,
  //                                     KC_BSPC, KC_GRV,                        KC_LGUI, KC_LALT
  // ),

  [_QWERTY] = LAYOUT_5x6(
     KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_EQL,
     CHROME_LEFT_TAB, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     CHROME_RIGHT_TAB, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                          KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      GMAIL_DELETE,KC_LALT,                                                       KC_LEFT, KC_RIGHT,
                                      MT(MOD_LGUI,KC_ESC),KC_LCTL,                        KC_SPC,LT(_RAISE, KC_ENT),
                                      RAISE,KC_LSFT,                         KC_BSPC,LT(_LOWER, KC_TAB),
                                      LOWER, CHROME_RIGHT_TAB,                        KC_DEL,KC_RBRC
  ),

  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       KC_MS_ACCEL0,_______,_______,KC_MS_UP,_______,KC_LBRC,                        KC_RBRC,KC_PGDOWN,KC_PGUP,KC_INS ,KC_SLCK,KC_MUTE,
       KC_MS_ACCEL1,_______,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,_______,                        KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,_______,KC_VOLU,
       KC_MS_ACCEL2,_______,KC_MS_WH_LEFT,_______,KC_MS_WH_RIGHT,_______,                        _______,VIM_CLANGFORMAT,_______,_______,_______,KC_VOLD,
                                               KC_MS_BTN4,KC_MS_BTN5,            KC_EQL ,_______,
                                               KC_MS_BTN1,KC_MS_BTN2,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),

  [_LOWER] = LAYOUT_5x6(
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_PSCR,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),
};
