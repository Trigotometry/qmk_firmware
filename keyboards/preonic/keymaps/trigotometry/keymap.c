#include "preonic.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Layer declarations
enum preonic_layers {
  _DVORAK = 0,
  _QWERTY = 1,
  _GAMING = 2,
  _LOWER = 3,
  _RAISE = 4,
};

enum preonic_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  GAMING,
  LOWER,
  RAISE,
};

// QMK predefined macros
#define SFT_ENT   SFT_T(KC_ENT)   // Tap for Enter, hold for Shift

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | GEsc |  1   |  2   |  3   |  4   |  5   |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  "   |  ,   |  .   |  P   |  Y   |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Shift |  A   |  O   |  E   |  U   |  I   |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SFTENT|  ;   |  Q   |  J   |  K   |  X   |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    | Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,  KC_7,  KC_8,    KC_9,    KC_0,  KC_DEL },
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,  KC_G,  KC_C,    KC_R,    KC_L,  KC_BSPC},
  {KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,  KC_H,  KC_T,    KC_N,    KC_S,  KC_SLSH},
  {SFT_ENT, KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,  KC_M,  KC_W,    KC_V,    KC_Z,  KC_ENT },
  {XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC,RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},

  /* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | GEsc |  1   |  2   |  3   |  4   |  5   |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shft |  A   |  S   |  D   |  F   |  G   |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SFTENT|  Z   |  X   |  C   |  V   |  B   |   N  |   M  |   ,  |   .  |   /  | Entr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | Supr |Lower |    Space    | Raise| Left | Down |  Up  | Rght |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {SFT_ENT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT},
  {XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Grve |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  Y   |  U   |  I   |  O   |  P   | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shft |   A  |   S  |   D  |   F  |   G  |  H   |  J   |  K   |  L   |  ;   |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |  N   |  M   |  ,   |  .   |  /   | Entr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | Alt  | Alt  |Lower |    Space    | Raise| Left | Down |  Up  | Rght |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LCTL, KC_LALT, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |   *  |   /  |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | VolD |  Up  | VolU |      |      |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Left | Down | Rght |      |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Prev | Play | Skip |      |      |   1  |   2  |   3  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Supr |      |             |   0  | Home |PageDn|PageUp|  End |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_PAST, KC_PSLS, XXXXXXX, KC_DEL },
  {_______, XXXXXXX, KC_VOLD, KC_UP,   KC_VOLU, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_BSPC},
  {_______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PPLS, XXXXXXX},
  {_______, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PEQL, KC_ENT },
  {_______, _______, _______, KC_LGUI, _______, _______, _______, KC_0,    KC_HOME, KC_PGDN, KC_PGUP, KC_END }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  \   |      |      |   /  |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  |   |  [   |  {   |  (   |  <   |   >  |   )  |   }  |   ]  |   |  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  +   |  -   |   _  |   =  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |Dvorak|Qwerty| Game | Reset|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 },
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX, XXXXXXX, KC_PSLS, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK, KC_RABK, KC_RPRN, KC_RCBR, KC_RBRC, KC_PIPE, XXXXXXX},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_PMNS, KC_UNDS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, DVORAK,  QWERTY,  GAMING,    RESET}
}

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

        case DVORAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_DVORAK);
          }
          return false;
          break;
          
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;

        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
          } else {
            layer_off(_LOWER);
          }
          return false;
          break;

        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
          } else {
            layer_off(_RAISE);
          }
          return false;
          break;

        case GAMING:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_GAMING);
          }
          return false;
          break;

      }
    return true;
};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_D5, 8},
  {NOTE_E6, 8},
  {NOTE_D6, 8},
  {NOTE_E5, 8}
};

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
}
#endif
