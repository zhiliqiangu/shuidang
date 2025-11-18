1. wanwu3/config.h
该文件是配置头文件，主要用于定义键盘的各类功能参数和使能选项，具体包括：
定义 RGB 矩阵的 LED 数量（RGB_MATRIX_LED_COUNT 16）、最大亮度（RGB_MATRIX_MAXIMUM_BRIGHTNESS 255）和动画速度（RGB_MATRIX_SPEED 60）。
启用多种 RGB 矩阵灯光效果，如循环、彩虹、呼吸灯、骑士灯（扫描效果）、按键触发波纹等（通过ENABLE_XXX宏定义）。
启用高级 MIDI 功能（MIDI_ADVANCED）。
2. wanwu3/keymaps/default/keymap.c
该文件是默认按键映射的实现文件，主要定义了键盘的按键布局、编码器功能和 LED 配置：
按键映射：通过keymaps数组定义了两个图层（[0]和[1]）的按键布局，使用LAYOUT宏指定每个位置的按键（如KC_1、KC_A等），其中图层 1 包含重启按键（QK_BOOT）。
编码器功能：在encoder_map中定义了编码器在不同图层的功能（图层 0 控制音量增减，图层 1 无功能）。
LED 配置：通过g_led_config结构体定义了：
轴灯与矩阵位置的对应关系。
每个 LED 的物理坐标位置。
灯的分类信息（均为 4）。
3. wanwu3/keyboard.json
该文件是键盘的硬件描述文件，用于定义键盘的硬件参数和结构信息，供 QMK 固件识别和配置：
基本信息：键盘名称、制造商、维护者等。
USB 信息：VID（厂商 ID）、PID（产品 ID）和设备版本。
矩阵引脚：定义行列引脚（cols和rows）及矩阵尺寸（4 行 4 列）。
编码器配置：指定编码器的引脚（pin_a、pin_b）和分辨率。
处理器与 bootloader：使用STM32F103处理器和stm32duino bootloader。
指示灯：定义 Num Lock、Caps Lock 等指示灯的引脚。
功能使能：启用 RGB 矩阵和编码器功能。
RGB 配置：指定 WS2812 灯的控制引脚（B1）和驱动类型。
布局定义：通过layouts描述每个按键在矩阵中的位置（matrix）和坐标（x、y）
制作过程
2个旋钮一个负责音量，一个负责亮度调节，基础16键盘。
1.在KEYboard Layout Editor网站.调整按钮大小位置和表面的各种数字并导出代码  在kbfirmware.com网站导入代码调整矩阵生成键盘固件修改RGB引脚和数量   在builder.swillkb.com网站导入代码得到16键矩阵的定位板   
2.在做一个开源键盘PCB 图纸上进行一定的修改更换芯片使用篮丸芯片C8T6, 带保险USB接口模块  USB HUB模块  主控芯片模块 键盘矩阵模块 降压电路模块（避免电压不稳定影响BOOTLODER）在犀牛修改定位板，并导入嘉立创。
3.根据QMK官网开源代码，查看官网规则，修改成16键，增加旋钮功能，RGB效果。
4.使用Autodesk Fusion 进行3D打印
