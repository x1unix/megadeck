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
    ASSERT_RECOVERY();

    pinMode(KBD_PIN, INPUT_PULLUP);
    enableInterrupt(KBD_PIN, onKeyDown, CHANGE);
    
    // Enable generic keyboard interface
    Keyboard.begin();

    // Consumer for media keys.
    // See: https://github.com/NicoHood/HID/wiki/Consumer-API
    Consumer.begin();
}

void loop() {}

void onKeyDown() {
    key keyNumber = readKey(KBD_PIN);
    if (keyNumber == MDKEY_LOW) {
        return;
    }

    // Define your keys here
    switch (keyNumber) {
      case MDKEY_1:
        Keyboard.add(KEY_LEFT_SHIFT);
        Keyboard.add(KEY_LEFT_ALT);
        Keyboard.send();
        Keyboard.releaseAll();
        break;
      case MDKEY_2:
        Keyboard.println("Hello World yobta!");
        break;
      case MDKEY_3:
        Consumer.write(MEDIA_PLAY_PAUSE);
        break;
      case MDKEY_8:
        Consumer.write(MEDIA_VOL_DOWN);
        break;
      case MDKEY_4:
        Consumer.write(MEDIA_VOLUME_UP);
        break;
      case MDKEY_12:
        Consumer.write(MEDIA_PREV);
        break;
      case MDKEY_16:
        Consumer.write(MEDIA_NEXT);
        break;
      default:
        Serial.print("Unknown Key: ");
        Serial.println(keyNumber);
        break;
    }
}
