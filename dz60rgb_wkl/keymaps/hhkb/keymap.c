#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        QK_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(2),
        KC_LCTL,        KC_LALT, KC_LGUI,                            KC_SPC,                                      KC_RALT, MO(1),   KC_RCTL
    ),
    [1] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        KC_CAPS, _______, _______,   _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, QK_BOOT,
        _______, KC_KB_VOLUME_DOWN, _______, KC_KB_VOLUME_UP, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______
    ),
    [2] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        _______, _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,
        KC_CAPS, MS_BTN1, MS_UP, MS_BTN2, MS_WHLU, _______, _______, _______, _______, _______, _______, KC_UP, _______, _______,
        _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN3, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT,          _______,
        _______,          _______, _______, MS_WHLD, _______, _______, _______, _______, _______, _______, KC_DOWN, _______, _______,
        _______, _______, _______,                            _______,                                     _______, _______, _______
    )
};
