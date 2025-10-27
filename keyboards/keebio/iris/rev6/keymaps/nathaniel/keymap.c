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

#define LAYER_COUNT 5

enum layer_names {
    _COLEMAK,
    _QUERTY,
    _SYM,
    _NAV,
    _NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______,  _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOTE, _______,     
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,     KC_I,    KC_O, _______,       
        _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, _______,            _______,  KC_K,    KC_H,    KC_COMMA, KC_DOT,  KC_SEMICOLON, _______,
                                 KC_LSFT, KC_SPC,  MO(_NAV),                          MO(_SYM),   MO(_NUM), KC_BSPC
    ),

    [_QUERTY] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______,  _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,     KC_O,    KC_P, _______,        
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,     KC_L,    KC_QUOTE, _______,    
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______,             _______, KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SEMICOLON, _______,
                                  KC_LSFT, KC_SPC,  MO(_NAV),                            MO(_SYM),   MO(_NUM), KC_BSPC
    ),

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______,  _______, _______, _______,
        _______, KC_GRV,        KC_EQUAL,      KC_UNDS, KC_MINS, KC_PLUS,                 KC_PIPE,    KC_EXLM, KC_AT,    KC_HASH, KC_DLR, _______,
        _______, OSM(MOD_LCTL), OSM(MOD_LSFT), KC_LPRN, KC_RPRN, _______,                KC_SLASH,   KC_LABK, KC_RABK,  KC_QUES, KC_TILD, _______,
        _______, KC_LCBR,       KC_RCBR,       KC_LBRC, KC_RBRC, _______, _______,   _______,       KC_BSLS,    KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, _______,
                                   _______, _______, QK_LLCK,                            _______, _______, _______
    ),

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                                    _______, _______, _______,  _______, _______, _______,
        _______, KC_ESC,         KC_TAB,         KC_LEFT_GUI,       C(KC_X),  C(KC_C),                               KC_MUTE,   MS_WHLU,  MS_WHLD,  MS_WHLL,   MS_WHLR, _______, 
        _______, OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LALT),   KC_ENT,   C(KC_V),                               KC_PAGE_UP,   KC_UP,    KC_DOWN,  KC_LEFT,  KC_RGHT, _______,     
        _______, KC_VOLU,        KC_VOLD,        KC_CAPS,         CW_TOGG,  _______, _______, _______,             KC_PAGE_DOWN,   C(KC_Z),  C(KC_Y),  KC_HOME,   KC_END, _______,  
                                                 _______,         _______,  _______,                               QK_LLCK,  _______,  KC_DEL
    ),

    [_NUM] = LAYOUT(
        _______, _______,       _______,       _______,       _______,       _______,                                _______, _______, _______, _______, _______, _______,
        _______, KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,                                  QK_LOCK,     KC_1,        KC_2,        KC_3,        KC_INS,      _______,
        _______, OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT), KC_F6,         KC_F7,                                  DF(_COLEMAK), KC_4,       KC_5,        KC_6,        KC_0,       _______,
        _______, KC_F8,         KC_F9,         KC_F10,        KC_F11,        KC_F12, _______,               _______, DF(_QUERTY), KC_7,        KC_8,        KC_9,        KC_PSCR,       _______,
                                      _______,       _______,       QK_LLCK,                                _______,     _______,     _______
    ),
};
