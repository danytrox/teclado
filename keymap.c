#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

/* THIS FILE WAS GENERATED & CUSTOMIZED WITH OLED BITMAP! */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NUHS, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_ENT, MO(2), KC_SPC, MO(3)),
    [1] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TAB, KC_GRV, KC_UNDS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12, KC_CAPS, KC_NUBS, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_NO, KC_NO, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS),
    [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_UP, KC_9, KC_MPRV, KC_VOLU, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_MUTE, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_MNXT, KC_VOLD, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


#ifdef OLED_ENABLE
// Tu bitmap de 16x16px listo para QMK
static const char PROGMEM icono_danery[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xe7, 0xf7, 0xcf, 0xf7, 0xe7, 0xf3, 0xe7, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // --- CÓDIGO PARA LA MITAD PRINCIPAL (IZQUIERDA O DERECHA CON USB) ---
        oled_write_ln_P(PSTR("LILY58 - DANERY"), false);

        // Mostrar la capa activa según tus índices del JSON
        oled_write_P(PSTR("Capa: "), false);
        switch (get_highest_layer(layer_state)) {
            case 0: oled_write_ln_P(PSTR("Default"), false); break;
            case 1: oled_write_ln_P(PSTR("Numeros"), false); break;
            case 2: oled_write_ln_P(PSTR("Simbolos"), false); break;
            case 3: oled_write_ln_P(PSTR("Capa 3"), false); break;
            default: oled_write_ln_P(PSTR("Desconocida"), false);
        }

        // Mostrar estado de Bloq Mayús
        led_t led_state = host_keyboard_led_state();
        oled_write_ln_P(led_state.caps_lock ? PSTR("CAPS: [ON]") : PSTR("CAPS: OFF"), false);

    } else {
        // --- CÓDIGO PARA LA MITAD SECUNDARIA (ESCLAVA) ---
        oled_write_ln_P(PSTR("  MI LILY58  "), false);
        oled_write_ln_P(PSTR("-------------"), false);

        // Colocamos el cursor abajo de las líneas de texto anteriores
        oled_set_cursor(5, 3);

        // Dibujamos tus 32 bytes del icono
        oled_write_raw_P(icono_danery, 32);

        oled_set_cursor(0, 6);
        oled_write_ln_P(PSTR(" QMK Firmware"), false);
    }
    return false;
}
#endif
