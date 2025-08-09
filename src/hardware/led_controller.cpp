#include "led_controller.h"
#include "../utils/logger.h"

// Define the arrays from config.h
const int LED_PINS[NUM_LEDS] = {16, 17, 5};
const char* LED_NAMES[NUM_LEDS] = {"SERVICE", "BILL", "HELP"};

void LEDController::initialize() {
    Logger::info("Initializing LEDs...");
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LED_PINS[i], OUTPUT);
        digitalWrite(LED_PINS[i], LOW);
    }
    Logger::info("LEDs initialized successfully");
}

void LEDController::control(int ledIndex, bool state) {
    if (ledIndex >= 0 && ledIndex < NUM_LEDS) {
        digitalWrite(LED_PINS[ledIndex], state);
    }
}

void LEDController::controlAll(bool state) {
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LED_PINS[i], state);
    }
}

void LEDController::blink(int ledIndex, int duration) {
    control(ledIndex, HIGH);
    delay(duration);
    control(ledIndex, LOW);
}

void LEDController::testAll() {
    Logger::info("Testing all LEDs...");
    controlAll(HIGH);
    delay(DELAY_1);
    controlAll(LOW);
    delay(DELAY_SHORT);
    Logger::info("LED test complete");
}