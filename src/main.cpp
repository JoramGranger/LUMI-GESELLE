#include <Arduino.h>
#include "config/config.h"
#include "utils/logger.h"
#include "hardware/led_controller.h"
#include "hardware/button_handler.h"
#include "network/wifi_manager.h"
#include "network/api_client.h"

void setup() {
    Logger::initialize();
    
    // Initialize hardware
    LEDController::initialize();
    ButtonHandler::initialize();
    
    // Initialize network
    WiFiManager::initialize();
    APIClient::initialize();
    
    // Test hardware
    LEDController::testAll();
    
    // Connect to WiFi
    if (WiFiManager::connect()) {
        Logger::info("Lumi Cube ready! Press buttons to send requests.");
    } else {
        Logger::error("System starting without network connectivity.");
    }
}

void loop() {
    // Check network connection
    WiFiManager::checkConnection();
    
    // Handle button presses
    ButtonHandler::checkAll();
    
    delay(DELAY_DEBOUNCE);
}