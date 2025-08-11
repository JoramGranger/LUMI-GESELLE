#ifndef CONFIG_H
#define CONFIG_H

// System Wide Definitions
#define BAUD_RATE 9600
#define DELAY_1 1000
#define DELAY_SHORT 500
#define DELAY_BUTTON_RESPONSE 2000
#define DELAY_DEBOUNCE 50
#define NUM_LEDS 3
#define NUM_BUTTONS 3

// WiFi Configuration
#define WIFI_CONNECT_TIMEOUT 20000  // 20 seconds
#define WIFI_RETRY_DELAY 5000       // 5 seconds

// LED Configuration
extern const int LED_PINS[NUM_LEDS];
extern const char* LED_NAMES[NUM_LEDS];

// Button Configuration  
extern const int BUTTON_PINS[NUM_BUTTONS];
extern const char* BUTTON_NAMES[NUM_BUTTONS];

// Network Configuration
extern const char* WIFI_SSID;
extern const char* WIFI_PASSWORD;
extern const char* API_ENDPOINT;

#endif