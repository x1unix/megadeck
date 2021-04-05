#include "recovery.h"

bool isRecoveryMode() {
    // Wait untill Serial becomes available, and print recovery message.
    while (!Serial);
    Serial.println("============= ! RECOVERY MODE ! =============");
    Serial.println("Use this mode to reflash the board in case:\n");
    Serial.println("* Board does not respond to commands.");
    Serial.println("* Board's USB device descriptor errors.\n");
    Serial.println("Good luck :)");
    Serial.end();
    return false;
}
