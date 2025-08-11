#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include "../config/config.h"
#include "../utils/logger.h"

class WiFiManager {
private:
    static bool isConnected;
    static unsigned long lastReconnectAttempt;
    
public:
    static void initialize();
    static bool connect();
    static void checkConnection();
    static bool getConnectionStatus();
    static String getLocalIP();
    static void printNetworkInfo();
};

#endif