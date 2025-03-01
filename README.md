# open_diet_2025
Simulating Classical and Quantum Walks with an Arduino-Based LED System: a project for the event [Open DIET 2025](https://diet.web.uniroma1.it/en/node/6883).

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

## Project execution.
We want to show the difference between a classical [random walk](https://en.wikipedia.org/wiki/Random_walk) and a (simulation of a) [quantum walk](https://en.wikipedia.org/wiki/Quantum_walk) on the LED strip. We have two folders:
- `random_walk` containing the Arduino script `random_walk.ino` which implements a uniform symmetric random walk. Each LED represents the position of the walker. Pushing the button allows the walker to change position (with probability 1/2 he will go right and with probability 1/2 he will go left respecting the boundary conditions prescribed by the LED strip topology).
- `quantum_walk` containing the Arduino script `quantum_walk.ino`. In this case each LED represents the position of the walker, before a [measurement process](https://en.wikipedia.org/wiki/Measurement_in_quantum_mechanics) (remember the [Schrödinger's cat](https://en.wikipedia.org/wiki/Schr%C3%B6dinger%27s_cat)?). The brightness of each LED is proportional to the square of the modulus of the [amplitude](https://en.wikipedia.org/wiki/Probability_amplitude) of the [superposition state](https://en.wikipedia.org/wiki/Quantum_superposition) associated to the walker position. In this setting the probability of moving from one point to another is defined in terms of the [Hadamard matrix](https://en.wikipedia.org/wiki/Hadamard_matrix) (which is the quantum equivalent of a [Bernoulli random variable](https://en.wikipedia.org/wiki/Bernoulli_distribution)).

To execute the project on our laptop you need to download the [Arduino IDE](https://www.arduino.cc/en/software). If you don't have an Arduino kit you can always try some of the many online simulators e.g. [this one](https://wokwi.com/).

