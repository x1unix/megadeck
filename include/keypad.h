#ifndef MEGADESK_MDKEYS_H
#define MEGADESK_MDKEYS_H
#include <Arduino.h>

// RobotDyn MDKEY 4x4 MDKEY Definitions.
//
// All MDKEY values are divided by 10 to get exact results.
// Values are tested for Arduino Pro Micro, and will differ on other boards.

/////////////////////////////
// Arduino Pro Micro values.
/////////////////////////////
typedef int key;

#define MAX_ANALOG_VALUE 1023
#define MDKEY_LOW 250
#define MDKEY_1 102
#define MDKEY_2 93
#define MDKEY_3 86
#define MDKEY_4 80
#define MDKEY_5 71
#define MDKEY_6 67
#define MDKEY_7 64
#define MDKEY_8 62
#define MDKEY_9 57
#define MDKEY_10 55
#define MDKEY_11 54
#define MDKEY_12 52
#define MDKEY_13 49
#define MDKEY_14 44
#define MDKEY_15 40
#define MDKEY_16 38

key readKey(uint8_t pinNumber);

#endif