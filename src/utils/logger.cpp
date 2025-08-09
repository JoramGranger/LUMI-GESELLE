#include "logger.h"

void Logger::initialize() {
    Serial.begin(BAUD_RATE);
    delay(1000);
    info("=== Lumi Cube System Starting ===");
}

void Logger::info(const String& message) {
    Serial.print("[INFO] ");
    Serial.println(message);
}

void Logger::error(const String& message) {
    Serial.print("[ERROR] ");
    Serial.println(message);
}

void Logger::debug(const String& message) {
    Serial.print("[DEBUG] ");
    Serial.println(message);
}