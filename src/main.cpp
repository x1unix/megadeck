// Define board type (Arduino Pro Micro in my case)
#include <Arduino.h>
#include "EnableInterrupt.h"
#include "HID-Project.h"
#include "keypad.h"
#include "recovery.h"

#define KBD_PIN 8

// Predefine functions
bool isRecoveryMode();
void onKeyDown();
void reset();

void setup() {
    Serial.begin(9600);
    pinMode(KBD_PIN, INPUT_PULLUP);
    ASSERT_RECOVERY();
    while (!Serial);
    Serial.println("Not in recovery!");
    return;
    enableInterrupt(KBD_PIN, onKeyDown, CHANGE);
    enableInterrupt(RECOVERY_PIN, reset, CHANGE);
    Keyboard.begin();
}

void loop() {}

void reset() {
    int val = digitalRead(RECOVERY_PIN);
    if (val == HIGH)
        return;
    Keyboard.end();
    disableInterrupt(RECOVERY_PIN | PINCHANGEINTERRUPT);
    disableInterrupt(KBD_PIN | PINCHANGEINTERRUPT);
    Serial.println("Keyboard detach");
}

void onKeyDown() {
    key keyNumber = readKey(KBD_PIN);
    if (keyNumber == MDKEY_LOW) {
        return;
    }

    switch (keyNumber) {
      case MDKEY_1:
        Keyboard.print("test");
        break;
      case MDKEY_2:
        Keyboard.press(MEDIA_PLAY_PAUSE);
        break;
      default:
        Serial.print("Unknown Key: ");
        Serial.println(keyNumber);
        break;
    }
}
