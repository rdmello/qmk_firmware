#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

/* COMMON ROW
 * ,----------------------------------------- ------------------------------------------.
 * |Adjust|Raise |Space | GUI  | LOWER| Ctrl| |Space | RAISE| Alt  |      |      |      |
 * `----------------------------------------- ------------------------------------------'
 */
#define RYLAN_LAYOUT(...) LAYOUT_ortho_5x12( \
   __VA_ARGS__, \
   ADJUST, RAISE, KC_SPC, KC_LGUI, LOWER, KC_LCTL,      KC_SPC, RAISE, KC_LALT, _______,  _______, _______ \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |                                    COMMON ROW                                     |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = RYLAN_LAYOUT( \
  _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,       KC_I,    KC_O,    KC_P, KC_BSPC,   \
  CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,       KC_K,    KC_L, KC_SCLN, KC_QUOT,   \
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH, KC_SFTENT  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |M-BTN2| M-UP |M-BTN1|M-SRUP| HOME |  `   | -    | =    |  [   |  ]   |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  ESC | M-LT | M-DN | M-RT |M-SRDN| END  | LEFT | DOWN |  UP  |RIGHT |  \   | LOCK |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SHIFT |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | ENTER|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |                                    COMMON ROW                                     |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] =  RYLAN_LAYOUT( \
  _______, _______, _______, _______,       _______, _______,     _______, _______, _______, _______, _______, _______, 
  KC_TILD, KC_BTN2, KC_MS_U, KC_BTN1, KC_MS_WH_DOWN, KC_HOME,      KC_GRV, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_DEL, \
  KC_ESC,  KC_MS_L, KC_MS_D, KC_MS_R,   KC_MS_WH_UP,  KC_END,     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSLS, KC_LOCK, \
  KC_LSFT,    KC_1,    KC_2,    KC_3,          KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ENT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |  ~   |  _   |  +   |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   .  |   0  |   9  |   8  |   7  |   6  |FFXBCK| PGDN | PGUP |FFXFWD|   |  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |  ^   |  &   |   *  |  (   |   )  |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |                                    COMMON ROW                                     |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = RYLAN_LAYOUT( \
  _______, _______, _______, _______, _______, _______,        _______, _______, _______,    _______, _______, _______, 
  KC_EQL,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_TILD,    KC_UNDS, KC_PLUS,    KC_LCBR, KC_RCBR, _______, \
  KC_DOT,     KC_0,    KC_9,    KC_8,    KC_7,    KC_6,     G(KC_LEFT), KC_PGDN, KC_PGUP, G(KC_RGHT), KC_PIPE, _______, \
  KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     KC_CIRC,    KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, KC_PIPE  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | MUTE | VOL+ |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | BRI- | VOL- | BRI+ |      |      |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |                                    COMMON ROW                                     |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = RYLAN_LAYOUT( \
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, 
  _______, KC_MUTE, KC_VOLU, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
  _______, KC_BRID, KC_VOLD, KC_BRIU, _______, _______,       _______, _______, _______, _______, _______,  KC_F12, \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11  \
)
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
