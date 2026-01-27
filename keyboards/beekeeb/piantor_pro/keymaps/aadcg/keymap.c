// SPDX-FileCopyrightText: 2025-2026 André A. Gomes
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* FIXME douple tap on backspace key (which doubles as a nav layer) enables
   delete on hold... */

/* Add C-M on hold for W and O keys? */
/* Add alpha layer without tap/hold keys? (game layer) */
/* Try AltGr as a one shot modifier */

#define L1_BSPC LT(1,KC_BSPC)   // Tap for ⌫  ; Hold for L1
#define L2_H    LT(2,KC_H)      // Tap for H   ; Hold for L2
#define L2_DEL  LT(2,KC_DEL)    // Tap for DEL ; Hold for L2
#define L3_TAB  LT(3,KC_TAB)    // Tap for TAB ; Hold for L3
#define C_D     CTL_T(KC_D)     // Tap for D   ; Hold for Control
#define C_K     CTL_T(KC_K)     // Tap for K   ; Hold for Control
#define C_SPC   CTL_T(KC_SPC)   // Tap for SPC ; Hold for Control
#define M_S     ALT_T(KC_S)     // Tap for S   ; Hold for Meta
#define M_L     ALT_T(KC_L)     // Tap for L   ; Hold for Meta
#define SFT_F   SFT_T(KC_F)     // Tap for F   ; Hold for Shift
#define SFT_J   RSFT_T(KC_J)    // Tap for J   ; Hold for Shift
#define S_A     GUI_T(KC_A)     // Tap for A   ; Hold for Super
#define S_SCLN  GUI_T(KC_SCLN)  // Tap for ;   ; Hold for Super
#define RA_Z    ALGR_T(KC_Z)    // Tap for Z   ; Hold for AltGr
#define RA_SLSH ALGR_T(KC_SLSH) // Tap for /   ; Hold for AltGr
#define KC__W   LCA_T(KC_W)     // Tap for w   ; Hold for C-M
#define KC__O   LCA_T(KC_O)     // Tap for o   ; Hold for C-M
#define KC__V   LT(0,KC_V)      // Tap for V   ; Hold for M-x
#define KC__X   LT(0,KC_X)      // Tap for X   ; Hold for C-x
#define KC__C   LT(0,KC_C)      // Tap for C   ; Hold for C-c
#define KC__I   LT(0,KC_I)      // Tap for i   ; Hold for I
#define KC__B   LT(0,KC_B)      // Tap for B   ; Hold for C-x b
#define KC__P   LT(0,KC_P)      // Tap for P   ; Hold for C-x p
#define KC__G   LT(0,KC_G)      // Tap for G   ; Hold for C-x g

#define C_M     LALT(KC_LCTL)

#define SPELL   S(KC_F10)
#define B_TAB   C(KC_TAB)

#define VISIT   HYPR(KC_V)
#define FLASH   HYPR(KC_F)

enum custom_keycodes {
  CX_0 = SAFE_RANGE,
  CX_1,
  CX_2,
  CX_3,
  CX_4,
  CX_P,
  UNDO,
  CUT,
  COPY,
  PASTE,
  REDO
};

/* I'd like to move to 5 columns + pinky */
/* Russian isn't so easy to type on a 5 column layout. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  KC_GRV,  KC_Q,    KC__W,   KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC__I,   KC__O,   KC__P,   KC_LBRC,
  KC_MINS, S_A,     M_S,     C_D,     SFT_F,   KC__G,                     L2_H,    SFT_J,   C_K,     M_L,     S_SCLN,  KC_QUOT,
  KC_EQL,  RA_Z,    KC__X,   KC__C,   KC__V,   KC__B,                     KC_N,    KC_M,    KC_COMM, KC_DOT,  RA_SLSH, KC_RBRC,
                                      KC_LPRN, C_SPC,   L3_TAB,  KC_ENT,  L1_BSPC, L2_DEL
),

  [1] = LAYOUT_split_3x6_3(
  FLASH,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX,                   SPELL,   QK_AREP, QK_REP,  C_M,     KC_ALGR, XXXXXXX,
  KC_ESC,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS,                   QK_LOCK, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, B_TAB,
  VISIT,   UNDO,    CUT,     COPY,    PASTE,   REDO,                      CX_4,    CX_0,    CX_1,    CX_2,    CX_3,    CX_P,
                                      KC_ENT,  _______, KC_TAB,  _______, _______, _______
),

  [2] = LAYOUT_split_3x6_3(
  _______, _______, MS_WHLU, MS_UP,   MS_WHLD, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                                      MS_BTN3, MS_BTN1, MS_BTN2, _______, _______, _______
),

  [3] = LAYOUT_split_3x6_3(
  XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MO(4),                     XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX,
  XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   REDO,                      XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    XXXXXXX
),

  [4] = LAYOUT_split_3x6_3(
  QK_BOOT, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F11,  XXXXXXX,
  CG_TOGG, UNDO,    CUT,     COPY,    PASTE,   REDO,                      XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F12,  XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

  [5] = LAYOUT_split_3x6_3(
  XXXXXXX, KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_BRIU, KC_BRID, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                   XXXXXXX, KC_VOLU, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, UNDO,    CUT,     COPY,    PASTE ,   REDO,                     XXXXXXX, KC_MPRV, KC_MSTP, XXXXXXX, KC_MNXT, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_MPLY, KC_MUTE
),
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {
  case LT(0,KC_X):
    /* Intercept hold function to send C-x. */
    /* On macOS, send Cmd-x since my Emacs setup swaps Ctrl and Cmd. */
    if (!record->tap.count && record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      return false;
    }
    return true;
  case LT(0,KC_C):
    /* Intercept hold function to send C-c. */
    /* On macOS, send Cmd-x since my Emacs setup swaps Ctrl and Cmd. */
    if (!record->tap.count && record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_C)) : tap_code16(C(KC_C));
      return false;
    }
    return true;
  case LT(0,KC_V):
    /* Intercept hold function to send M-x. */
    if (!record->tap.count && record->event.pressed) {
      tap_code16(A(KC_X));
      return false;
    }
    return true;
  case LT(0,KC_I):
    /* Intercept hold function to send I. */
    if (!record->tap.count && record->event.pressed) {
      tap_code16(LSFT(KC_I));
      return false;
    }
    return true;
  case LT(0,KC_B):
    /* Intercept hold function to send C-x b. */
    /* On macOS, send Cmd-x b since my Emacs setup swaps Ctrl and Cmd. */
    if (!record->tap.count && record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_B);
      return false;
    }
    return true;
  case LT(0,KC_P):
    /* Intercept hold function to send C-x p. */
    /* On macOS, send Cmd-x p since my Emacs setup swaps Ctrl and Cmd. */
    if (!record->tap.count && record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_P);
      return false;
    }
    return true;
  case LT(0,KC_G):
    /* Intercept hold function to send C-x g. */
    /* On macOS, send Cmd-x g since my Emacs setup swaps Ctrl and Cmd. */
    if (!record->tap.count && record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_G);
      return false;
    }
    return true;
  case CX_0:
    /* Custom keycode to send C-x 0. */
    /* On macOS, send Cmd-x 0 since my Emacs setup swaps Ctrl and Cmd. */
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_0);
    }
    return false;
  case CX_1:
    /* Custom keycode to send C-x 1. */
    /* On macOS, send Cmd-x 1 since my Emacs setup swaps Ctrl and Cmd. */
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_1);
    }
    return false;
  case CX_2:
    /* Custom keycode to send C-x 2. */
    /* On macOS, send Cmd-x 2 since my Emacs setup swaps Ctrl and Cmd. */
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_2);
    }
    return false;
  case CX_3:
    /* Custom keycode to send C-x 3. */
    /* On macOS, send Cmd-x 3 since my Emacs setup swaps Ctrl and Cmd. */
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_3);
    }
    return false;
  case CX_4:
    /* Custom keycode to send C-x 4. */
    /* On macOS, send Cmd-x 4 since my Emacs setup swaps Ctrl and Cmd. */
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_4);
    }
    return false;
  case CX_P:
    /* Custom keycode to send C-x +. */
    /* On macOS, send Cmd-x + since my Emacs setup swaps Ctrl and Cmd. */
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_PLUS);
    }
    return false;
    /* On macOS keybindings aren't bound by default (e.g. C-x for CUT), but
       they're easily added. This way, these keys will work both for Emacs and
       all other applications on Linux and macOS. */
  case UNDO:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(C(KC_Z)) : tap_code16(KC_UNDO);
    }
    return false;
  case CUT:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(C(KC_X)) : tap_code16(LSFT(KC_DEL));
    }
    return false;
  case COPY:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(C(KC_C)) : tap_code16(C(KC_INS));
    }
    return false;
  case PASTE:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(C(KC_V)) : tap_code16(LSFT(KC_INS));
    }
    return false;
  case REDO:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(C(LSFT(KC_Z))) : tap_code16(KC_AGIN);
    }
    return false;
  }
  return true;
}

/* uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*       /\* Tapping backspace and holding for nav layer happens too often so we */
/*          disable the auto-repeat function *\/ */
/*         case LT(1,KC_BSPC): */
/*             return 0; */
/*         default: */
/*             return QUICK_TAP_TERM; */
/*     } */
/* } */

#ifdef COMBO_ENABLE
enum combos {
  BC,
  PPL,
  THINK
};

/* Horizontal combos (QWERTY) whose combination is rare in English */
/* const uint16_t PROGMEM combo_todo[] = {KC_Q, KC__W, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {RA_Z, KC__X, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {KC__C, KC__V, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {SFT_J, C_K, COMBO_END}; */

/* Vertical combos (QWERTY) whose combination is rare in English */
/* const uint16_t PROGMEM combo_todo[] = {SFT_J, KC_M, COMBO_END}r; */
/* const uint16_t PROGMEM combo_todo[] = {SFT_F, KC__V, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {KC_Q,  S_A, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {KC__X, M_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {KC__G, KC__B, COMBO_END}; */

const uint16_t PROGMEM combo_bc[]    = {KC__B, KC__C, COMBO_END};
const uint16_t PROGMEM combo_ppl[]   = {KC__P, S_SCLN, COMBO_END};
const uint16_t PROGMEM combo_think[] = {KC__I, C_K, COMBO_END};

combo_t key_combos[] = {
  [BC]    = COMBO_ACTION(combo_bc),
  [PPL]   = COMBO_ACTION(combo_ppl),
  [THINK] = COMBO_ACTION(combo_think),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case BC:
    if (pressed) {
      SEND_STRING("because");
    }
    break;
  case PPL:
    if (pressed) {
      SEND_STRING("people");
    }
    break;
  case THINK:
    if (pressed) {
      SEND_STRING("think");
    }
    break;
  }
}
#endif

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
  if (!process_detected_host_os_user(detected_os)) {
    return false;
  }
  switch (detected_os) {
  case OS_MACOS:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
    break;
  case OS_IOS:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
    break;
  case OS_WINDOWS:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
    break;
  case OS_LINUX:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
    break;
  case OS_UNSURE:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
    break;
  }
  return true;
}
#endif
