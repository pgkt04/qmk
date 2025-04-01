#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    QK_GRAVE_ESCAPE,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TAB,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,
    KC_LCTL, KC_A,    KC_S,        KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        MT(MOD_RSFT, KC_ENTER),
    KC_LSFT, MT(MOD_LSFT, KC_Z),     KC_X,           KC_C,           KC_V,          KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH, LT(3, KC_GRAVE),
                                                    MT(MOD_LGUI,KC_SPACE), MT(MOD_LALT, KC_BSPC),                                LT(2, KC_SPACE),LT(1,KC_ENTER)
  ),
  [1] = LAYOUT_voyager(
    _______,      _______,          _______,          _______,          _______,          _______,                                          _______,          _______,          _______,       KC_MINUS,     KC_EQUAL,    KC_GRAVE,
    _______, _______,        _______,          _______,        _______,         _______,                                        _______,   _______,           KC_UP,           KC_LBRC,       KC_RBRC,       KC_BSLS,
    _______,        _______, _______,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        _______, KC_LEFT, KC_DOWN, KC_RIGHT,        _______,        _______,
    _______, _______, KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,                                        KC_BSPC,        _______,         _______,           _______,         _______,       _______,
                                                    _______, _______,                                 _______, _______
  ),
  [2] = LAYOUT_voyager(
    // KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5, KC_F6,                                   KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,  KC_F12,
    _______,      _______,          _______,          _______,          _______,          _______,                                          _______,          _______,          _______,       KC_MINUS,     KC_EQUAL,    KC_GRAVE,
    KC_CAPS, _______, KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,  KC_MS_WH_UP,                                 _______,     _______,        _______,          _______,         _______, KC_QUOTE,
    _______, _______,KC_MS_LEFT,KC_MS_DOWN,  KC_MS_RIGHT,KC_MS_BTN3,                                 KC_MS_BTN1,   KC_MS_BTN1,   KC_MS_BTN2,        _______,       _______, _______,
    _______, _______, _______, KC_MS_BTN4,  KC_MS_BTN5, KC_MS_WH_DOWN,                                _______, _______,_______,   _______, _______, _______,
                                                    _______, _______,                                         _______, _______
  ),
  [3] = LAYOUT_voyager(
    _______, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                               KC_F6,    KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    _______, _______,        _______,          _______,        _______,         _______,                                        _______,   _______,    _______,    _______, _______,  KC_DEL,
    _______,        KC_VOLD, KC_VOLU,        _______,        _______,        _______,                                        _______, _______, _______, _______,        _______,        _______,
    _______, _______, _______,        _______,        _______,        _______,                                        _______,        _______,         _______,           _______,         KC_RSFT,       _______,
                                                    _______, _______,                                 _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_A);
        tap_code16(KC_A);
        tap_code16(KC_A);
    }
    if(state->count > 3) {
        tap_code16(KC_A);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_A); break;
        case SINGLE_HOLD: layer_on(1); break;
        case DOUBLE_TAP: register_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_A); register_code16(KC_A);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_A); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(1)) {
            layer_off(1);
          }
        break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_A); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};

