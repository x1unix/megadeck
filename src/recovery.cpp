#include "recovery.h"

bool isRecoveryMode() {
    // Check if recovery pin is closed.
    pinMode(RECOVERY_PIN, INPUT_PULLUP);
    int val = digitalRead(RECOVERY_PIN);
    if (val == HIGH)
        return false;

    // Wait until Serial becomes available, and print recovery message.
    while (!Serial);
    Serial.println("============= ! RECOVERY MODE ! =============");
    Serial.println("Use this mode to reflash the board in case:\n");
    Serial.println("* Board does not respond to commands.");
    Serial.println("* Board's USB device descriptor errors.\n");
    Serial.println("Good luck :)");
    return true;
}
