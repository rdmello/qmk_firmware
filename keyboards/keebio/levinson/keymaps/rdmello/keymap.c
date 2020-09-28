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
  COLEMAK,
  DVORAK,
};

/* COMMON ROW
 * ,-------------------------------------------------------------------------------------------.
 * |Adjust|Raise |Lower | Ctrl  | LOWER| GUI(SPC)| |    SPC | RAISE| Alt | GUI |      |      |
 * `-------------------------------------------------------------------------------------------'
 */
#define RYLAN_LAYOUT(...) LAYOUT_ortho_4x12( \
   __VA_ARGS__, \
   ADJUST, RAISE, LOWER, KC_LCTL, LOWER, LGUI_T(KC_SPC),      KC_SPC, RAISE, KC_LALT, KC_LGUI, _______, _______ \
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
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P, KC_BSPC,   \
  CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,   \
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_SFTENT  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |M-BTN2| M-UP |M-BTN1| PGUP | HOME |  `   | -    | =    |  [   |  ]   |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  ESC | M-LT | M-DN | M-RT | PGDN | END  | LEFT | DOWN |  UP  |RIGHT |  \   | LOCK |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SHIFT |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | ENTER|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |                                    COMMON ROW                                     |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] =  RYLAN_LAYOUT( \
  KC_TILD,        KC_BTN2, KC_MS_U, KC_BTN1, KC_PGUP, KC_HOME,      KC_GRV, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_DEL, \
  CTL_T(KC_ESC),  KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN,  KC_END,     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSLS, KC_LOCK, \
  KC_LSFT,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ENT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |M-BTN2|M-SRUP|M-BTN1|      |      |  ~   |  _   |  +   |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |M-SRLT|M-SRDN|M-SRRT|      |      |FFXBCK| PGDN | PGUP |FFXFWD|   |  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |  ^   |  &   |   *  |  (   |   )  |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |                                    COMMON ROW                                     |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = RYLAN_LAYOUT( \
  _______, KC_BTN2, KC_WH_U, KC_BTN1, _______, _______,  KC_TILD,    KC_UNDS, KC_PLUS,    KC_LCBR, KC_RCBR, _______, \
  _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,  G(KC_LBRC), KC_PGDN, KC_PGUP, G(KC_RBRC), KC_PIPE, _______, \
  KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,  KC_CIRC,    KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, KC_PIPE  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |M-SPD2| MUTE | VOL+ |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |M-SPD1| BRI- | VOL- | BRI+ |      |      |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |M-SPD0|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      | TGL  | TGL  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  KC_ACL2, KC_MUTE, KC_VOLU, _______,  DVORAK, _______,       _______, _______, _______, _______, _______, _______, \
  KC_ACL1, KC_BRID, KC_VOLD, KC_BRIU,  QWERTY, _______,       _______, _______, _______, _______, _______,  KC_F12, \
  KC_ACL0,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, \
  _______, _______, _______, _______, _______, MAGIC_TOGGLE_CTL_GUI,       _______, _______, MAGIC_TOGGLE_CTL_GUI, _______, _______, _______  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = RYLAN_LAYOUT( \
         KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  CTL_T(KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = RYLAN_LAYOUT( \
         KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  CTL_T(KC_ESC),  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
        KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SFTENT \
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
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
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
