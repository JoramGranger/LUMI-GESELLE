#ifndef API_CLIENT_H
#define API_CLIENT_H

#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "wifi_manager.h"
#include "../utils/logger.h"

class APIClient {
private:
    static HTTPClient http;
    
public:
    static void initialize();
    static bool sendServiceRequest(const String& requestType, int tableNumber = 1);
    static String createRequestPayload(const String& requestType, int tableNumber);
};

#endif