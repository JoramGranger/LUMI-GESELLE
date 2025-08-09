#include <Arduino.h>

// System Wide Definitions
#define BAUD_RATE 9600
#define DELAY_1 1000
#define DELAY_SHORT 500

// LED Pin Definitions
#define LED_SERVICE_PIN 16
#define LED_BILL_PIN 17
#define LED_HELP_PIN 5

// Function declarations
void testLEDSequence();
void testAllLEDsTogether();

void setup() {
  // Initialize serial communication
  Serial.begin(BAUD_RATE);
  
  // Configure LED pins as output
  pinMode(LED_SERVICE_PIN, OUTPUT);
  pinMode(LED_BILL_PIN, OUTPUT);
  pinMode(LED_HELP_PIN, OUTPUT);
  
  // Startup message
  Serial.println("=== Lumi Cube LED Test ===");
}

void loop() {
  // Test all LEDs in sequence
  testLEDSequence();
  
  // Test all LEDs together
  testAllLEDsTogether();
  
  // Wait before repeating
  delay(DELAY_1);
}

void testLEDSequence() {
  Serial.println("Testing LEDs in sequence...");
  
  // Service LED
  Serial.println("SERVICE LED");
  digitalWrite(LED_SERVICE_PIN, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(LED_SERVICE_PIN, LOW);
  delay(DELAY_SHORT);
  
  // Bill LED
  Serial.println("BILL LED");
  digitalWrite(LED_BILL_PIN, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(LED_BILL_PIN, LOW);
  delay(DELAY_SHORT);
  
  // Help LED
  Serial.println("HELP LED");
  digitalWrite(LED_HELP_PIN, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(LED_HELP_PIN, LOW);
  delay(DELAY_SHORT);
}

void testAllLEDsTogether() {
  Serial.println("All LEDs ON");
  digitalWrite(LED_SERVICE_PIN, HIGH);
  digitalWrite(LED_BILL_PIN, HIGH);
  digitalWrite(LED_HELP_PIN, HIGH);
  delay(DELAY_1);
  
  Serial.println("All LEDs OFF");
  digitalWrite(LED_SERVICE_PIN, LOW);
  digitalWrite(LED_BILL_PIN, LOW);
  digitalWrite(LED_HELP_PIN, LOW);
  delay(DELAY_SHORT);
}