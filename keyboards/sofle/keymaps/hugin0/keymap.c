#include QMK_KEYBOARD_H

#include "g/keymap_combo.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GAME0,
    _GAME1,
    _LOWER,
    _RAISE,
    _NAVI,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_NAVI,
    KC_ADJUST,
    /* KC_PRVWD, */
    /* KC_NXTWD, */
    /* KC_LSTRT, */
    /* KC_LEND, */
    /* KC_DLINE */
};

#define SFT_ENT RSFT_T(KC_ENTER)
#define ESC_CTL LCTL_T(KC_ESC)

// Layer renames, because it was easier than looking around for all the calls.
#define LOWER KC_LOWER
#define RAISE KC_RAISE
#define ADJUST KC_ADJUST

// Gaming layer stuff
#define GAME1 MO(_GAME1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(  
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0     , KC_GRV ,
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P     , KC_BSPC,
  KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN  , KC_QUOT,
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX,     XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH  , KC_RSFT,
                    KC_LGUI, KC_LALT, KC_LCTL, LOWER  , KC_SPC ,     SFT_ENT, RAISE  , KC_RCTL, KC_RALT, KC_RGUI
),

[_GAME0] = LAYOUT(  
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0     , KC_GRV ,
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P     , KC_BSPC,
  ESC_CTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN  , KC_QUOT,
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX,     XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH  , KC_RSFT,
                    KC_LGUI, KC_LALT, KC_LCTL, GAME1  , KC_SPC ,     SFT_ENT, RAISE  , KC_RCTL, KC_RALT, KC_RGUI
),

[_GAME1] = LAYOUT(
/* Gaming alternate layer, put macros and such on this layer. */
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_QWERTY),
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
/* RAISE Layer, used for numbers and maths operations */
  KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  _______, KC_9   , KC_8   , KC_7   , KC_6   , KC_0   ,                       _______, _______, _______, _______, _______, _______,
  _______, KC_4   , KC_3   , KC_2   , KC_1   , KC_5   ,                       _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
  _______, KC_SLSH, KC_ASTR, KC_PLUS, KC_MINS, KC_EQL , _______,     _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ 
),

[_LOWER] = LAYOUT(
/* LOWER layer, used for symbols mostly. */
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_DEL ,
  KC_NAVI, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                       KC_MINS, KC_LPRN, KC_LBRC, KC_LCBR, KC_BSLS, _______,
  _______, KC_UNDO, KC_CUT , KC_COPY, KC_PAST, _______, _______,     _______, KC_UNDS, KC_RPRN, KC_RBRC, KC_RCBR, _______, _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

[_NAVI] = LAYOUT(
/* Navigation Layer */
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______   
),

[_ADJUST] = LAYOUT(
/* ADJUST layer, reserved to changing keyboard behaviors */
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_GAME0),
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
)
};

/*************************/
/* Per key tapping terms */
/*************************/
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_SPC):
            return TAPPING_TERM + 250; /* lengthen the tapping term to prioritize the tap */
        default:
            return TAPPING_TERM;
    }
}


/*****************************************************************************/
/*     OLED CODE -- Not currently used, but left in for future addition.     */
/*****************************************************************************/
#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NAVI:
            oled_write_P(PSTR("Navi"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

/********************************************************************/
/* Custom Keycode processing.  carried over from the default keymap */
/* Needs read and understood, before removing and/or modifying.     */
/********************************************************************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_NAVI:
          if (record->event.pressed) {
            layer_on(_NAVI);
          } else {
            layer_off(_NAVI);
          }
          return false;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PAST:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

/*************************************************************************************/
/*    encoder code.  currently no encoder installed, but I haven't ruled it out yet. */
/*************************************************************************************/

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
