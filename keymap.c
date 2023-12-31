#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _OTHER,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_80(
    KC_ESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        KC_F12,  KC_MPLY,  KC_MUTE,
    KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,       KC_EQL,  XXXXXXX,  KC_BSPC, KC_INS,
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,       KC_RBRC, KC_BSLS,  KC_DEL,
    KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENT,  KC_HOME,
    OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT), KC_UP,   KC_END,
    KC_LCTL,       KC_LGUI, KC_LALT, MO(1),   XXXXXXX,  KC_SPC,           XXXXXXX, KC_SPC,  KC_RALT, KC_RCTL, XXXXXXX,       KC_LEFT, KC_DOWN,  KC_RGHT
  ),
  [_OTHER] = LAYOUT_80(
    _______,       _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,        _______, _______,  _______,
    _______,       _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,        _______, XXXXXXX,  KC_DEL,  KC_MNXT,
    _______,       _______, _______, _______, QK_RBT,   OS_TOGG, _______, _______, _______, KC_PWR,  _______, _______,        _______, _______,  KC_MPRV,
    KC_CAPS,       _______, KC_SLEP, _______, _______,  _______, _______, _______, _______, QK_LOCK, _______, _______,        _______, KC_PGUP,
    _______,       _______, _______, KC_CALC,  _______, QK_BOOT, _______, _______, _______, _______, _______, _______,        _______, KC_PGDN,
    _______,       _______, _______, _______, XXXXXXX,  _______,          XXXXXXX, _______, _______, _______, XXXXXXX,        _______, _______,  _______
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
        // I think the pins in the rev4 info.json for this keyboard are swapped or my encoder is backwards from designed.
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return false;
}

void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
}
