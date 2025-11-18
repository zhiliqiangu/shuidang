#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_A,
        KC_4,    KC_5,    KC_6,    KC_B,
        KC_7,    KC_8,    KC_9,    KC_C,
        KC_D,    KC_E,    KC_F,    MO(1)
    ),
    [1] = LAYOUT(
        QK_BOOT,  _______, _______, _______,
        _______,  _______, _______, _______,
        _______,  _______, _______, _______,
        _______,  _______, _______, MO(1)   
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN) },
    [1] = { ENCODER_CCW_CW(KC_NO, KC_NO) } // Add this line for layer 1
};
#endif
led_config_t g_led_config = { {
  // 轴灯矩阵s
    {      0,  1,  2,      3   }, 
    {      7,  6,  5,      4   }, 
    {      8,  9, 10,     11   }, 
    {     12, 13, 14, NO_LED   }
}, {
  //  所有灯的物理位置
  { 100,  10 }, { 110,  10 }, { 120,  10 }, { 130,  10 },
  { 100,  20 }, { 110,  20 }, { 120,  20 }, { 130,  20 },
  { 100,  30 }, { 110,  30 }, { 120,  30 }, { 130,  30 },
  { 100,  40 }, { 110,  40 }, { 120,  40 }

}, {
  // 灯的分类
  4, 4, 4,4, 
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4 
} };




