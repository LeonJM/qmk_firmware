#include QMK_KEYBOARD_H

// Base Layer Shortcuts
#define CUT_X LT(0, KC_X)
#define COPY_C LT(0, KC_C)
#define PASTE_V LT(0, KC_V)
#define ESC_Q LT(0, KC_Q)

// Home Row Mods - mod tap keycodes
#define L_WIN LGUI_T(KC_A)
#define L_ALT LALT_T(KC_S)
#define L_SHIFT LSFT_T(KC_D)
#define L_CTRL LCTL_T(KC_F)
#define R_CTRL RCTL_T(KC_J)
#define R_SHIFT RSFT_T(KC_K)
#define R_ALT RALT_T(KC_L)
#define R_WIN RGUI_T(KC_SCLN)

enum __layers {
    _BASE,
};

enum custom_keycodes {
    dummy = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // All F2 keys in this layout are just for testing only
    [_BASE] = LAYOUT(
        KC_GRAVE,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,          KC_6,    KC_7,           KC_8,         KC_9,         KC_0,            KC_MINS,  KC_EQL,   KC_F2,          KC_F2,
        KC_TAB,           ESC_Q,        KC_W,         KC_E,         KC_R,         KC_T,          KC_Y,    KC_U,           KC_I,         KC_O,         KC_P,            KC_LBRC,  KC_RBRC,  KC_BSLS,        KC_F2,
        KC_CAPS,          L_WIN,        L_ALT,        L_SHIFT,      L_CTRL,       KC_G,          KC_H,    R_CTRL,         R_SHIFT,      R_ALT,        R_WIN,           KC_QUOT,  KC_NO,    KC_ENT,         KC_F2,
        KC_LSFT,   KC_NO, KC_Z,         CUT_X,        COPY_C,       PASTE_V,      KC_B,          KC_F2,   KC_N,           KC_M,         KC_COMM,      KC_DOT,          KC_SLSH,            KC_F2,          KC_UP,
        KC_RCTL,          LT(4, KC_DEL), LT(2, KC_BSPC), LT(3, KC_ENT),          LT(1, KC_SPC), KC_F2,  KC_F2,                                                                                    KC_LEFT, KC_DOWN, KC_RGHT
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUT_X: {  
            // Intercept hold function to send Ctrl-X
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); 
                return false;
            }
            break;
        }
        case COPY_C: {  
            // Intercept hold function to send Ctrl-C
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C));
                return false;
            }
            break;
        }
        case PASTE_V: {  
            // Intercept hold function to send Ctrl-V
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V));
                return false;
            }
            break;
        }
        case ESC_Q: {
            // Intercept hold function to send Escape
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_ESC);
                return false;
            }
            break;
        }
    }
    return true;        // Process the keycode as ususal
}

// Custom tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_WIN:
        case L_ALT:
        case R_ALT:
        case R_WIN:
        case ESC_Q:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}