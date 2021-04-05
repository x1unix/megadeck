#ifndef MEGADESK_MDKEYS_H
#define MEGADESK_MDKEYS_H
#include <Arduino.h>

// RobotDyn MDKEY 4x4 MDKEY Definitions.
//
// All MDKEY values are divided by 10 to get exact results.
// Values are tested for Arduino Pro Micro, and will differ on other boards.

typedef int key;

#define MDKEY_EMPTY 0x0
#define MDKEY_1 0x1
#define MDKEY_2 0x2
#define MDKEY_3 0x3
#define MDKEY_4 0x4
#define MDKEY_5 0x5
#define MDKEY_6 0x6
#define MDKEY_7 0x7
#define MDKEY_8 0x8
#define MDKEY_9 0x9
#define MDKEY_10 0xA
#define MDKEY_11 0xB
#define MDKEY_12 0xC
#define MDKEY_13 0xD
#define MDKEY_14 0XE
#define MDKEY_15 0xF
#define MDKEY_16 0x10

// Platform-specific keyboard button voltage values
#ifdef ARDUINO_ARCH_AVR
#define MAX_ANALOG_VALUE 1023

#define RNG_KEY_EMPTY 270 // 26 25 23
#define V_MAX_KEY16 390
#define V_MAX_KEY15 412
#define V_MAX_KEY14 450
#define V_MAX_KEY13 501
#define V_MAX_KEY12 527
#define V_MAX_KEY11 542
#define V_MAX_KEY10 558
#define V_MAX_KEY9 576
#define V_MAX_KEY8 621
#define V_MAX_KEY7 647
#define V_MAX_KEY6 677
#define V_MAX_KEY5 712
#define V_MAX_KEY4 805
#define V_MAX_KEY3 863
#define V_MAX_KEY2 935
#else
#error Unsupported board, please add V_MAX_KEY values to "header/keypad.h"
#endif

key readKey(uint8_t pinNumber);

#endif