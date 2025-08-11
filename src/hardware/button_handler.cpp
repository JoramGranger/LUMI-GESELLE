#include "button_handler.h"
#include "led_controller.h"
#include "../utils/logger.h"
#include "../network/api_client.h"

// Define the arrays from config.h
const int BUTTON_PINS[NUM_BUTTONS] = {18, 19, 21};
const char* BUTTON_NAMES[NUM_BUTTONS] = {"SERVICE", "BILL", "MENU"};

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
        String requestType = String(BUTTON_NAMES[buttonIndex]);
        Logger::info(requestType + " request activated!");
        
        // Light LED to show processing
        LEDController::control(buttonIndex, HIGH);
        
        // Send API request
        bool success = APIClient::sendServiceRequest(requestType);
        
        if (success) {
            Logger::info(requestType + " request sent successfully!");
        } else {
            Logger::error(requestType + " request failed!");
        }
        
        // Keep LED on for visual feedback
        delay(DELAY_BUTTON_RESPONSE);
        LEDController::control(buttonIndex, LOW);
    }
}