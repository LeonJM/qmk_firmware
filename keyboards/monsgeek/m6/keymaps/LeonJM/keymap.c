#include QMK_KEYBOARD_H

// Base Layer Shortcuts
#define CUT_X LT(0, KC_X)
#define COPY_C LT(0, KC_C)
#define PASTE_V LT(0, KC_V)

// Base Layer Shortcuts (Dvorak)
#define CUT_X2 LT(0, KC_Q)
#define COPY_C2 LT(0, KC_J)
#define PASTE_V2 LT(0, KC_K)

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

// Home Row Mods (Dvorak) - mod tap keycodes
#define L_WIN2 LGUI_T(KC_A)
#define L_ALT2 LALT_T(KC_O)
#define L_SHIFT2 LSFT_T(KC_E)
#define L_CTRL2 LCTL_T(KC_U)
#define R_CTRL2 RCTL_T(KC_H)
#define R_SHIFT2 RSFT_T(KC_T)
#define R_ALT2 RALT_T(KC_N)
#define R_WIN2 RGUI_T(KC_S)

// Combos
const uint16_t PROGMEM dvorak_layer_combo[] = {L_CTRL, R_CTRL, COMBO_END};
const uint16_t PROGMEM qwerty_layer_combo[] = {L_CTRL2, R_CTRL2, COMBO_END};

enum __layers {
    _BASE,
    _DVORAK,
    _NORMAL,
    _NUMPAD,
    _SYMBOL,
    _FUNC,
    _NAV
};

enum custom_keycodes {
    VIM_H = SAFE_RANGE,
};

bool alt_tabbing = false;
bool alt_held = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_NO,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,              KC_NO, KC_NO, KC_NO,     TG(_NORMAL),
        KC_NO,           KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,            KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,               KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           L_WIN,     L_ALT,     L_SHIFT,   L_CTRL,    KC_G,            KC_H,      R_CTRL,    R_SHIFT,   R_ALT,     R_WIN,              KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_Z,      CUT_X,     COPY_C,    PASTE_V,   KC_B,   KC_NO,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,            KC_NO,                   KC_NO,
        KC_NO,      LT(0, KC_DEL), LT(_NAV, KC_BSPC), LT(_NUMPAD, KC_ENT),            LT(_SYMBOL, KC_SPC), KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO
    ),

    [_DVORAK] = LAYOUT(
        KC_NO,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,              KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_QUOT,   KC_COMM,   KC_DOT,    KC_P,      KC_Y,            KC_F,      KC_G,      KC_C,      KC_R,      KC_L,               KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           L_WIN2,    L_ALT2,    L_SHIFT2,  L_CTRL2,   KC_I,            KC_D,      R_CTRL2,   R_SHIFT2,  R_ALT2,    R_WIN2,             KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_SCLN,   CUT_X2,    COPY_C2,   PASTE_V2,  KC_X,   KC_NO,   KC_B,      KC_M,      KC_W,      KC_V,      KC_Z,            KC_NO,                   KC_NO,
        KC_NO,      LT(0, KC_DEL), LT(_NAV, KC_BSPC), LT(_NUMPAD, KC_ENT),            LT(_SYMBOL, KC_SPC), KC_NO, KC_NO,                                                   KC_NO, KC_NO, KC_NO
    ),

    [_NORMAL] = LAYOUT(
        KC_GRAVE,        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,            KC_6,      KC_7,      KC_8,      KC_9,      KC_0,               KC_MINS,  KC_EQL,  KC_NO,     KC_TRNS,
        KC_TAB,          KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,            KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,               KC_LBRC,  KC_RBRC, KC_BSLS,   KC_TRNS,
        KC_CAPS,         L_WIN,     L_ALT,     L_SHIFT,   L_CTRL,    KC_G,            KC_H,      R_CTRL,    R_SHIFT,   R_ALT,     R_WIN,              KC_QUOT,  DEAD,    KC_NO,     KC_TRNS,
        KC_LSFT,  DEAD,  KC_Z,      CUT_X,     COPY_C,    PASTE_V,   KC_B,   KC_NO,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,            KC_NO,                        KC_UP,
        KC_RCTL,    LT(0, KC_DEL), LT(_NAV, KC_BSPC), LT(_NUMPAD, KC_ENT),            LT(_SYMBOL, KC_SPC), KC_NO, KC_NO,                                                      KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_SYMBOL] = LAYOUT(
        KC_NO,           KC_NO,     KC_NO,        KC_NO,        KC_NO,        KC_NO,            KC_NO,     KC_NO,        KC_NO,        KC_NO,        KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_NO,     KC_GRAVE,     KC_MINS,      KC_EQL,       KC_NO,            KC_NO,     KC_LBRC,      KC_RBRC,      KC_QUOT,      KC_BSLS,        KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_1,      LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5,             KC_6,      RCTL_T(KC_7), RSFT_T(KC_8), RALT_T(KC_9), KC_0,           KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_NO,     KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,   KC_NO,     KC_NO,        KC_COMM,      KC_DOT,       KC_SLSH,        KC_NO,                   KC_NO,
        KC_NO,                                 KC_TRNS, LT(_FUNC, KC_BSPC), KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,                                                             KC_NO, KC_NO, KC_NO
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
        KC_NO,           KC_NO,           KC_NO,          KC_NO,         KC_NO,         KC_NO,            KC_NO,        KC_NO,            KC_NO,          KC_NO,     KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           KC_NO,           KC_NO,          KC_NO,         KC_NO,         KC_NO,            KC_NO,        KC_NO,            KC_NO,          KC_NO,     KC_NO,          KC_NO, KC_NO, KC_NO,     KC_NO,
        KC_NO,           LGUI_T(KC_ESC),  LALT_T(KC_NO),  LSFT_T(KC_NO), LCTL_T(KC_NO), KC_NO,            KC_LEFT,      KC_DOWN,          KC_UP,          KC_RGHT,   KC_NO,          KC_NO, DEAD,  KC_NO,     KC_NO,
        KC_NO,   DEAD,   KC_NO,           KC_NO,          KC_INSERT,     KC_NO,         KC_NO,   KC_NO,   KC_HOME,      KC_PAGE_DOWN,     KC_PAGE_UP,     KC_END,    KC_NO,          KC_NO,                   KC_NO,
        KC_NO,                                                      KC_TRNS, KC_TRNS, KC_TRNS,            KC_TAB, KC_TRNS, KC_TRNS,                                                                    KC_NO, KC_NO, KC_NO
    ),

    // [_TRNS] = LAYOUT(
    //     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
    //     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
    //     KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,
    //     KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,                                                            KC_TRNS, KC_TRNS, KC_TRNS
    // ),
};

// /// @brief Send key(s) with one or more modifiers, using sentinel KC_NO to mark end of arrays.
// /// @param mod_keys Null-terminated array of modifier keys (ends with KC_NO)
// /// @param target_keys Null-terminated array of target keys (ends with KC_NO)
// void send_mod_keys(const uint16_t *mod_keys, const uint16_t *target_keys) {
//     uint8_t saved_mods = get_mods();  // Save existing mods

//     clear_mods();                     // Prevent mod interference

//     // Press all mod keys
//     for (const uint16_t *k = mod_keys; *k != KC_NO; ++k) {
//         register_code(*k);
//     }

//     // Press all target keys
//     for (const uint16_t *k = target_keys; *k != KC_NO; ++k) {
//         register_code(*k);
//     }

//     // Release all target keys
//     for (const uint16_t *k = target_keys; *k != KC_NO; ++k) {
//         unregister_code(*k);
//     }

//     // Release all mod keys
//     for (const uint16_t *k = mod_keys; *k != KC_NO; ++k) {
//         unregister_code(*k);
//     }

//     set_mods(saved_mods);  // Restore original mods
// }

combo_t key_combos[] = {
    COMBO(dvorak_layer_combo, TG(_DVORAK)),
    COMBO(qwerty_layer_combo, TG(_DVORAK)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // uint8_t mod_state = get_mods();

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
            if (record->event.pressed && (alt_tabbing)) {
                tap_code(KC_LEFT);  // Left Arrow while alt tabbing
                return false;
            }
            break;
        }
        case R_SHIFT: {
            if (record->event.pressed && (alt_tabbing)) {
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
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}