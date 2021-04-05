#include "keypad.h"
#include <Arduino.h>


key readKey(uint8_t pinNumber) {
    int value = analogRead(pinNumber);
#ifdef MAX_ANALOG_VALUE
    value = (int)map(value, 0, MAX_ANALOG_VALUE, 0, 1023);
#endif
    if (value < RNG_KEY_EMPTY) {
        return MDKEY_EMPTY;
    }

    if (value < V_MAX_KEY16) return MDKEY_16;
    if (value < V_MAX_KEY15) return MDKEY_15;
    if (value < V_MAX_KEY14) return MDKEY_14;
    if (value < V_MAX_KEY13) return MDKEY_13;
    if (value < V_MAX_KEY12) return MDKEY_12;
    if (value < V_MAX_KEY11) return MDKEY_11;
    if (value < V_MAX_KEY10) return MDKEY_10;
    if (value < V_MAX_KEY9) return MDKEY_9;
    if (value < V_MAX_KEY8) return MDKEY_8;
    if (value < V_MAX_KEY7) return MDKEY_7;
    if (value < V_MAX_KEY6) return MDKEY_6;
    if (value < V_MAX_KEY5) return MDKEY_5;
    if (value < V_MAX_KEY4) return MDKEY_4;
    if (value < V_MAX_KEY3) return MDKEY_3;
    if (value < V_MAX_KEY2) return MDKEY_2;

    return MDKEY_1;
}
