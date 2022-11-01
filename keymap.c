/* Copyright 2021 HellSingCoder
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

enum sofle_layers {
    _QWERTY   = 0,
    _COLEMAK  = 1,
    _FUNCTION = 2,
    _SYMBOLS  = 3,
    _ADJUST   = 5,
};

// clang-format off
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_FUNCTION,
    KC_SYMBOLS,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_BSPC_DEL,
    KC_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                        ,-----------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  |  BS  |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                        |   Y  |   U  |   I  |   O  |   P  |  `   |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-----------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  mute |    |    caps   |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-----------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \          \-----------------------------------------'
     *            | LGUI | LAlt | LCtrl| Enter| /SYMBOLS/       \ FUNCTION \  |  Spc | RCtrl | RAlt | RGUI |
     *            |      |      |      |      |/       /         \          \ |      |       |      |      |
     *            `----------------------------------'           '------''---------------------------------'
     */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,          KC_3,       KC_4,        KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
  KC_GRV,   KC_Q,   KC_W,          KC_E,       KC_R,        KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC_DEL,
  KC_TAB,   KC_A,   KC_S,          KC_D,       KC_F,        KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   LT(0, KC_X),  LT(0,KC_C),  LT(0,KC_V),  KC_B,  KC_MUTE,     KC_CAPS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                 KC_LGUI, KC_LALT, KC_LCTL, KC_ENTER, KC_SYMBOLS,      KC_FUNCTION,  KC_SPC, KC_RCTL, KC_RALT, KC_RGUI
),

    /*
     * COLEMAK DH
     * ,-----------------------------------------.                        ,-----------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  |  BS  |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |                        |   J  |   L  |   U  |   Y  |   ;  |  `   |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * | Caps |   A  |   R  |   S  |   T  |   D  |-------.    ,-----------|   H  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------|  mute |    |    caps   |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-----------|   K  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \          \-----------------------------------------'
     *            | LGUI | LAlt | LCtrl| Enter| /Layer  /       \ FUNCTION \  |  Spc | RCtrl | RAlt | RGUI |
     *            |      |      |      |      |/       /         \          \ |      |       |      |      |
     *            `----------------------------------'           '------''---------------------------------'
     */

[_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
  KC_GRV,   KC_Q,  KC_W,  KC_F,  KC_P,  KC_G,                                    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSPC_DEL,
  KC_TAB,   KC_A,  KC_R,  KC_S,  KC_T,  KC_D,                                    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,   KC_MUTE,              KC_CAPS,   KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                KC_LGUI,KC_LALT,KC_LCTL,KC_ENTER,KC_SYMBOLS,      KC_FUNCTION,  KC_SPC, KC_RCTL, KC_RALT, KC_RGUI
),

/* FUNCTION 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Up  |  END |      |      |                    |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | RAlt | LCTR | Enter | /      /       \      \  |      |      |      |      |
 *            |      |      |      |       |/      /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_FUNCTION] = LAYOUT(
  XXXXXXX,   KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,                             KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  XXXXXXX,  XXXXXXX,  KC_UP,    KC_END,   XXXXXXX,  XXXXXXX,                           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F12,
  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,                           KC_HOME,  XXXXXXX,  KC_INS,   KC_HOME,  KC_PGUP,  XXXXXXX,
  KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX,  KC_APP,   KC_DEL,   KC_END,   KC_PGDN, KC_RSFT,
                KC_LGUI, KC_LALT, KC_LCTL, KC_ENTER, KC_SYMBOLS,                       KC_FUNCTION,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | LBRC | RBRC |      |                    | PIPE | LPRN | RPRN |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | LCBR | RCBR |      |-------.    ,-------| Mins |  Eql | BSLS | LBRC | RBRC |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |-------|    |-------|      | SCln |  Cln |      |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBOLS] = LAYOUT(
  XXXXXXX,  KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,                            KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_LBRC,   KC_RBRC,  XXXXXXX,                          KC_PIPE,  KC_LPRN,  KC_RPRN,  XXXXXXX,  XXXXXXX,  KC_F12,
  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_LCBR,   KC_RCBR,  XXXXXXX,                          KC_MINS,  KC_EQL,   KC_BSLS,  KC_LBRC,  KC_RBRC,  XXXXXXX,
  KC_LSFT,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,       XXXXXXX,  XXXXXXX,  KC_SCLN,  KC_COLN,  XXXXXXX,  XXXXXXX,  KC_RSFT,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SYMBOLS,                      KC_FUNCTION, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|    |QWERTY|COLEMK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX ,    XXXXXXX,  XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT,  XXXXXXX,  KC_QWERTY,  KC_COLEMAK,  XXXXXXX,  XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  CG_TOGG,    XXXXXXX,     XXXXXXX,  XXXXXXX,                        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,  XXXXXXX,    XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX,  XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};
// clang-format on

/* Smart Backspace Delete */

bool            shift_held = false;
static uint16_t held_shift = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_FUNCTION:
            if (record->event.pressed) {
                layer_on(_FUNCTION);
                update_tri_layer(_SYMBOLS, _FUNCTION, _ADJUST);
            } else {
                layer_off(_FUNCTION);
                update_tri_layer(_SYMBOLS, _FUNCTION, _ADJUST);
            }
            return false;
        case KC_SYMBOLS:
            if (record->event.pressed) {
                layer_on(_SYMBOLS);
                update_tri_layer(_SYMBOLS, _FUNCTION, _ADJUST);
            } else {
                layer_off(_SYMBOLS);
                update_tri_layer(_SYMBOLS, _FUNCTION, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

            /* Smart Backspace Delete */

        case KC_RSFT:
        case KC_LSFT:
            shift_held = record->event.pressed;
            held_shift = keycode;
            break;
        case KC_BSPC_DEL:
            if (record->event.pressed) {
                if (shift_held) {
                    unregister_code(held_shift);
                    register_code(KC_DEL);
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
                if (shift_held) {
                    register_code(held_shift);
                }
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    return true;
}

#endif
