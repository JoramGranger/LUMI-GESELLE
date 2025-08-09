#include <Arduino.h>

// System Wide Definitions
#define BAUD_RATE 9600
#define DELAY_1 1000
#define DELAY_SHORT 500
#define NUM_LEDS 3

// LED Configuration
const int LED_PINS[NUM_LEDS] = {16, 17, 5};
const char* LED_NAMES[NUM_LEDS] = {"SERVICE", "BILL", "HELP"};

// Function declarations
void initializeLEDs();
void controlLED(int ledIndex, bool state);
void controlAllLEDs(bool state);
void testLEDSequence();
void testAllLEDsTogether();
void blinkLED(int ledIndex, int duration);

void setup() {
  Serial.begin(BAUD_RATE);
  initializeLEDs();
  Serial.println("=== Lumi Cube LED Test ===");
}

void loop() {
  testLEDSequence();
  testAllLEDsTogether();
  delay(DELAY_1);
}

// Initialize all LED pins
void initializeLEDs() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW); // Ensure all start OFF
  }
}

// Control individual LED by index
void controlLED(int ledIndex, bool state) {
  if (ledIndex >= 0 && ledIndex < NUM_LEDS) {
    digitalWrite(LED_PINS[ledIndex], state);
  }
}

// Control all LEDs at once
void controlAllLEDs(bool state) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], state);
  }
}

// Blink specific LED for duration
void blinkLED(int ledIndex, int duration) {
  controlLED(ledIndex, HIGH);
  delay(duration);
  controlLED(ledIndex, LOW);
}

// Test LEDs in sequence
void testLEDSequence() {
  Serial.println("Testing LEDs in sequence...");
  
  for (int i = 0; i < NUM_LEDS; i++) {
    Serial.println(LED_NAMES[i]);
    blinkLED(i, DELAY_SHORT);
    delay(DELAY_SHORT);
  }
}

// Test all LEDs together
void testAllLEDsTogether() {
  Serial.println("All LEDs ON");
  controlAllLEDs(HIGH);
  delay(DELAY_1);
  
  Serial.println("All LEDs OFF");
  controlAllLEDs(LOW);
  delay(DELAY_SHORT);
}