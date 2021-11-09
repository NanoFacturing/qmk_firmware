/* Copyright 2021 tkhub
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DEFTN = 0,
    _OPT,
    _FNC,
    _EXC
    // _BASE,
    //_FN
};

#define     KC_FN                       MO(_OPT)
#define     SEND_CTRL_CODE(code)        register_code(KC_LCTRL);    \
                                        SEND_STRING(code);          \
                                        unregister_code(KC_LCTRL)

#define     SEND_CTRL_SFT(code)         register_code(KC_LCTRL);    \
                                        register_code(KC_LSFT);     \
                                        SEND_STRING(code);          \
                                        register_code(KC_LCTRL);    \
                                        register_code(KC_LSFT)    

#define     SEND_CTRL_SFT_ALT(code)     register_code(KC_LCTRL);    \
                                        register_code(KC_LSFT);     \
                                        register_code(KC_LALT);     \
                                        SEND_STRING(code);          \
                                        register_code(KC_LCTRL);    \
                                        register_code(KC_LSFT);     \
                                        register_code(KC_LALT)

#define     SEND_CTRL_ALT(code)         register_code(KC_LCTRL);    \
                                        register_code(KC_LALT);     \
                                        SEND_STRING(code);          \
                                        register_code(KC_LCTRL);    \
                                        register_code(KC_LALT)

#define     SEND_SFT_ALT(code)          register_code(KC_LSFT);     \
                                        register_code(KC_LALT);     \
                                        SEND_STRING(code);          \
                                        register_code(KC_LSFT);     \
                                        register_code(KC_LALT)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    KCO_00,
    KCO_CtrlA,
    KCO_CtrlX,
    KCO_CtrlC,
    KCO_CtrlV,
    KCO_CtrlZ,
    KCO_EQL,
    KE_R,           //  Excel Ctrl+R
    KE_D,           //  Excel Ctrl+D
    KE_TAB,         //  Excel Alt+TAB
    KCO_CMM,        //  ,
};

// https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes_basic
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_DEFTN] = LAYOUT(
    //              COL0        COL1        COL2        COL3        COL4        COL5
    /* ROW4 */      KC_ESC,     KC_BSPC,    KC_PMNS,    KC_PAST,    KC_PSLS,    KCO_CtrlA,  \
    /* ROW3 */      KC_TAB,     KC_PPLS,    KC_P7,      KC_P8,      KC_P9,      KCO_CtrlX,  \
    /* ROW2 */      KC_LCTL,    KC_NO,      KC_P4,      KC_P5,      KC_P6,      KCO_CtrlC,  \
    /* ROW1 */      KC_LSFT,    KC_ENT,     KC_P1,      KC_P2,      KC_P3,      KCO_CtrlV,  \
    /* ROW0 */      KCO_CtrlZ,  KC_NO,      KC_P0,      KCO_00,     KC_PDOT,    KC_FN       \
    ),
    [_OPT] = LAYOUT(
    //              COL0        COL1        COL2        COL3        COL4        COL5
    /* ROW4 */      TO(_DEFTN), KC_NLCK,    KC_PEQL,    KC_LPRN,    KC_RPRN,    TO(_FNC),   \
    /* ROW3 */      _______,    KC_SPACE,   KC_HOME,    KC_UP,      KC_PGUP,    TO(_EXC),   \
    /* ROW2 */      _______,    KC_NO,      KC_LEFT,    KC_SPC,     KC_RIGHT,   KC_NO,  \
    /* ROW1 */      _______,    _______,    KC_END,     KC_DOWN,    KC_PGDOWN,  KC_NO,   \
    /* ROW0 */      KC_MUTE,    KC_NO,      KC_KANA,    KC_PCMM,    KC_DELETE,  KC_FN       \
    ),
    [_FNC] = LAYOUT(
    //              COL0        COL1        COL2        COL3        COL4        COL5
    /* ROW4 */      _______,    _______,    KC_F10,     KC_F11,     KC_F12,     _______,    \
    /* ROW3 */      _______,    _______,    KC_F7,      KC_F8,      KC_F9,      _______,    \
    /* ROW2 */      _______,    _______,    KC_F4,      KC_F5,      KC_F6,      _______,    \
    /* ROW1 */      _______,    _______,    KC_F1,      KC_F2,      KC_F3,      _______,    \
    /* ROW0 */      _______,    _______,    _______,    _______,    _______,    KC_FN       \
    ),
    [_EXC] = LAYOUT(
    //              COL0        COL1        COL2        COL3        COL4        COL5
    /* ROW4 */      _______,    _______,    _______,    KE_D,       _______,    _______,    \
    /* ROW3 */      KE_TAB,     _______,    KC_PGUP,    KC_UP,      KC_HOME,    _______,    \
    /* ROW2 */      KC_LCTL,    _______,    KC_LEFT,    KC_E,       KC_RIGHT,   KE_R,    \
    /* ROW1 */      KC_LSFT,    _______,    KC_PGDOWN,  KC_DOWN,    KC_END,     _______,    \
    /* ROW0 */      _______,    _______,    _______,    _______,    KC_DELETE,  KC_FN       \
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
        case KCO_00:
            if (record->event.pressed) {
                //SEND_STRING("00");
                SEND_STRING(SS_TAP(X_P0));
                SEND_STRING(SS_TAP(X_P0));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case KCO_CtrlA:
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                SEND_STRING("a");
                unregister_code(KC_LCTRL);
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case KCO_CtrlX:
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                SEND_STRING("x");
                unregister_code(KC_LCTRL);
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case KCO_CtrlC:
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                SEND_STRING("c");
                unregister_code(KC_LCTRL);
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case KCO_CtrlV:
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                SEND_STRING("v");
                unregister_code(KC_LCTRL);
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case KCO_CtrlZ:
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                SEND_STRING("z");
                unregister_code(KC_LCTRL);
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case KCO_EQL:
            if (record->event.pressed) {
                SEND_STRING("=");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case KCO_CMM:
            if (record->event.pressed) {
                SEND_STRING(",");
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
}
