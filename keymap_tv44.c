#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP_ARROW(ESC,   Q,     W,   E,   R,   T,   Y,   U,   I,   O,    P,    FN17, \
                 FN1,   A,     S,   D,   F,   G,   H,   J,   K,   L,    SCLN, FN2, \
                 FN0,   Z,     X,   C,   V,   B,   N,   M,   COMM,DOT,  SLSH, FN3, \
                 LCTL,  LGUI,  FN21,    SPC,        BSPC, FN22,   FN16, BSLS, LALT),

    /* 1: FN 1, Nums and F-Keys */
    KEYMAP_ARROW(F1,   F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10,  F11,  F12, \
                 TRNS, 1,   2,   3,   4,   5,   6,   7,   8,   9,    0,    TRNS, \
                 TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN9, FN10, EQL,  FN8, \
                 TRNS, TRNS,  LBRC,    TAB,       TRNS, RBRC, FN14, FN11, FN18),

    /* 2: FN 2, Macros and Symbols */
    KEYMAP_ARROW(GRV,  TRNS,FN23,UP,  FN24,TRNS,TRNS,FN25, FN4, FN26,TRNS, TRNS, \
                 TRNS, HOME,LEFT,DOWN,RGHT,END, FN19,FN5,  FN6, FN7, FN20, TRNS, \
                 TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, MINS,SLSH,TRNS, TRNS, \
                 TRNS, TRNS,  FN12,     ENT,   DELETE,   FN13, FN15, TRNS, TRNS),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case 0:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(7), U(LSHIFT), END ) :
                MACRO_NONE );
        case 1:
            return (record->event.pressed ? MACRO( D(LSHIFT), D(UP), END ) :
                MACRO( U(UP), U(LSHIFT), END ) );
        case 2:
            return (record->event.pressed ? MACRO( D(LSHIFT), D(LEFT), END ) :
                MACRO( U(LEFT), U(LSHIFT), END ) );
        case 3:
            return (record->event.pressed ? MACRO( D(LSHIFT), D(DOWN), END ) :
                MACRO( U(DOWN), U(LSHIFT), END ) );
        case 4:
            return (record->event.pressed ? MACRO( D(LSHIFT), D(RGHT), END ) :
                MACRO( U(RGHT), U(LSHIFT), END ) );
        case 5:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(2), U(LSHIFT), END ) :
                MACRO_NONE );
        case 6:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(EQL), U(LSHIFT), END ) :
                MACRO_NONE );
        case 7:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(8), U(LSHIFT), END ) :
                MACRO_NONE );
        case 8:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(MINS), U(LSHIFT), END ) :
                MACRO_NONE );
        case 9:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(COMM), U(LSHIFT), END ) :
                MACRO_NONE );
        case 10:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(DOT), U(LSHIFT), END ) :
                MACRO_NONE );
        case 11:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(6), U(LSHIFT), END ) :
                MACRO_NONE );
        case 12:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(5), U(LSHIFT), END ) :
                MACRO_NONE );
        case 13:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(1), U(LSHIFT), END ) :
                MACRO_NONE );
        case 14:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(3), U(LSHIFT), END ) :
                MACRO_NONE );
        case 15:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(4), U(LSHIFT), END ) :
                MACRO_NONE );
        case 16:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(HOME), U(LSHIFT), END ) :
                MACRO_NONE );
        case 17:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(END), U(LSHIFT), END ) :
                MACRO_NONE );
        case 18:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(9), U(LSHIFT), END ) :
                MACRO_NONE );
        case 19:
            return (record->event.pressed ? MACRO( D(LSHIFT), T(0), U(LSHIFT), END ) :
                MACRO_NONE );
        case 20:
            return (record->event.pressed ? MACRO( D(LCTRL), D(LEFT), END ) :
                MACRO( U(LEFT), U(LCTRL), END ) );
        case 21:
            return (record->event.pressed ? MACRO( D(LCTRL), D(RGHT), END ) :
                MACRO( U(RGHT), U(LCTRL), END ) );
        case 22:
            return (record->event.pressed ? MACRO( D(LSHIFT), D(LCTRL), D(LEFT), END ) :
                MACRO( U(LEFT), U(LCTRL), U(LSHIFT), END ) );
        case 23:
            return (record->event.pressed ? MACRO( D(LSHIFT), D(LCTRL), D(RGHT), END ) :
                MACRO( U(RGHT), U(LCTRL), U(LSHIFT), END ) );
    }
    return MACRO_NONE;
}
            

const action_t PROGMEM fn_actions[] = {
    [0]  = ACTION_MODS_TAP_TOGGLE(MOD_LSFT),
    [1]  = ACTION_LAYER_MOMENTARY(1),
    [2]  = ACTION_LAYER_TAP_KEY(2, KC_QUOT),
    [3]  = ACTION_MACRO(0),
    [4]  = ACTION_MACRO(1),
    [5]  = ACTION_MACRO(2),
    [6]  = ACTION_MACRO(3),
    [7]  = ACTION_MACRO(4),
    [8]  = ACTION_MACRO(5),
    [9]  = ACTION_MACRO(6),
    [10] = ACTION_MACRO(7),
    [11] = ACTION_MACRO(8),
    [12] = ACTION_MACRO(9),
    [13] = ACTION_MACRO(10),
    [14] = ACTION_MACRO(11),
    [15] = ACTION_MACRO(12),
    [16] = ACTION_MACRO(13),
    [17] = ACTION_MACRO(14),
    [18] = ACTION_MACRO(15),
    [19] = ACTION_MACRO(16),
    [20] = ACTION_MACRO(17),
    [21] = ACTION_MACRO(18),
    [22] = ACTION_MACRO(19),
    [23] = ACTION_MACRO(20),
    [24] = ACTION_MACRO(21),
    [25] = ACTION_MACRO(22),
    [26] = ACTION_MACRO(23),
};
