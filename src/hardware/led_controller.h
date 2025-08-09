#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>
#include "../config/config.h"

class LEDController {
public:
    static void initialize();
    static void control(int ledIndex, bool state);
    static void controlAll(bool state);
    static void blink(int ledIndex, int duration);
    static void testAll();
};

#endif