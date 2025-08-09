#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include <Arduino.h>
#include "../config/config.h"

class ButtonHandler {
private:
    static bool lastStates[NUM_BUTTONS];
    
public:
    static void initialize();
    static void checkAll();
    static void handlePress(int buttonIndex);
};

#endif