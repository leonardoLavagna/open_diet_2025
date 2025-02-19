# open_diet_2025
Simulating Classical and Quantum Walks with an Arduino-Based LED System

## Equipment
To carry out this project we need:
- [Arduino Uno R3](https://docs.arduino.cc/hardware/uno-rev3/)
- LED strip (WS2812B, e.g. the [BTF-LIGHTING DC5V WS2812B ECO RGB](https://www.amazon.it/BTF-LIGHTING-indirizzabili-individualmente-flessibile-controller/dp/B088W62171?th=1), not included in the Arduino Uno R3 Kit)
- Resistor (e.g. 220Ω, included in the Arduino Uno R3 Kit)
- Breadboard & jumper wires (included in the Arduino Uno R3 Kit)
- Power Supply Module (included in the Arduino Uno R3 Kit)
- 9V1A Adapter (included in the Arduino Uno R3 Kit)
- USB Cable (included in the Arduino Uno R3 Kit)
  
## Wiring
Connect the Led strip to an external power supply, then connect it to Arduino (datalink only). In particular:
- Connect the Power Supply Module to the Breadboard (direct connection)
- Connect the LED strip to the Power Supply Moduel via the Breadboard: 5V to the + side and GND to the - side
- Connect the LED strip also to the Arduino: DIN to the Breadboard (far away from the LED-to-Power Supply connection) followed by the Resistor then a connection to Arduino Pin 4
Check the connections then power everithing up (9V1A Adapter for the Power Supply Module connected to a plug and the USB Cable connected to a computer).

