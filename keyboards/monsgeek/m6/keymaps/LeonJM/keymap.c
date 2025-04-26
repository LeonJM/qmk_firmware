#include QMK_KEYBOARD_H

// Base Layer Shortcuts
#define CUT_X LT(0, KC_X)
#define COPY_C LT(0, KC_C)
#define PASTE_V LT(0, KC_V)
#define ESC_Q LT(0, KC_Q)
#define TAB_W LT(0, KC_W)

// Misc
#define DEAD KC_NO      // The key that does not physically exist on the Monsgeek M6

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
    _NORMAL,
    _NUMPAD,
    _SYMBOL,
    _FUNC,
    _NAV
};

enum custom_keycodes {
    dummy = SAFE_RANGE,
};

bool alt_tabbing = false;
bool alt_held = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_NO,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,              KC_NO, KC_NO, KC_NO,     TG(_NORMAL),
        KC_NO,           ESC_Q,     TAB_W,     KC_E,      KC_R,      KC_T,            KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,               KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           L_WIN,     L_ALT,     L_SHIFT,   L_CTRL,    KC_G,            KC_H,      R_CTRL,    R_SHIFT,   R_ALT,     R_WIN,              KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_Z,      CUT_X,     COPY_C,    PASTE_V,   KC_B,   KC_NO,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,            KC_NO,                   KC_NO,
        KC_NO,   LT(0, KC_DEL), LT(_SYMBOL, KC_BSPC), LT(_NUMPAD, KC_ENT),            LT(_NAV, KC_SPC), KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO
    ),

    [_NORMAL] = LAYOUT(
        KC_GRAVE,        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,            KC_6,      KC_7,      KC_8,      KC_9,      KC_0,               KC_MINS,  KC_EQL,  KC_NO,     KC_TRNS,
        KC_TAB,          ESC_Q,     TAB_W,     KC_E,      KC_R,      KC_T,            KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,               KC_LBRC,  KC_RBRC, KC_BSLS,   KC_TRNS,
        KC_CAPS,         L_WIN,     L_ALT,     L_SHIFT,   L_CTRL,    KC_G,            KC_H,      R_CTRL,    R_SHIFT,   R_ALT,     R_WIN,              KC_QUOT,  DEAD,    KC_NO,     KC_TRNS,
        KC_LSFT,  DEAD,  KC_Z,      CUT_X,     COPY_C,    PASTE_V,   KC_B,   KC_NO,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,            KC_NO,                        KC_UP,
        KC_RCTL, LT(0, KC_DEL), LT(_SYMBOL, KC_BSPC), LT(_NUMPAD, KC_ENT),            LT(_NAV, KC_SPC), KC_NO, KC_NO,                                                      KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_SYMBOL] = LAYOUT(
        KC_NO,           KC_NO,     KC_NO,     KC_NO,        KC_NO,        KC_NO,            KC_NO,     KC_NO,        KC_NO,        KC_NO,     KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_NO,     KC_GRAVE,  KC_MINS,      KC_EQL,       KC_NO,            KC_NO,     KC_LBRC,      KC_RBRC,      KC_QUOT,   KC_BSLS,        KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_1,      KC_2,      LSFT_T(KC_3), LCTL_T(KC_4), KC_5,             KC_6,      RCTL_T(KC_7), RSFT_T(KC_8), KC_9,      KC_0,           KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_NO,     KC_NO,     KC_NO,        KC_NO,        KC_NO,   KC_NO,   KC_NO,     KC_NO,        KC_NO,        KC_NO,     KC_NO,          KC_NO,                   KC_NO,
        KC_NO,                                         KC_TRNS, KC_TRNS, KC_TRNS,            MO(_FUNC), KC_TRNS, KC_TRNS,                                                        KC_NO, KC_NO, KC_NO
    ),

    [_FUNC] = LAYOUT(
        QK_BOOT,         KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_F11,    KC_F12,    KC_F13,    KC_F14,    KC_F15,           KC_F16,    KC_F17,    KC_F18,    KC_F19,    KC_F20,         KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,            KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,         KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,          KC_NO,                   KC_NO,
        KC_NO,                                   KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,                                                    KC_NO, KC_NO, KC_NO
    ),

    [_NUMPAD] = LAYOUT(
        KC_NO,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,            KC_NO,     KC_7,      KC_8,      KC_9,      KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           S(KC_8),   KC_SLSH,   KC_MINS,   KC_PLUS,   KC_EQL,           KC_NO,     KC_4,      KC_5,      KC_6,      KC_NO,          KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_0,      KC_1,      KC_2,      KC_3,      KC_DOT,         KC_NO,                   KC_NO,
        KC_NO,                                   KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,                                                    KC_NO, KC_NO, KC_NO
    ),

    [_NAV] = LAYOUT(
        KC_NO,           KC_NO,     KC_NO,     KC_NO,         KC_NO,         KC_NO,            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_NO,     KC_NO,     KC_NO,         KC_NO,         KC_NO,            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_NO,     KC_NO,     LSFT_T(KC_NO), LCTL_T(KC_NO), KC_NO,            KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_NO,          KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_NO,     KC_NO,     KC_NO,         KC_NO,         KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,          KC_NO,                   KC_NO,
        KC_NO,                                           KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,                                                    KC_NO, KC_NO, KC_NO
    ),

    // [_TRNS] = LAYOUT(
    //     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
    //     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
    //     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,
    //     KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,                                                            KC_TRNS, KC_TRNS, KC_TRNS
    // ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case R_ALT:
        case L_ALT: {
            if (record->event.pressed) {
                alt_held = true;
            } else {
                alt_held = false;
                alt_tabbing = false;    // Reset state when Alt is released.
            }
            break;
        }
        case R_CTRL: {
            if (record->event.pressed && alt_tabbing) {
                tap_code(KC_LEFT);  // Left Arrow while alt tabbing
                return false;
            }
            break;
        }
        case R_SHIFT: {
            if (record->event.pressed && alt_tabbing) {
                tap_code(KC_RIGHT);  // Right Arrow while alt tabbing
                return false;
            }
            break;
        }
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
        case TAB_W: {
            // Intercept hold function to send Tab
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_TAB);
                if (alt_held) alt_tabbing = true;   // Currently alt tabbing.
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