# open_diet_2025
Simulating Classical and Quantum Walks with an Arduino-Based LED System

## Equipment
To carry out this project we need:
- [Arduino Uno R3](https://docs.arduino.cc/hardware/uno-rev3/)
- LED strip (WS2812B, e.g. the [BTF-LIGHTING DC5V WS2812B ECO RGB](https://www.amazon.it/BTF-LIGHTING-indirizzabili-individualmente-flessibile-controller/dp/B088W62171?th=1), not included in the Arduino Uno R3 Kit)
- USB Cable (included in the Arduino Uno R3 Kit)

**Remark 1.** If the LED strip is too big (e.g. >100 LEDs, depending on the power consumption of each LED) you will also need:
- Resistor (e.g. 220Ω, included in the Arduino Uno R3 Kit)
- Breadboard & jumper wires (included in the Arduino Uno R3 Kit)
- Power Supply Module (included in the Arduino Uno R3 Kit)
- 9V1A Adapter (included in the Arduino Uno R3 Kit)
  
## Wiring
Connect the LED strip to Arduino. In particular: 5V to 5V, GND to GND and dataling (DIN) top Pin 4.

**Remark 2.** In the case of Remark 1 you will need to:
- Connect the Power Supply Module to the Breadboard
- Connect the LED strip to the Power Supply Module via the Breadboard
- Connect the LED strip also to the Arduino.

