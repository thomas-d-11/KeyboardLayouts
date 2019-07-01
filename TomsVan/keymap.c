#include "MiniVan20190622161824.h"
enum custom_keycodes {
	M_IME = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case M_IME:
				SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
				return false;
		}
	}
	else {
		switch(keycode) {
			case M_IME:
				SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
				return false;
		}
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = KEYMAP(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TT(3), TT(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(2, KC_QUOT), LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TG(2), KC_LCTL, KC_LGUI, LSFT(KC_3), LSFT(KC_9), KC_SPC, KC_BSPC, LSFT(KC_0), LSFT(KC_1), KC_BSLS, KC_LALT),
	[1] = KEYMAP(KC_GRV, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_EQL), KC_MINS, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_TAB, KC_TRNS, KC_RBRC, LSFT(KC_7), LSFT(KC_MINS), KC_TRNS),
	[2] = KEYMAP(LSFT(KC_GRV), KC_TRNS, KC_HOME, KC_UP, KC_END, KC_BRID, KC_BRIU, LSFT(KC_HOME), LSFT(KC_UP), LSFT(KC_END), KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT), LSFT(LCTL(KC_LEFT)), LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), LSFT(LCTL(KC_RIGHT)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, LSFT(KC_8), KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_4), LSFT(KC_COMM), KC_ENT, KC_DEL, LSFT(KC_DOT), LSFT(KC_2), KC_TRNS, KC_TRNS),
	[3] = KEYMAP(KC_TRNS, KC_TRNS, LCTL(LSFT(KC_TAB)), KC_TRNS, LCTL(KC_TAB), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LBRC), KC_TRNS, LCTL(KC_RBRC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_6), LSFT(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_LBRC), LCTL(LALT(KC_SPC)), LCTL(LALT(KC_BSPC)), LSFT(KC_RBRC), KC_TRNS, KC_TRNS, KC_TRNS),
};

#define set_black rgblight_setrgb (0x00, 0x00, 0x00)
#define set_green rgblight_setrgb (0x01, 0x03, 0x00)
#define set_cyan rgblight_setrgb (0x00, 0x02, 0x02)
#define set_magenta rgblight_setrgb (0x02, 0x00, 0x02)

void matrix_init_user(void) {
	set_black;
}

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case 1:
			set_green;
			break;
		case 2:
			set_cyan;
			break;
		case 3:
			set_magenta;
			break;
		default:
			set_black;
			break;
	}
	return state;
}
