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
    _MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOTE,     
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,     KC_I,    KC_O,       
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMMA, KC_DOT,  KC_SEMICOLON,
                                 KC_LSFT, KC_SPC,  MO(_NAV),                           MO(_SYM),   MO(_NUM), KC_BSPC 

  ),

    [_QUERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,        
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,     KC_L,    KC_QUOTE,    
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SEMICOLON,
                                  KC_LSFT, KC_SPC,  MO(_NAV),                           MO(_SYM),   MO(_NUM), KC_BSPC 
  ),

    [_SYM] = LAYOUT_split_3x5_3(
        KC_GRV,        KC_EQUAL,      KC_UNDS, KC_MINS, KC_PLUS,               KC_PIPE,    KC_EXLM, KC_AT,    KC_HASH, KC_DLR,
        OSM(MOD_LCTL), OSM(MOD_LSFT), KC_LPRN, KC_RPRN, OSM(MOD_LALT),         KC_SLASH,   KC_LABK, KC_RABK,  KC_QUES, KC_TILD,
        KC_LCBR,       KC_RCBR,       KC_LBRC, KC_RBRC, KC_DOT,                KC_BSLS,    KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR,
                                   _______, _______, QK_LLCK,                           _______,    _______, _______
  ),

    [_NAV] = LAYOUT_split_3x5_3(
        KC_ESC,         KC_TAB,         _______,       C(KC_X),  C(KC_C),                               KC_VOLU,   KC_VOLD,  KC_MUTE,  KC_DEL,   DF(_COLEMAK), 
        OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LALT),   KC_ENT,   C(KC_V),                               KC_CAPS,   KC_UP,    KC_DOWN,  KC_LEFT,  KC_RGHT,      
        KC_HOME,        KC_END,         KC_PGUP,         KC_PGDN,  KC_INS,                                CW_TOGG,   C(KC_Z),  C(KC_Y),  KC_LGUI,   DF(_QUERTY),  
                                                 _______,         _______,  _______,                               QK_LLCK,  _______,  _______
  ),

    [_NUM] = LAYOUT_split_3x5_3(
        KC_F1,          KC_F2,          KC_F3,           KC_F4,   KC_F5,                               QK_LOCK,   KC_1,  KC_2,  KC_3,   _______,
        OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LALT),   KC_F6,   KC_F7,                               _______,   KC_4,  KC_5,  KC_6,   KC_KP_0,
        KC_F8,          KC_F9,          KC_F10,          KC_F11,  KC_F12,                              _______,   KC_7,  KC_8,  KC_9,   _______,
                                                 _______,         _______, QK_LLCK,                             _______,  _______,  _______
  )
};
