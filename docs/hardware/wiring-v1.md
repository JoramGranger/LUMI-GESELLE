# Lumi Cube v1.0 - Wiring

## Working Configuration
- ESP32 GPIO16 → LED anode (long leg)
- LED cathode (short leg) → 220Ω resistor → GND
- LED Color: Green (white LEDs don't work - voltage too low)

## Next: Add buttons on GPIO18, 19, 21 with 10kΩ pull-ups