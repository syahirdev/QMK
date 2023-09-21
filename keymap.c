/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  BACKLIT
};

#define COMMENT LCTL(KC_SLSH)
#define DBKSP LCTL(KC_BSPC)

#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)

#define SELECT LCTL(KC_A)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define SAVE LCTL(KC_S)

#define REFRESH LCTL(KC_R)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 *,-----------------------------------------------------------------------------------------------------------------------.
 *|   Esc   |   1 !   |   2 @   |   3 #   |   4 $   |   5 %   |   6 ^   |   7 &   |   8 *   |   9 (   |   0 )   |   Del   |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|   Tab   |    Q    |    W    |    F    |    P    |    G    |    J    |    L    |    U    |    Y    |    -    |    /    |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|  ←Bksp  |    A    |    R    |    S    |    T    |    D    |    H    |    N    |    E    |    I    |    O    |  Enter  |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|  Shift  |    Z    |    X    |    C    |    V    |    B    |    K    |    M    |    '"   |    ;:   |   (↑)   |    )    |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|  Brite  |   GUI   |   Alt   |   Ctrl  |  LOWER  |       Space       |  RAISE  |   (←)   |   (←)   |   (↓)   |   (→)   |
 *`-----------------------------------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
  KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_MINS,  KC_SLSH,
  KC_BSPC,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_ENT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_QUOT,  KC_SCLN,  KC_UP,    KC_RPRN,
  BACKLIT,  KC_LGUI,  KC_LALT,  KC_LCTL,  LOWER,    KC_SPC,   KC_SPC,   RAISE,    KC_LEFT,  KC_LEFT,  KC_DOWN,  KC_RGHT
),
/* Qwerty
 *,-----------------------------------------------------------------------------------------------------------------------.
 *|   Esc   |   1 !   |   2 @   |   3 #   |   4 $   |   5 %   |   6 ^   |   7 &   |   8 *   |   9 (   |   0 )   |   Del   |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|   Tab   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |    /    |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|  ←Bksp  |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    -    |  Enter  |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|  Shift  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    '"   |    ;:   |   (↑)   |    )    |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|  Brite  |   GUI   |   Alt   |   Ctrl  |  LOWER  |       Space       |  RAISE  |   (←)   |   (←)   |   (↓)   |   (→)   |
 *`-----------------------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_SLSH,
  KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_MINS,  KC_ENT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_QUOT,  KC_SCLN,  KC_UP,    KC_RPRN,
  BACKLIT,  KC_LGUI,  KC_LALT,  KC_LCTL,  LOWER,    KC_SPC,   KC_SPC,   RAISE,    KC_LEFT,  KC_LEFT,  KC_DOWN,  KC_RGHT
),

/* Lower
 *,-----------------------------------------------------------------------------------------------------------------------.
 *|         | Ctrl+Y  |         |         |         |         |         |         |         |         |         |         |
 *|         | REDO    |         |         |         |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *| Ctrl+/  | Ctrl+Z  |         |  HOME   |   END   |         |         |         |   (↑)   |         |         |         |
 *| COMMENT | UNDO    |         |         |         |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|Ctrl+Bksp| Ctrl+A  | Ctrl+X  | Ctrl+C  | Ctrl+V  |    {    |    }    |   (←)   |   (↓)   |   (→)   |         |         |
 *| ←←Bksp  | SELECT  | CUT     | COPY    | PASTE   |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|         |         |         |         | Ctrl+S  |    [    |    ]    |         |         |         |         |         |
 *|         |         |         |         | SAVE    |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *| CTRL+R  |         |         |         |         |                   |         |         |         |         |         |
 *| REFRESH |         |         |         |         |                   |         |         |         |         |         |
 *`-----------------------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_NO,    REDO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  COMMENT,  UNDO,     KC_NO,    KC_HOME,  KC_END,   KC_NO,    KC_NO,    KC_NO,    KC_UP,    KC_NO,    KC_NO,    KC_NO,
  DBKSP,    SELECT,   CUT,      COPY,     PASTE,    KC_LCBR,  KC_RCBR,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    SAVE,     KC_LBRC,  KC_RBRC,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  REFRESH,  KC_NO,    KC_NO,    KC_NO,    _______,  KC_NO,    KC_NO,    _______,  KC_NO,    KC_NO,    KC_NO,    KC_NO
),

/* Raise
 *,-----------------------------------------------------------------------------------------------------------------------.
 *|         |         |         |         |         |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|         |         |         |         |         |         |         |   7 &   |   8 *   |   9 (   |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|         |    +    |    -    |    *    |    /    |         |         |   4 $   |   5 %   |   6 ^   |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|         |         |         |         |         |         |         |   1 !   |   2 @   |   3 #   |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|         |         |         |         |         |                   |         |   0 )   |         |         |    .    |
 *`-----------------------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_7,     KC_8,     KC_9,     KC_NO,    KC_NO,
  KC_NO,    KC_PPLS,  KC_PMNS,  KC_PAST,  KC_PSLS,  KC_NO,    KC_NO,    KC_4,     KC_5,     KC_6,     KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_1,     KC_2,     KC_3,     KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    _______,  KC_NO,    KC_NO,    _______,  KC_0,     KC_NO,    KC_NO,    KC_DOT
),

/* Adjust (Lower + Raise)
 *,-----------------------------------------------------------------------------------------------------------------------.
 *|         | TYPE:   | TYPE:   |         |         |         |         |   F10   |   F11   |   F12   |         |  RESET  |
 *|         | COLEMAK | QWERTY  |         |         |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|         |         |         |         |  PRNT   |         |         |   F7    |   F8    |   F9    |         |         |
 *|         |         |         |         |  SCRN   |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|         |         |         |         |         |         |         |   F4    |   F5    |   F6    |         |         |
 *|         |         |         |         |         |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|  HUE+   |  SAT+   | BRGHT+  |  CALC   |         |         |         |   F1    |   F2    |   F3    |  VOL+   |         |
 *|         |         |         |  ULATOR |         |         |         |         |         |         |         |         |
 *|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 *|  HUE-   |  SAT-   | BRGHT-  |         |         |                   |         |         |         |  VOL-   |         |
 *|         |         |         |         |         |                   |         |         |         |         |         |
 *`-----------------------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_NO,    COLEMAK,  QWERTY,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F10,   KC_F11,   KC_F12,   KC_NO,    QK_BOOT,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PSCR,  KC_NO,    KC_NO,    KC_F7,    KC_F8,    KC_F9,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F4,    KC_F5,    KC_F6,    KC_NO,    KC_NO,
  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_CALC,  KC_NO,    KC_NO,    KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_VOLU,  KC_NO,
  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,    _______,  KC_NO,    KC_NO,    _______,  KC_NO,    KC_NO,    KC_VOLD,  KC_NO
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
