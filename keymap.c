#include "keymap.h"
#include "features/achordion.h"
#include "features/rgb_indicators.h"
#include "keys/combos.h"
#include "keys/key_overrides.h"
#include "keys/mouse_control.h"
#include "leader.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───────────┬───────────┬───────────┬───────────────┬─────────┐                             ┌─────────────────┬─────────────┬───────────┬───────────┬───────────┬──────┐
//    │ S(,) │     q     │     w     │     e     │       r       │    t    │                             │        y        │      u      │     i     │     o     │     p     │ bspc │
//    ├──────┼───────────┼───────────┼───────────┼───────────────┼─────────┤                             ├─────────────────┼─────────────┼───────────┼───────────┼───────────┼──────┤
//    │ f13  │ LCTL_T(a) │ LSFT_T(s) │ LGUI_T(d) │   LALT_T(f)   │    g    │                             │        h        │  RALT_T(j)  │ RGUI_T(k) │ RSFT_T(l) │ RCTL_T(;) │ ent  │
//    ├──────┼───────────┼───────────┼───────────┼───────────────┼─────────┤                             ├─────────────────┼─────────────┼───────────┼───────────┼───────────┼──────┤
//    │  '   │     z     │     x     │     c     │       v       │    b    │                             │        n        │      m      │     -     │     =     │     /     │  no  │
//    └──────┴───────────┴───────────┴───────────┼───────────────┼─────────┼──────────────┐       ┌──────┼─────────────────┼─────────────┼───────────┴───────────┴───────────┴──────┘
//                                               │ QK_REPEAT_KEY │ MO(SYM) │ LT(NAV, spc) │       │ lsft │ LT(MOUSE, bspc) │ LT(FN, del) │
//                                               └───────────────┴─────────┴──────────────┘       └──────┴─────────────────┴─────────────┘
[BASEMOD] = LAYOUT_split_3x6_3(
  S(KC_COMM) , KC_Q         , KC_W         , KC_E         , KC_R          , KC_T    ,                                     KC_Y               , KC_U           , KC_I         , KC_O         , KC_P            , KC_BSPC,
  KC_F13     , LCTL_T(KC_A) , LSFT_T(KC_S) , LGUI_T(KC_D) , LALT_T(KC_F)  , KC_G    ,                                     KC_H               , RALT_T(KC_J)   , RGUI_T(KC_K) , RSFT_T(KC_L) , RCTL_T(KC_SCLN) , KC_ENT ,
  KC_QUOT    , KC_Z         , KC_X         , KC_C         , KC_V          , KC_B    ,                                     KC_N               , KC_M           , KC_MINS      , KC_EQL       , KC_SLSH         , KC_NO  ,
                                                            QK_REPEAT_KEY , MO(SYM) , LT(NAV, KC_SPC) ,         KC_LSFT , LT(MOUSE, KC_BSPC) , LT(FN, KC_DEL)
),

//    ┌──────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                   ┌──────┬──────┬──────┬────┬──────┬─────┐
//    │ S(,) │   esc   │ LCTL(z) │ LCTL(x) │ LCTL(v) │ LCTL(b) │                                   │  1   │  2   │  3   │ 4  │  5   │ no  │
//    ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┤                                   ├──────┼──────┼──────┼────┼──────┼─────┤
//    │ f13  │  lctl   │  lsft   │  lgui   │  lalt   │   no    │                                   │  no  │ left │ down │ up │ rght │ ent │
//    ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┤                                   ├──────┼──────┼──────┼────┼──────┼─────┤
//    │  '   │ LCTL(s) │   no    │   no    │   tab   │   no    │                                   │  6   │  7   │  8   │ 9  │  0   │  /  │
//    └──────┴─────────┴─────────┴─────────┼─────────┼─────────┼──────────────┐       ┌────────────┼──────┼──────┼──────┴────┴──────┴─────┘
//                                         │         │ MO(SYM) │ LT(NAV, spc) │       │ MO(NAVMOD) │ bspc │ del  │
//                                         └─────────┴─────────┴──────────────┘       └────────────┴──────┴──────┘
[NAV] = LAYOUT_split_3x6_3(
  S(KC_COMM) , KC_ESC     , LCTL(KC_Z) , LCTL(KC_X) , LCTL(KC_V) , LCTL(KC_B) ,                                        KC_1    , KC_2    , KC_3    , KC_4  , KC_5     , KC_NO  ,
  KC_F13     , KC_LCTL    , KC_LSFT    , KC_LGUI    , KC_LALT    , KC_NO      ,                                        KC_NO   , KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT , KC_ENT ,
  KC_QUOT    , LCTL(KC_S) , KC_NO      , KC_NO      , KC_TAB     , KC_NO      ,                                        KC_6    , KC_7    , KC_8    , KC_9  , KC_0     , KC_SLSH,
                                                      _______    , MO(SYM)    , LT(NAV, KC_SPC) ,         MO(NAVMOD) , KC_BSPC , KC_DEL
),

//    ┌──────┬────────────┬────────────┬────────────┬────────────┬────────────┐                             ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
//    │ S(,) │    esc     │ S(LCTL(z)) │ S(LCTL(x)) │ S(LCTL(v)) │ S(LCTL(b)) │                             │ LSFT(1) │ LSFT(2) │ LSFT(3) │ LSFT(4) │ LSFT(5) │   no    │
//    ├──────┼────────────┼────────────┼────────────┼────────────┼────────────┤                             ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//    │ f13  │    lctl    │    lsft    │    lgui    │    lalt    │     g      │                             │  S(-)   │  home   │  pgdn   │  pgup   │   end   │ LSFT(4) │
//    ├──────┼────────────┼────────────┼────────────┼────────────┼────────────┤                             ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//    │  '   │ S(LCTL(s)) │     no     │     no     │   S(tab)   │     no     │                             │ LSFT(6) │ LSFT(7) │ LSFT(8) │ LSFT(9) │ LSFT(0) │    /    │
//    └──────┴────────────┴────────────┴────────────┼────────────┼────────────┼──────────────┐       ┌──────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
//                                                  │            │  MO(SYM)   │ LT(NAV, spc) │       │ lsft │  bspc   │   del   │
//                                                  └────────────┴────────────┴──────────────┘       └──────┴─────────┴─────────┘
[NAVMOD] = LAYOUT_split_3x6_3(
  S(KC_COMM) , KC_ESC        , S(LCTL(KC_Z)) , S(LCTL(KC_X)) , S(LCTL(KC_V)) , S(LCTL(KC_B)) ,                                     LSFT(KC_1) , LSFT(KC_2) , LSFT(KC_3) , LSFT(KC_4) , LSFT(KC_5) , KC_NO     ,
  KC_F13     , KC_LCTL       , KC_LSFT       , KC_LGUI       , KC_LALT       , KC_G          ,                                     S(KC_MINS) , KC_HOME    , KC_PGDN    , KC_PGUP    , KC_END     , LSFT(KC_4),
  KC_QUOT    , S(LCTL(KC_S)) , KC_NO         , KC_NO         , S(KC_TAB)     , KC_NO         ,                                     LSFT(KC_6) , LSFT(KC_7) , LSFT(KC_8) , LSFT(KC_9) , LSFT(KC_0) , KC_SLSH   ,
                                                               _______       , MO(SYM)       , LT(NAV, KC_SPC) ,         KC_LSFT , KC_BSPC    , KC_DEL
),

//    ┌──────┬───────────────┬───────────────┬───────────────┬───────────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
//    │ S(,) │      esc      │    LCTL(z)    │    LCTL(x)    │    LCTL(v)    │ LCTL(b) │                    │   no    │  S(0)   │  S(])   │    ]    │  S(.)   │   no    │
//    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//    │ f13  │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │ OSM(MOD_LGUI) │ OSM(MOD_LALT) │   no    │                    │    -    │  S(9)   │  S([)   │    [    │  S(,)   │ LSFT(=) │
//    ├──────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//    │  '   │      no       │      no       │      no       │      tab      │   no    │                    │ LSFT(6) │ LSFT(7) │ LSFT(8) │ LSFT(9) │ LSFT(0) │    /    │
//    └──────┴───────────────┴───────────────┴───────────────┼───────────────┼─────────┼─────┐       ┌──────┼─────────┼─────────┼─────────┴─────────┴─────────┴─────────┘
//                                                           │               │         │     │       │ lsft │  bspc   │   del   │
//                                                           └───────────────┴─────────┴─────┘       └──────┴─────────┴─────────┘
[SYM] = LAYOUT_split_3x6_3(
  S(KC_COMM) , KC_ESC        , LCTL(KC_Z)    , LCTL(KC_X)    , LCTL(KC_V)    , LCTL(KC_B) ,                             KC_NO      , S(KC_0)    , S(KC_RBRC) , KC_RBRC    , S(KC_DOT)  , KC_NO       ,
  KC_F13     , OSM(MOD_LCTL) , OSM(MOD_LSFT) , OSM(MOD_LGUI) , OSM(MOD_LALT) , KC_NO      ,                             KC_MINS    , S(KC_9)    , S(KC_LBRC) , KC_LBRC    , S(KC_COMM) , LSFT(KC_EQL),
  KC_QUOT    , KC_NO         , KC_NO         , KC_NO         , KC_TAB        , KC_NO      ,                             LSFT(KC_6) , LSFT(KC_7) , LSFT(KC_8) , LSFT(KC_9) , LSFT(KC_0) , KC_SLSH     ,
                                                               _______       , _______    , _______ ,         KC_LSFT , KC_BSPC    , KC_DEL
),

//    ┌──────┬──────┬──────┬──────┬─────────┬───────────────────┐                        ┌─────────┬──────────────┬──────────────┬────────────┬───────────────┬─────────┐
//    │ S(,) │ esc  │ btn3 │ btn2 │  btn1   │  MS_GRID_SIZE_UP  │                        │ LSFT(1) │ MS_STEP_LEFT │ MS_STEP_DOWN │ MS_STEP_UP │ MS_STEP_RIGHT │   no    │
//    ├──────┼──────┼──────┼──────┼─────────┼───────────────────┤                        ├─────────┼──────────────┼──────────────┼────────────┼───────────────┼─────────┤
//    │ f13  │ btn2 │ wh_d │ wh_u │  btn1   │ MS_GRID_SIZE_boot │                        │  S(-)   │     ms_l     │     ms_d     │    ms_u    │     ms_r      │ LSFT(4) │
//    ├──────┼──────┼──────┼──────┼─────────┼───────────────────┤                        ├─────────┼──────────────┼──────────────┼────────────┼───────────────┼─────────┤
//    │  '   │  no  │  no  │  no  │   tab   │ MS_GRID_SIZE_DOWN │                        │ LSFT(6) │ MS_GRID_LEFT │ MS_GRID_DOWN │ MS_GRID_UP │ MS_GRID_RIGHT │    /    │
//    └──────┴──────┴──────┴──────┼─────────┼───────────────────┼─────────┐       ┌──────┼─────────┼──────────────┼──────────────┴────────────┴───────────────┴─────────┘
//                                │ MS_ACL0 │      MS_ACL1      │ MS_ACL2 │       │ lsft │  bspc   │     del      │
//                                └─────────┴───────────────────┴─────────┘       └──────┴─────────┴──────────────┘
[MOUSE] = LAYOUT_split_3x6_3(
  S(KC_COMM) , KC_ESC  , KC_BTN3 , KC_BTN2 , KC_BTN1 , MS_GRID_SIZE_UP    ,                             LSFT(KC_1) , MS_STEP_LEFT , MS_STEP_DOWN , MS_STEP_UP , MS_STEP_RIGHT , KC_NO     ,
  KC_F13     , KC_BTN2 , KC_WH_D , KC_WH_U , KC_BTN1 , MS_GRID_SIZE_RESET ,                             S(KC_MINS) , KC_MS_L      , KC_MS_D      , KC_MS_U    , KC_MS_R       , LSFT(KC_4),
  KC_QUOT    , KC_NO   , KC_NO   , KC_NO   , KC_TAB  , MS_GRID_SIZE_DOWN  ,                             LSFT(KC_6) , MS_GRID_LEFT , MS_GRID_DOWN , MS_GRID_UP , MS_GRID_RIGHT , KC_SLSH   ,
                                             MS_ACL0 , MS_ACL1            , MS_ACL2 ,         KC_LSFT , KC_BSPC    , KC_DEL
),

//    ┌──────┬─────────┬─────────┬──────┬─────────┬──────┐                    ┌──────┬─────┬─────┬─────┬─────┬─────┐
//    │ mute │ RGB_VAD │ RGB_VAI │ bRID │  bRIU   │ mnxt │                    │  no  │ f5  │ f6  │ f7  │ f8  │ no  │
//    ├──────┼─────────┼─────────┼──────┼─────────┼──────┤                    ├──────┼─────┼─────┼─────┼─────┼─────┤
//    │ volu │  lctl   │  lsft   │ lgui │  lalt   │ mply │                    │  no  │ f1  │ f2  │ f3  │ f4  │ ent │
//    ├──────┼─────────┼─────────┼──────┼─────────┼──────┤                    ├──────┼─────┼─────┼─────┼─────┼─────┤
//    │ vold │   no    │   no    │  no  │ SGUI(d) │ mprv │                    │  no  │ f9  │ f10 │ f11 │ f12 │ no  │
//    └──────┴─────────┴─────────┴──────┼─────────┼──────┼─────┐       ┌──────┼──────┼─────┼─────┴─────┴─────┴─────┘
//                                      │         │ f16  │ f20 │       │ lsft │ bspc │ del │
//                                      └─────────┴──────┴─────┘       └──────┴──────┴─────┘
[FN] = LAYOUT_split_3x6_3(
  KC_MUTE , RGB_VAD , RGB_VAI , KC_BRID , KC_BRIU    , KC_MNXT ,                            KC_NO   , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_NO ,
  KC_VOLU , KC_LCTL , KC_LSFT , KC_LGUI , KC_LALT    , KC_MPLY ,                            KC_NO   , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_ENT,
  KC_VOLD , KC_NO   , KC_NO   , KC_NO   , SGUI(KC_D) , KC_MPRV ,                            KC_NO   , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO ,
                                          _______    , KC_F16  , KC_F20 ,         KC_LSFT , KC_BSPC , KC_DEL
)
};
// clang-format on

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    // Sequence: HU combo (as leader) then 'r' -> ère
    // Note: Since keyboard is in US QWERTY but OS is in Colemak-DH
    // S in QWERTY = 'R' in Colemak-DH
    if (leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_RALT("s") "ksk"); // ère  On macOS, use SS_LOPT instead of SS_LALT
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // To change tap term per key
    return TAPPING_TERM;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    // Handle mouse-related keycodes
    if (!process_mouse_keycode(keycode, record)) {
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C
