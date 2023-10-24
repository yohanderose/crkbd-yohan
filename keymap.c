#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */


// Keymaps


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, LSFT_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT, LALT_T(KC_APP), KC_LGUI, LT(1, KC_SPC), LT(2, KC_SPC), KC_BSPC, KC_DEL),
                                                              [1] = LAYOUT_split_3x6_3(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_MINS, KC_TRNS, KC_GRV, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_LBRC, KC_RBRC, KC_TRNS, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [2] = LAYOUT_split_3x6_3(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, LSFT_T(KC_F1), KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_BSPC, KC_DEL, KC_NO, RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

// Tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ESC):
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}

// RGB Controls
extern rgblight_config_t rgblight_config;
void                     keyboard_post_init_user(void) {
    rgblight_config.hue = 140; // between cyan and azure
    rgblight_config.sat = 255;
    rgblight_config.val = 63; // 25% brightness
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // get current brightness
    uint8_t current_brightness = rgblight_get_val();
    switch (biton32(state)) {
        case 1:
            // Violet
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(180, 255, current_brightness);
            break;
        case 2:
            // Rose
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(222, 255, current_brightness);
            break;
        default:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(140, 255, current_brightness);
            break;
    }
    return state;
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
