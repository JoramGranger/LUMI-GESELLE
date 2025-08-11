#include "api_client.h"

// Initialize static member
HTTPClient APIClient::http;

void APIClient::initialize() {
    Logger::info("API Client initialized");
}

bool APIClient::sendServiceRequest(const String& requestType, int tableNumber) {
    if (!WiFiManager::getConnectionStatus()) {
        Logger::error("Cannot send request - WiFi not connected");
        return false;
    }
    
    Logger::info("Sending " + requestType + " request...");
    
    http.begin(API_ENDPOINT);
    http.addHeader("Content-Type", "application/json");
    
    String payload = createRequestPayload(requestType, tableNumber);
    Logger::debug("Payload: " + payload);
    
    int httpResponseCode = http.POST(payload);
    
    if (httpResponseCode > 0) {
        String response = http.getString();
        Logger::info("Response (" + String(httpResponseCode) + "): " + response);
        http.end();
        return true;
    } else {
        Logger::error("HTTP request failed: " + String(httpResponseCode));
        http.end();
        return false;
    }
}

String APIClient::createRequestPayload(const String& requestType, int tableNumber) {
    StaticJsonDocument<200> doc;
    
    doc["cube_id"] = "cube_001";  // Will make this configurable later
    doc["table_number"] = tableNumber;
    doc["request_type"] = requestType.c_str();
    doc["timestamp"] = millis();
    doc["wifi_signal"] = WiFi.RSSI();
    
    String payload;
    serializeJson(doc, payload);
    return payload;
}