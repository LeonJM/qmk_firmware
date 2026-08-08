// Ported from keyboards/monsgeek/m6/keymaps/LeonJM on the MonsGeek M6.
//
// The two boards are both 65% Alice-style splits, so rows 0-3 translate almost
// 1:1. The differences that mattered:
//   - The M6 has three left thumb keys; the Split 65 has one (a 3u spacebar).
//     That key takes Backspace/_NAV, and the M6's _NUMPAD layer was dropped.
//   - Delete moved to the right pinky column, where the factory legend says Del.
//   - [7,8] is the encoder push-button (no keycap, no LED) and toggles _NORMAL.
//   - _NORMAL is the stock factory layout verbatim, so the board can be handed
//     to someone else; its Fn key opens _STOCKFN, a copy of the vendor Fn layer.

#include QMK_KEYBOARD_H

// Base Layer Shortcuts
#define CUT_X LT(0, KC_X)
#define COPY_C LT(0, KC_C)
#define PASTE_V LT(0, KC_V)

// Base Layer Shortcuts (Dvorak)
#define CUT_X2 LT(0, KC_Q)
#define COPY_C2 LT(0, KC_J)
#define PASTE_V2 LT(0, KC_K)

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

// Layer numbering is not free here, for two reasons.
//
// 1. split65.c hardcodes its own enum (_BL=0, _FL=1, _MBL=2, _MFL=3) and tests
//    keymap_is_mac_system() as "default_layer_state is 2 or 3". That macro gates
//    ~30 branches of Mac/Windows key remapping in process_record_kb. _NORMAL is a
//    *persistent default layer*, so it must avoid 2 and 3 or the board silently
//    enters Mac mode. Hence the gap.
// 2. QMK resolves keys from the highest active layer down, and default_layer_state
//    counts. So every momentary layer must sit ABOVE _NORMAL, or it would be
//    invisible whenever _NORMAL is the default.
enum __layers {
    _BASE    = 0,
    _DVORAK  = 1,
    _NORMAL  = 4,
    _SYMBOL  = 5,
    _FUNC    = 6,
    _NAV     = 7,
    _STOCKFN = 8
};

enum custom_keycodes {
    TG_NORM = SAFE_RANGE,   // toggle _BASE <-> _NORMAL, remembered across power cycles
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG_NORM,
        KC_NO,   KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,   KC_NO,   KC_NO,   KC_DEL,
        KC_NO,   L_WIN,   L_ALT,   L_SHIFT,  L_CTRL,   KC_G,                 KC_H,    R_CTRL,  R_SHIFT, R_ALT,   R_WIN,   KC_NO,   KC_ENT,           KC_NO,
        KC_NO,   KC_Z,    CUT_X,   COPY_C,   PASTE_V,  KC_B,                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   LT(_NAV, KC_BSPC),                        LT(_SYMBOL, KC_SPC), KC_NO, MO(_FUNC), KC_NO,         KC_NO,   KC_NO,   KC_NO
    ),

    [_DVORAK] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_NO,   KC_QUOT, KC_COMM, KC_DOT,   KC_P,     KC_Y,                 KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_NO,   L_WIN,   L_ALT2,  L_SHIFT2, L_CTRL2,  KC_I,                 KC_D,    R_CTRL2, R_SHIFT2,R_ALT2,  R_WIN2,  KC_NO,   KC_TRNS,          KC_NO,
        KC_NO,   KC_SCLN, CUT_X2,  COPY_C2,  PASTE_V2, KC_X,                 KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,             KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   LT(_NAV, KC_BSPC),                        LT(_SYMBOL, KC_SPC), KC_NO, MO(_FUNC), KC_NO,         KC_NO,   KC_NO,   KC_NO
    ),

    // The stock factory layout, verbatim, so the board can be handed to anyone.
    // Only deviation: the knob press is KC_TRNS so it falls through to _BASE's
    // TG(_NORMAL) and toggles back out.
    [_NORMAL] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,     KC_4,     KC_5,    KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TG_NORM,
        KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,     KC_F,     KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                                   KC_SPC,  KC_RALT, MO(_STOCKFN), KC_RCTL,              KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_SYMBOL] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_GRAVE,KC_MINS,  KC_EQL,   KC_NO,                KC_NO,   KC_LBRC, KC_RBRC, KC_QUOT, KC_BSLS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_NO,   LGUI_T(KC_1), LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5,       KC_6, RCTL_T(KC_7), RSFT_T(KC_8), RALT_T(KC_9), RGUI_T(KC_0), KC_NO, KC_TRNS, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                KC_NO,   KC_NO,   KC_COMM, KC_DOT,  KC_SLSH,          KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_TRNS, KC_TRNS, LT(_FUNC, KC_BSPC),                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO,   KC_NO,   KC_NO
    ),

    [_FUNC] = LAYOUT(
        QK_BOOT, KC_BT1,  KC_BT2,  KC_BT3,   KC_2G4,   KC_BATQ, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_F11,  KC_F12,  KC_F13,   KC_F14,   KC_F15,               KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,                KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,   KC_TRNS,          KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO,   KC_NO,   KC_NO
    ),

    [_NAV] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_NO,   LGUI_T(KC_ESC), LALT_T(KC_NO), LSFT_T(KC_NO), LCTL_T(KC_NO), KC_NO,  KC_LEFT, RCTL_T(KC_DOWN), RSFT_T(KC_UP), RALT_T(KC_RGHT), RGUI_T(KC_NO), KC_NO, KC_TRNS, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_INSERT,KC_NO,                KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,            KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,                                  KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO,   KC_NO,   KC_NO
    ),

    // The vendor's Fn layer, so _NORMAL behaves exactly like a factory board.
    // Three vendor keycodes removed: TO(_MBL) and KC_FILP both manipulate
    // default_layer_state and would strand the board under our layer numbering,
    // and KC_A on the A key was a vendor leftover.
    [_STOCKFN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  EE_CLR,  KC_TRNS,
        RM_NEXT, KC_BT1,  KC_BT2,  KC_BT3,   KC_2G4,   KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_HUED, RM_HUEU, KC_TRNS, KC_INS,
        KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_SATD, RM_SATU, KC_TRNS,          KC_HOME,
        KC_TRNS, KC_TRNS, RM_TOGG, KC_TRNS,  KC_TRNS,  KC_TRNS,              NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, RM_VALU, KC_END,
        KC_TRNS, GU_TOGG, KC_TRNS, KC_BATQ,                                  KC_BATQ, KC_TRNS, KC_TRNS, KC_TRNS,                   RM_SPDD, RM_VALD, RM_SPDU
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_DVORAK]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NORMAL]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYMBOL]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FUNC]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAV]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_STOCKFN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif
// clang-format on

combo_t key_combos[] = {
    COMBO(dvorak_layer_combo, TG(_DVORAK)),
    COMBO(qwerty_layer_combo, TG(_DVORAK)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case TG_NORM: {
            // Swap the default layer rather than toggling one on top, so QMK
            // persists the choice to EEPROM and the board comes back where you
            // left it. _NORMAL is the stock layout; _BASE is the custom one.
            if (record->event.pressed) {
                set_single_persistent_default_layer(
                    get_highest_layer(default_layer_state) == _NORMAL ? _BASE : _NORMAL);
            }
            return false;
        }
        case CUT_X:
        case CUT_X2: {
            // Intercept hold function to send Ctrl-X
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X));
                return false;
            }
            break;
        }
        case COPY_C:
        case COPY_C2: {
            // Intercept hold function to send Ctrl-C
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C));
                return false;
            }
            break;
        }
        case PASTE_V:
        case PASTE_V2: {
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
        case L_ALT2:
        case R_ALT:
        case R_ALT2:
        case R_WIN:
        case R_WIN2:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

// Paint every LED. No need to spare the indicator positions: the vendor's
// rgb_matrix_indicators_advanced_kb() calls this hook *first* and only then
// paints caps lock, win lock, the BT/2.4G pairing blink and the battery gauge,
// so those overlay us and still win. They are event-driven anyway -- they only
// paint while charging, on low battery, or during a pairing blink.
static void wash(uint8_t led_min, uint8_t led_max, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, r, g, b);
    }
}

// _NORMAL gets a horizontal gradient instead of a flat wash: light blue at the
// G/H seam fading to light purple at the outer edges. G's LED sits at x=79 and
// H's at x=93, so the seam is 86.
//
// Each side is normalised to its own width rather than to absolute distance.
// The right half is physically wider (brackets, backslash, arrows, pinky column)
// so it reaches x=210 while the left only reaches x=0 -- scaling by raw distance
// would leave the left edge visibly less purple than the right.
#define GRAD_SEAM  86
#define GRAD_LEFT  86    // seam -> x=0
#define GRAD_RIGHT 124   // seam -> x=210

static void gradient(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        int16_t  dx   = (int16_t)g_led_config.point[i].x - GRAD_SEAM;
        uint16_t span = (dx < 0) ? GRAD_LEFT : GRAD_RIGHT;
        if (dx < 0) dx = -dx;

        uint16_t t = ((uint16_t)dx * 255) / span;   // 0 at the seam, 255 at either edge
        if (t > 255) t = 255;

        rgb_matrix_set_color(i,
                             110 + (uint8_t)((90 * t) / 255),    // 110 -> 200
                             200 - (uint8_t)((50 * t) / 255),    // 200 -> 150
                             255);                               // blue stays pinned
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            wash(led_min, led_max, 255, 255, 255);  // White
            break;
        case _DVORAK:
            wash(led_min, led_max, 0, 255, 255);    // Cyan
            break;
        case _NORMAL:
            gradient(led_min, led_max);             // Light blue centre -> light purple edges
            break;
        case _SYMBOL:
            wash(led_min, led_max, 128, 0, 255);    // Purple
            break;
        case _FUNC:
            wash(led_min, led_max, 255, 0, 0);      // Red
            break;
        case _NAV:
            wash(led_min, led_max, 255, 255, 0);    // Yellow
            break;
        // _STOCKFN deliberately has no case: leaving the stock effect visible is
        // what makes its RGB brightness/hue/effect keys usable.
    }
    return true;    // Let the vendor's caps / win lock / battery overlays paint on top
}

// Required by the split transport: without this the halves never handshake.
bool is_keyboard_master(void) {
    setPinInput(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
}
