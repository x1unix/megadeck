#include "keypad.h"
#include <Arduino.h>


key readKey(uint8_t pinNumber) {
    int analogValue = analogRead(pinNumber);
#ifdef MAX_ANALOG_VALUE
    analogValue = (int)map(analogValue, 0, MAX_ANALOG_VALUE, 0, 1023);
#endif
    if (analogValue < MDKEY_LOW) {
        return MDKEY_LOW;
    }

    // Floor number to map closer values
    float floored = floor((float)analogValue / 10);
    key keyNumber = (key) floored;
    return keyNumber;
}
