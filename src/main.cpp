#include <Arduino.h>

// System Wide Definitions
#define BAUD_RATE 9600
#define DELAY_1 1000
#define DELAY_SHORT 500
#define DELAY_BUTTON_RESPONSE 2000
#define DELAY_DEBOUNCE 50
#define NUM_LEDS 3
#define NUM_BUTTONS 3

// LED Configuration
const int LED_PINS[NUM_LEDS] = {16, 17, 5};
const char* LED_NAMES[NUM_LEDS] = {"SERVICE", "BILL", "MENU"};

// Button Configuration
const int BUTTON_PINS[NUM_BUTTONS] = {18, 19, 21};
const char* BUTTON_NAMES[NUM_BUTTONS] = {"SERVICE", "BILL", "MENU"};

// Button state tracking
bool lastButtonStates[NUM_BUTTONS] = {HIGH, HIGH, HIGH};

// Function declarations
void initializeLEDs();
void initializeButtons();
void controlLED(int ledIndex, bool state);
void controlAllLEDs(bool state);
void blinkLED(int ledIndex, int duration);
void testLEDSequence();
void testAllLEDsTogether();
void checkButtons();
void handleButtonPress(int buttonIndex);

void setup() {
  Serial.begin(BAUD_RATE);
  initializeLEDs();
  initializeButtons();
  
  Serial.println("=== Lumi Cube Complete Test ===");
  testAllLEDsTogether(); // Quick LED test on startup
  Serial.println("Press buttons to test functionality!");
}

void loop() {
  checkButtons();
  delay(DELAY_DEBOUNCE);
}

// Initialize all LED pins
void initializeLEDs() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
}

// Initialize all button pins
void initializeButtons() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
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

// Test all LEDs together (startup test)
void testAllLEDsTogether() {
  Serial.println("Testing all LEDs...");
  controlAllLEDs(HIGH);
  delay(DELAY_1);
  controlAllLEDs(LOW);
  delay(DELAY_SHORT);
}

// Check all buttons for presses
void checkButtons() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    bool currentState = digitalRead(BUTTON_PINS[i]);
    
    // Button pressed (HIGH to LOW transition with pullup)
    if (lastButtonStates[i] == HIGH && currentState == LOW) {
      handleButtonPress(i);
    }
    
    lastButtonStates[i] = currentState;
  }
}

// Handle individual button press
void handleButtonPress(int buttonIndex) {
  if (buttonIndex >= 0 && buttonIndex < NUM_BUTTONS) {
    Serial.print(BUTTON_NAMES[buttonIndex]);
    Serial.println(" request activated!");
    
    // Light corresponding LED for response time
    controlLED(buttonIndex, HIGH);
    delay(DELAY_BUTTON_RESPONSE);
    controlLED(buttonIndex, LOW);
    
    Serial.print(BUTTON_NAMES[buttonIndex]);
    Serial.println(" request completed!");
  }
}