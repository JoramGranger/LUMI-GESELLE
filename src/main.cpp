#include <Arduino.h>
#include "config/config.h"
#include "utils/logger.h"
#include "hardware/led_controller.h"
#include "hardware/button_handler.h"

void setup() {
    Logger::initialize();
    
    LEDController::initialize();
    ButtonHandler::initialize();
    
    LEDController::testAll();
    Logger::info("Press buttons to test functionality!");
}

void loop() {
    ButtonHandler::checkAll();
    delay(DELAY_DEBOUNCE);
}