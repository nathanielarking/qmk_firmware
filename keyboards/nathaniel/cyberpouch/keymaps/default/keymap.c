/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define LAYER_COUNT 6

enum layer_names {
    _COLEMAK,
    _QUERTY,
    _SYM,
    _NAV,
    _NUM,
    _MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬
     * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ' │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ ; │
     * ┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴
     *               ┌───┐                   ┌───┐
     *               │sft├───┐           ┌───┤num│
     *               └───┤Spc├───┐   ┌───┤bsp├───┘
     *                   └───┤nav│   │sym├───┘
     *                       └───┘   └───┘
     */
    [_COLEMAK] = LAYOUT(
        KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,                                 KC_J,        KC_L,        KC_U,        KC_Y,        KC_QUOTE,
        KC_A,        KC_R,        KC_S,        KC_T,        KC_G,                                 KC_M,        KC_N,        KC_E,        KC_I,        KC_O,
        KC_Z,        KC_X,        KC_C,        KC_D,        KC_V,                                 KC_K,        KC_H,        KC_COMMA,    KC_DOT,      KC_SEMICOLON,
                                  KC_LSFT,     KC_SPC,      MO(_NAV),                             MO(_SYM),    MO(_NUM),    MO(_NUM)
    ),

    /*
     * ┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬
     * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ' │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ ; │
     * ┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴
     *               ┌───┐                   ┌───┐
     *               │sft├───┐           ┌───┤num│
     *               └───┤Spc├───┐   ┌───┤bsp├───┘
     *                   └───┤nav│   │sym├───┘
     *                       └───┘   └───┘
     */
    [_QUERTY] = LAYOUT(
        KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,                                 KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,
        KC_A,        KC_S,        KC_D,        KC_F,        KC_G,                                 KC_H,        KC_J,        KC_K,        KC_L,        KC_QUOTE,
        KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,                                 KC_N,        KC_M,        KC_COMMA,    KC_DOT,      KC_SEMICOLON,
                                  KC_LSFT,     KC_SPC,      MO(_NAV),                             MO(_SYM),    MO(_NUM),    KC_BSPC
    ),

    /*
     * ┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬
     * │ ` │ = │ _ │ - │ + │       │ | │ ! │ @ │ # │ $ │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ctr│sft│ ( │ ) │   │       │ / │ < │ > │ ? │ ~ │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ { │ } │ [ │ ] │   │       │ \ │ % │ ^ │ & │ * │
     * ┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤   │
     *               └───┤   ├───┐   ┌───┤   ├───┘
     *                   └───┤llk│   │sym├───┘
     *                       └───┘   └───┘
     */
    [_SYM] = LAYOUT(
        KC_GRV,        KC_EQUAL,      KC_UNDS,      KC_MINS,      KC_PLUS,                                KC_PIPE,     KC_EXLM,     KC_AT,      KC_HASH,     KC_DLR,
        OSM(MOD_LCTL), OSM(MOD_LSFT), KC_LPRN,      KC_RPRN,      _______,                                KC_SLASH,    KC_LABK,     KC_RABK,    KC_QUES,     KC_TILD,
        KC_LCBR,       KC_RCBR,       KC_LBRC,      KC_RBRC,      _______,                                KC_BSLS,     KC_PERC,     KC_CIRC,    KC_AMPR,     KC_ASTR,
                                      _______,      _______,      QK_LLCK,                                _______,     _______,     _______
    ),

    /*
     * ┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬
     * │esc│tab│gui│cut│cpy│       │mut│wlu│wld│wll│wlr│
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ctr│sft│alt│ent│pst│       |pup│up │dwn│lft│rht│
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * |vup│vdn│cap│cpw│   │       │pdn│und│rdo│hme|end│
     * ┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤del│
     *               └───┤   ├───┐   ┌───┤   ├───┘
     *                   └───┤nav│   │llk├───┘
     *                       └───┘   └───┘
     */
    [_NAV] = LAYOUT(
        KC_ESC,        KC_TAB,        KC_LEFT_GUI,  C(KC_X),      C(KC_C),                                KC_MUTE,     MS_WHLU,     MS_WHLD,    MS_WHLL,     MS_WHLR,
        OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT), KC_ENT,      C(KC_V),                                KC_PAGE_UP,  KC_UP,       KC_DOWN,    KC_LEFT,     KC_RGHT,
        KC_VOLU,       KC_VOLD,       KC_CAPS,       CW_TOGG,     _______,                                KC_PAGE_DOWN, C(KC_Z),    C(KC_Y),    KC_HOME,     KC_END,
                                      _______,       _______,     _______,                                QK_LLCK,     _______,     KC_DEL
    ),

    /*
     * ┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬
     * │ f1│ f2│ f3│ f4│ f5│       │klk│ 1 │ 2 │ 3 │ins│
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ctr│sft│alt│ f6│ f7│       │[1]│ 4 │ 5 │ 6 │ 0 │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │ f8│ f9│f10│f11│f12│       │[2]| 7 │ 8 │ 9 │psr│
     * ┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤   │
     *               └───┤   ├───┐   ┌───┤num├───┘
     *                   └───┤llk│   │   ├───┘
     *                       └───┘   └───┘
     */
    [_NUM] = LAYOUT(
        KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,                                  QK_LOCK,     KC_1,        KC_2,        KC_3,        KC_INS,
        OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT), KC_F6,         KC_F7,                                  DF(_COLEMAK), KC_4,       KC_5,        KC_6,        KC_0,
        KC_F8,         KC_F9,         KC_F10,        KC_F11,        KC_F12,                                 DF(_QUERTY), KC_7,        KC_8,        KC_9,        KC_PSCR,
                                      _______,       _______,       QK_LLCK,                                _______,     _______,     _______
    ),

    /*
     * ┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬
     * │   │   │   │   │ac0│       │ l │ 4 │   │   │   │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │   │   │   │   │ac1│       │ r │ 5 │   │   │   │
     * ┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼
     * │   │   │   │   │ac2│       │ m │ 6 │   │   │   │
     * ┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤   │
     *               └───┤   ├───┐   ┌───┤   ├───┘
     *                   └───┤   │   │   ├───┘
     *                       └───┘   └───┘
     */
    [_MOUSE] = LAYOUT(
        _______,       _______,       _______,       _______,       MS_ACL0,                                MS_BTN1,     MS_BTN4,     _______,     _______,     _______,
        _______,       _______,       _______,       _______,       MS_ACL1,                                MS_BTN2,     MS_BTN5,     _______,     _______,     _______,
        _______,       _______,       _______,       _______,       MS_ACL2,                                MS_BTN3,     MS_BTN6,     _______,     _______,     _______,
                                      _______,       _______,       _______,                                _______,     _______,     _______
    ),
};
