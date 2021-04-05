// Define board type (Arduino Pro Micro in my case)
#include "EnableInterrupt.h"
#include "keypad.h"
#include <Arduino.h>
#include <Keyboard.h>

#define KBD_PIN 8
#define RESET_PIN 2

// Predefine functions
void onKeyDown();
void reset();

void setup() {
    Serial.begin(9600);
    pinMode(KBD_PIN, INPUT_PULLUP);
    pinMode(RESET_PIN, INPUT_PULLUP);
    enableInterrupt(KBD_PIN, onKeyDown, CHANGE);
    enableInterrupt(RESET_PIN, reset, CHANGE);
    Keyboard.begin();
}

void loop() {}

void reset() {
    int val = digitalRead(RESET_PIN);
    if (val == HIGH)
        return;
    Keyboard.end();
    disableInterrupt(RESET_PIN | PINCHANGEINTERRUPT);
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
        break;
      default:
        Serial.print("Unknown Key: ");
        Serial.println(keyNumber);
        break;
    }
}
