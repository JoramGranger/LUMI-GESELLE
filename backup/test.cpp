#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("HELLO FROM ESP32!");
}

void loop() {
  Serial.println("I'm alive!");
  delay(2000);
}