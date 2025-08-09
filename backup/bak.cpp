#include <Arduino.h>

// Pin definitions
#define LED_PIN 16

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Configure LED pin as output
  pinMode(LED_PIN, OUTPUT);
  
  // Startup message
  Serial.println("LED Test Starting...");
}

void loop() {
  // Turn LED on
  Serial.println("LED ON");
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  
  // Turn LED off
  Serial.println("LED OFF");
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}