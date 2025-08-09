#include "button_handler.h"
#include "led_controller.h"
#include "../utils/logger.h"

// Define the arrays from config.h
const int BUTTON_PINS[NUM_BUTTONS] = {18, 19, 21};
const char* BUTTON_NAMES[NUM_BUTTONS] = {"SERVICE", "BILL", "HELP"};

// Initialize static member
bool ButtonHandler::lastStates[NUM_BUTTONS] = {HIGH, HIGH, HIGH};

void ButtonHandler::initialize() {
    Logger::info("Initializing buttons...");
    for (int i = 0; i < NUM_BUTTONS; i++) {
        pinMode(BUTTON_PINS[i], INPUT_PULLUP);
    }
    Logger::info("Buttons initialized successfully");
}

void ButtonHandler::checkAll() {
    for (int i = 0; i < NUM_BUTTONS; i++) {
        bool currentState = digitalRead(BUTTON_PINS[i]);
        
        if (lastStates[i] == HIGH && currentState == LOW) {
            handlePress(i);
        }
        
        lastStates[i] = currentState;
    }
}

void ButtonHandler::handlePress(int buttonIndex) {
    if (buttonIndex >= 0 && buttonIndex < NUM_BUTTONS) {
        Logger::info(String(BUTTON_NAMES[buttonIndex]) + " request activated!");
        
        LEDController::control(buttonIndex, HIGH);
        delay(DELAY_BUTTON_RESPONSE);
        LEDController::control(buttonIndex, LOW);
        
        Logger::info(String(BUTTON_NAMES[buttonIndex]) + " request completed!");
    }
}