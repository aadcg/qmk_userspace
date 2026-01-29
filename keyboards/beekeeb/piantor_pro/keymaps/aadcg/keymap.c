// SPDX-FileCopyrightText: 2025-2026 André A. Gomes
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// TODO
// Add alpha layer without tap/hold keys (game layer)
// Try AltGr as a one shot modifier
// Bind QK_REP and QK_AREP
// Add Russian alpha layer

// Home row mods
#define D_C     CTL_T(KC_D)     // Tap KC_D ; Hold C
#define K_C     CTL_T(KC_K)     // Tap KC_K ; Hold C
#define S_A     ALT_T(KC_S)     // Tap KC_S ; Hold A
#define L_A     ALT_T(KC_L)     // Tap KC_L ; Hold A
#define A_G     GUI_T(KC_A)     // Tap KC_A ; Hold G
#define SCLN_G  GUI_T(KC_SCLN)  // Tap KC_; ; Hold G
#define F_S     SFT_T(KC_F)     // Tap KC_F ; Hold S
// Right shift due to the caps word feature
#define J_S     RSFT_T(KC_J)    // Tap KC_J ; Hold S
// Additional thumb C-tap
#define SPC_C   CTL_T(KC_SPC)   // Tap SPC  ; Hold C
// AltGr-taps
#define Z_RA    ALGR_T(KC_Z)    // Tap KC_Z ; Hold AltGr
#define SLSH_RA ALGR_T(KC_SLSH) // Tap KC_/ ; Hold AltGr
// Modifier combos
#define W_CA    LCA_T(KC_W)     // Tap KC_W ; Hold CA
#define O_CA    LCA_T(KC_O)     // Tap KC_O ; Hold CA
#define _CA     LALT(KC_LCTL)   // Tap      ; Hold CA

// Layer taps
#define BS_NAV  LT(1,KC_BSPC)   // Tap ⌫   ; Hold Nav layer
#define DEL_RAT LT(2,KC_DEL)    // Tap DEL  ; Hold Rat layer
#define ENT_DE  LT(3,KC_ENT)    // Tap ENT  ; Hold DE  layer
#define TAB_NUM LT(4,KC_TAB)    // Tap TAB  ; Hold Num layer
#define PAR_SYM LT(5,XXXXXXX)   // Tap (    ; Hold Sym layer

// Auto Shift
#define I_SI    LT(0,KC_I)      // Tap KC_I ; Hold S-i

// Emacs utilities
#define V_MX    LT(0,KC_V)      // Tap KC_V ; Hold M-x (execute-extended-command)
#define X_CX    LT(0,KC_X)      // Tap KC_X ; Hold C-x (ctl-x-map)
#define C_CC    LT(0,KC_C)      // Tap KC_C ; Hold C-c (mode-specific map)
#define B_CXB   LT(0,KC_B)      // Tap KC_B ; Hold C-x b (switch-to-buffer)
#define P_CXP   LT(0,KC_P)      // Tap KC_P ; Hold C-x p (project-prefix-map)
#define G_CXG   LT(0,KC_G)      // Tap KC_G ; Hold C-x g (magit-status)
/* Web browser utilities */
#define SPELL   S(KC_F10)       // Spell checking
#define B_TAB   C(KC_TAB)       // Next tab
#define B_BTAB  LCS(KC_TAB)     // Previous tab
/* QMK utilities */
#define VISIT   HYPR(KC_V)
#define FLASH   HYPR(KC_F)

enum custom_keycodes {
  CX_0 = SAFE_RANGE,            // Generalized C-x 0 for Linux/macOS
  CX_1,                         // Generalized C-x 1 for Linux/macOS
  CX_2,                         // Generalized C-x 2 for Linux/macOS
  CX_3,                         // Generalized C-x 3 for Linux/macOS
  CX_4,                         // Generalized C-x 4 for Linux/macOS
  CX_P,                         // Generalized C-x + for Linux/macOS
  UNDO,                         // Generalized UNDO  for Linux/macOS
  CUT,                          // Generalized CUT   for Linux/macOS
  COPY,                         // Generalized COPY  for Linux/macOS
  PASTE,                        // Generalized PASTE for Linux/macOS
  REDO,                         // Generalized REDO  for Linux/macOS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(  // QWERTY layer
  XXXXXXX, KC_Q,    W_CA,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    I_SI,    O_CA,    P_CXP,   XXXXXXX,
  KC_MINS, A_G,     S_A,     D_C,     F_S,     G_CXG,       KC_H,    J_S,     K_C,     L_A,     SCLN_G,  KC_QUOT,
  XXXXXXX, Z_RA,    X_CX,    C_CC,    V_MX,    B_CXB,       KC_N,    KC_M,    KC_COMM, KC_DOT,  SLSH_RA, XXXXXXX,
                             PAR_SYM, SPC_C,   TAB_NUM,     ENT_DE,  BS_NAV,  DEL_RAT
                           ),
  [1] = LAYOUT_split_3x6_3(  // Navigation layer (NAV)
  XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX,     SPELL,   B_BTAB,  B_TAB,   _CA,     KC_ALGR, XXXXXXX,
  KC_ESC,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS,     QK_LOCK, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, CX_P,
  XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   REDO,        CX_4,    CX_0,    CX_1,    CX_2,    CX_3,    XXXXXXX,
                             KC_ENT,  _______, KC_TAB,      XXXXXXX, XXXXXXX, XXXXXXX
                           ),
  [2] = LAYOUT_split_3x6_3(  // Mouse layer (RAT)
  XXXXXXX, _______, MS_WHLU, MS_UP,   MS_WHLD, _______,     _______, _______, _______, _______, _______, XXXXXXX,
  _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,     _______, _______, _______, _______, _______, _______,
  XXXXXXX, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, XXXXXXX,
                             MS_BTN3, MS_BTN1, MS_BTN2,     _______, _______, _______
                           ),
  [3] = LAYOUT_split_3x6_3(  // Desktop layer (DE)
  XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,     _______, _______, _______, _______, _______, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX,     _______, _______, _______, _______, _______, _______,
  XXXXXXX, KC_MPRV, XXXXXXX, XXXXXXX, KC_MNXT, XXXXXXX,     _______, _______, _______, _______, _______, XXXXXXX,
                             KC_MUTE, KC_MPLY, KC_MSTP,     _______, _______, _______
                           ),
  [4] = LAYOUT_split_3x6_3(  // Number layer (NUM)
  XXXXXXX, KC_ALGR, _CA,     B_TAB,   B_BTAB,  SPELL,       XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PEQL, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MO(6),       KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PENT,
  XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   REDO,        KC_PSLS, KC_1,    KC_2,    KC_3,    KC_PAST, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX,     KC_SPC,  KC_0,    KC_BSPC
                           ),
  [5] = LAYOUT_split_3x6_3(  // Symbol layer (SYM)
  XXXXXXX, _______, _______, KC_SLSH, KC_PIPE, KC_BSLS,     KC_GRV,  KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX,
  XXXXXXX, _______, _______, _______, _______, XXXXXXX,     XXXXXXX, KC_LPRN, KC_LCBR, KC_LBRC, KC_EQL,  XXXXXXX,
  XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, XXXXXXX, XXXXXXX,
                             _______, _______, _______,     KC_PLUS, KC_MINS, KC_UNDS
                           ),
  [6] = LAYOUT_split_3x6_3(  // Control layer (CTL)
  XXXXXXX, CG_TOGG, _______, VISIT,   FLASH,   _______,     XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX,
  QK_BOOT, _______, _______, _______, _______, _______,     XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX,
                             _______, _______, _______,     XXXXXXX, XXXXXXX, XXXXXXX
                           ),
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {
  case PAR_SYM:
    if (record->tap.count && record->event.pressed) { // KC_LPRN on tap
      tap_code16(KC_LPRN);
      return false;
    }
    return true;
  case I_SI:
    if (!record->tap.count && record->event.pressed) { // Upcase I on hold
      tap_code16(LSFT(KC_I));
      return false;
    }
    return true;
  case V_MX:
    if (!record->tap.count && record->event.pressed) { // M-x on hold
      tap_code16(A(KC_X));
      return false;
    }
    return true;
  // On macOS, my Emacs setup swaps Ctrl and Cmd.
  case X_CX:
    if (!record->tap.count && record->event.pressed) { // C-x on hold
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      return false;
    }
    return true;
  case C_CC:
    if (!record->tap.count && record->event.pressed) { // C-c on hold
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_C)) : tap_code16(C(KC_C));
      return false;
    }
    return true;
  case B_CXB:
    if (!record->tap.count && record->event.pressed) { // C-x b on hold
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_B);
      return false;
    }
    return true;
  case P_CXP:
    if (!record->tap.count && record->event.pressed) { // C-x p on hold
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_P);
      return false;
    }
    return true;
  case G_CXG:
    if (!record->tap.count && record->event.pressed) { // C-x g on hold
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_G);
      return false;
    }
    return true;
  case CX_0:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_0);
    }
    return false;
  case CX_1:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_1);
    }
    return false;
  case CX_2:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_2);
    }
    return false;
  case CX_3:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_3);
    }
    return false;
  case CX_4:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_4);
    }
    return false;
  case CX_P:
    if (record->event.pressed) {
      (keymap_config.swap_lctl_lgui) ? tap_code16(LCMD(KC_X)) : tap_code16(C(KC_X));
      tap_code16(KC_PLUS);
    }
    return false;
  // These generalize KC_UNDO et al. such that they work on Emacs and other apps
  // on Linux/macOS.
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

/* Horizontal 2-combos whose combination is rare in English (QWERTY) */
/* const uint16_t PROGMEM combo_todo[] = {KC_Q, W_CA, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {Z_RA, X_CX, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {C_CC, V_MX, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {J_S, K_C, COMBO_END}; */

/* Vertical 2-combos whose combination is rare in English (QWERTY) */
/* const uint16_t PROGMEM combo_todo[] = {J_S, KC_M, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {F_S, V_MX, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {KC_Q,  A_G, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {X_CX, A_G, COMBO_END}; */
/* const uint16_t PROGMEM combo_todo[] = {G_CXG, B_CXB, COMBO_END}; */

const uint16_t PROGMEM combo_bc[]    = {B_CXB, C_CC, COMBO_END};
const uint16_t PROGMEM combo_ppl[]   = {P_CXP, SCLN_G, COMBO_END};
const uint16_t PROGMEM combo_think[] = {I_SI, K_C, COMBO_END};

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
