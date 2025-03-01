# open_diet_2025
Simulating Classical and Quantum Walks with an Arduino-Based LED System, a project for the event [Open DIET 2025](https://diet.web.uniroma1.it/en/node/6883).

## Equipment
To carry out this project we need:
- [Arduino Uno R3](https://docs.arduino.cc/hardware/uno-rev3/);
- LED strip (WS2812B, e.g. the [BTF-LIGHTING DC5V WS2812B ECO RGB](https://www.amazon.it/BTF-LIGHTING-indirizzabili-individualmente-flessibile-controller/dp/B088W62171?th=1) i used, not included in the Arduino Uno R3 Kit);
- USB Cable (included in the Arduino Uno R3 Kit) to power the system;
- Breadboard (included in the Arduino Uno R3 Kit) to smoothly connect the Arduino UNO R3 to the LED strip;
- Resistor (included in the Arduino Uno R3 Kit), say of 10K$\Omega$;
- Button (included in the Arduino Uno R3 Kit);
- Jumper wires (included in the Arduino Uno R3 Kit).

## Connection scheme
We need to connect the Arduino to a laptop with the USB cable in order to execute custom programs and also to power te system, then connect Arduino to the LED strip via the Breadbord where the button is placed in order to turn on and of the LEDs. The connection scheme is shown below.
- Connect the positive side of the Breadboard to 5V of Arduino;
- Connect the negative side of the Breadboard to GND (ground) of Arduino;
- Connect the LED power (5V) to the positive side of the Breadboard;
- Connect the ground (GND) of the LED strip to the negative side of the Breadboard;
- Connect the Datalink (DIN) of the LED strip to PIN 4 of Arduino;
- Connect PIN 2 of Arduino to the bottom leg of the button as shown in the figure below;
- Between the jumper wire connecting Arduino to the button put the resistor (one side connected to the negative side of the breadboard and the other side near the button bottom leg);
- Add a jumper wire connecting the positive side of the Breadboard to the top leg of the button as shown in the following figure. 

![connection](https://github.com/user-attachments/assets/2cd61f13-c3a3-41b6-9de1-b1fee31432be)

**Remark.** In some cases the power Arduino can give to the LED strip is not enough. In that case you can connect the LED strip directly to an external power source via the extra 5V and GND wires. 

## Connection testing.

To test the connection you can execute the Arduino script in the folder 

