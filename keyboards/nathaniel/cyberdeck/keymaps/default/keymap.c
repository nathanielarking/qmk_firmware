// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

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
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ' │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ ; │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │sft├───┐           ┌───┤num│
      *               └───┤Spc├───┐   ┌───┤bsp├───┘
      *                   └───┤nav│   │sym├───┘
      *                       └───┘   └───┘
      */
    [_COLEMAK] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOTE,    
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,     KC_I,    KC_O,        
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMMA, KC_DOT,  KC_SEMICOLON,
                                 KC_LSFT, KC_SPC,  MO(_NAV),                           MO(_SYM),   KC_BSPC, MO(_NUM)
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ' │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ ; │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │sft├───┐           ┌───┤num│
      *               └───┤Spc├───┐   ┌───┤bsp├───┘
      *                   └───┤nav│   │sym├───┘
      *                       └───┘   └───┘
      */
    [_QUERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,        
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,     KC_L,    KC_QUOTE,    
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SEMICOLON,
                                 KC_LSFT, KC_SPC,  MO(_NAV),                           MO(_SYM),   KC_BSPC, MO(_NUM)
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ ` │ = │ _ │ - │ + │       │ | │ ! │ @ │ # │ $ │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ctr│sft│ ( │ ) │alt│       │ / │ < │ > │ ? │ ~ │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ { │ } │ [ │ ] │ . │       │ \ │ % │ ^ │ & │ * │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤llk│   │sym├───┘
      *                       └───┘   └───┘
      */
    [_SYM] = LAYOUT(
        KC_GRV,        KC_EQUAL,      KC_UNDS, KC_MINS, KC_PLUS,               KC_PIPE,    KC_EXLM, KC_AT,    KC_HASH, KC_DLR,      
        OSM(MOD_LCTL), OSM(MOD_LSFT), KC_LPRN, KC_RPRN, OSM(MOD_LALT),         KC_SLASH,   KC_LABK, KC_RABK,  KC_QUES, KC_TILD,     
        KC_LCBR,       KC_RCBR,       KC_LBRC, KC_RBRC, KC_DOT,                KC_BSLS,    KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR,     
                                   _______, _______, QK_LLCK,                           _______,    _______, _______
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │esc│tab│atb│cut│cpy│       │vup│vdn│mut│del│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ctr│sft│alt│ent│pst│       │cap│up │dwn│lft│rht│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │hme│end│pgu│pgd│ins│       │cpw│und│rdo│gui│[1]│   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤nav│   │llk├───┘
      *                       └───┘   └───┘
      */
    [_NAV] = LAYOUT(
        KC_ESC,         KC_TAB,         A(KC_TAB),       C(KC_X),  C(KC_C),                               KC_VOLU,   KC_VOLD,  KC_MUTE,  KC_DEL,   DF(_COLEMAK), 
        OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LALT),   KC_ENT,   C(KC_V),                               KC_CAPS,   KC_UP,    KC_DOWN,  KC_LEFT,  KC_RGHT,     
        KC_HOME,        KC_END,         KC_PGUP,         KC_PGDN,  KC_INS,                                CW_TOGG,   C(KC_Z),  C(KC_Y),  KC_APP,   DF(_QUERTY), 
                                                 _______,         _______,  _______,                               QK_LLCK,  _______,  _______
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ f1│ f2│ f3│ f4│ f5│       │klk│ 1 │ 2 │ 3 │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ctr│sft│alt│ f6│ f7│       │   │ 4 │ 5 │ 6 │ 0 │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ f8│ f9│f10│f11│f12│       │   │ 7 │ 8 │ 9 │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤num│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤llk│   │   ├───┘
      *                       └───┘   └───┘
      */
    [_NUM] = LAYOUT(
        KC_F1,          KC_F2,          KC_F3,           KC_F4,   KC_F5,                               QK_LOCK,   KC_KP_1,  KC_KP_2,  KC_KP_3,   _______,  
        OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LALT),   KC_F6,   KC_F7,                               _______,   KC_KP_4,  KC_KP_5,  KC_KP_6,   KC_KP_0,  
        KC_F8,          KC_F9,          KC_F10,          KC_F11,  KC_F12,                              _______,   KC_KP_7,  KC_KP_8,  KC_KP_9,   _______,  
                                                 _______,         _______, QK_LLCK,                             _______,  _______,  _______
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │ l │ 4 │   │   │ac0│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │ r │ 5 │   │   │ac1│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │ m │ 6 │   │   │ac2│   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤ r ├───┘
      *                   └───┤   │   │ l ├───┘
      *                       └───┘   └───┘
      */
    [_MOUSE] = LAYOUT(
        _______,  _______,  _______,   _______,   MS_ACL0,                              MS_BTN1,  MS_BTN4,  _______,  _______,   _______,  
        _______,  _______,  _______,   _______,   MS_ACL1,                              MS_BTN2,  MS_BTN5,  _______,  _______,   _______,  
        _______,  _______,  _______,   _______,   MS_ACL2,                              MS_BTN3,  MS_BTN6,  _______,  _______,   _______,  
                                                _______,   _______, _______,                     MS_BTN1,  MS_BTN2,  _______
    ),
};

/*
void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    //pointing_device_set_cpi_on_side(true, 1000); //Set cpi on left side to a low value for slower scrolling.
    //pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
}
#ifdef POINTING_DEVICE_ENABLE

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
*/
//#endif