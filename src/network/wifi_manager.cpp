#include "wifi_manager.h"

// Network credentials
const char* WIFI_SSID = "MIA";
const char* WIFI_PASSWORD = "nurburgring-d";
const char* API_ENDPOINT = "http://192.168.1.101:8001/api/requests";  // Update later

// Initialize static members
bool WiFiManager::isConnected = false;
unsigned long WiFiManager::lastReconnectAttempt = 0;

void WiFiManager::initialize() {
    Logger::info("Initializing WiFi...");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

bool WiFiManager::connect() {
    Logger::info("Connecting to WiFi: " + String(WIFI_SSID));
    
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    
    unsigned long startTime = millis();
    while (WiFi.status() != WL_CONNECTED && 
           millis() - startTime < WIFI_CONNECT_TIMEOUT) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    
    if (WiFi.status() == WL_CONNECTED) {
        isConnected = true;
        Logger::info("WiFi connected successfully!");
        printNetworkInfo();
        return true;
    } else {
        isConnected = false;
        Logger::error("WiFi connection failed!");
        return false;
    }
}

void WiFiManager::checkConnection() {
    if (WiFi.status() != WL_CONNECTED && isConnected) {
        isConnected = false;
        Logger::error("WiFi connection lost!");
    }
    
    // Auto-reconnect if disconnected
    if (!isConnected && 
        millis() - lastReconnectAttempt > WIFI_RETRY_DELAY) {
        Logger::info("Attempting WiFi reconnection...");
        lastReconnectAttempt = millis();
        connect();
    }
}

bool WiFiManager::getConnectionStatus() {
    return (WiFi.status() == WL_CONNECTED);
}

String WiFiManager::getLocalIP() {
    if (getConnectionStatus()) {
        return WiFi.localIP().toString();
    }
    return "Not connected";
}

void WiFiManager::printNetworkInfo() {
    Logger::info("Network Information:");
    Logger::info("  SSID: " + String(WIFI_SSID));
    Logger::info("  IP Address: " + getLocalIP());
    Logger::info("  Signal Strength: " + String(WiFi.RSSI()) + " dBm");
    Logger::info("  MAC Address: " + WiFi.macAddress());
}