#ifndef RECOVERY_H
#define RECOVERY_H

#include <Arduino.h>
#define RECOVERY_PIN 2

#define ASSERT_RECOVERY() if (isRecoveryMode()) return; 
bool isRecoveryMode();

#endif