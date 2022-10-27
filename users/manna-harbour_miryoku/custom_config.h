// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

/* This sets up just the numbers to be reversed so that you still operate one with your pointer just like an actual number pad.   */
#define MIRYOKU_LAYER_NUM \
KC_LBRC,           KC_9,              KC_8,              KC_7,              KC_RBRC,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         QK_BOOT,           \
KC_SCLN,           KC_6,              KC_5,              KC_4,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_GRV,            KC_3,              KC_2,              KC_1,              KC_BSLS,           U_NA,              DF(U_NUM),         DF(U_NAV),         KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

/* Mimic the symbol layer, so that the symbols line up with the numbers on the reversed number pad */
#define MIRYOKU_LAYER_SYM \
KC_LCBR,           KC_LPRN,           KC_ASTR,           KC_AMPR,           KC_RCBR,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         QK_BOOT,           \
KC_COLN,           KC_CIRC,           KC_PERC,           KC_DLR,            KC_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_TILD,           KC_HASH,           KC_AT,             KC_EXLM,           KC_PIPE,           U_NA,              DF(U_SYM),         DF(U_MOUSE),       KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_LPRN,           KC_RPRN,           KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

/* Lastly align the fuction numbers with the numbers on the num layer so that you can reuse the muscle memory. */
#define MIRYOKU_LAYER_FUN \
KC_F12,            KC_F9,             KC_F8,             KC_F7,             KC_PSCR,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         QK_BOOT,           \
KC_F11,            KC_F6,             KC_F5,             KC_F4,             KC_SLCK,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_F10,            KC_F3,             KC_F2,             KC_F1,             KC_PAUS,           U_NA,              DF(U_FUN),         DF(U_MEDIA),       KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP



// Sofle Specific Config
#if defined (KEYBOARD_sofle)

#define XXX KC_NO
#define ESC_CTL CTL_T(KC_ESC)

/*
  Define the rest of the keys for the default mapping in case someone else needs to use my keyboard/PC so that more of the legends match up, and it should feel more natural, save for the HRMs.
  Mimics my previous keymaping before adopting miryoku
*/
#define MIRYOKU_MAPPING(                                                 \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT(\
KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5,               KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,\
KC_TAB,  K00,  K01,  K02,  K03,  K04,                K05,  K06,  K07,  K08,  K09,  KC_BSPC,\
ESC_CTL, K10,  K11,  K12,  K13,  K14,                K15,  K16,  K17,  K18,  K19,  KC_SCLN,\
KC_LSFT, K20,  K21,  K22,  K23,  K24, XXX,      XXX, K25,  K26,  K27,  K28,  K29,  KC_RSFT,\
          XXX, XXX,  K32,  K33,  K34,                K35,  K36,  K37,  XXX,  XXX\
)

/*
  Make use of the tap layer to work for FPS games with minimal special configurations
  Here we:
    * Move escape up to replace GRAVE and put GRAVE where the BACKSPACE key, would normally be.
    * Add a key to one of the non-used keys to switch back to the normal base layer when we are done with a game.
*/
#define MIRYOKU_LAYERMAPPING_TAP(                                                 \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT(\
KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,               KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,\
KC_TAB,  K00,  K01,  K02,  K03,  K04,                K05,  K06,  K07,  K08,  K09,  KC_GRAVE,\
KC_LCTL, K10,  K11,  K12,  K13,  K14,                K15,  K16,  K17,  K18,  K19,  KC_SCLN,\
KC_LSFT, K20,  K21,  K22,  K23,  K24, XXX,      XXX, K25,  K26,  K27,  K28,  K29,  KC_RSFT,\
         XXX,  XXX,  K32,  K33,  K34,                K35,  K36,  K37,  XXX,  DF(U_BASE) \
)

#endif
