#include <Adafruit_NeoPixel.h>

const int buttonPin = 2;
const int ledPin = 4;  
const int numPixels = 64;  

int buttonStatus = HIGH;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;
int walkerPosition = 35;  

float quantumState[numPixels] = {0};  // Probability amplitudes

Adafruit_NeoPixel strip(numPixels, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'
  
  // Initialize walker in superposition
  quantumState[walkerPosition] = 1.0;
  updateLEDs();
}

void loop() {
  int pinValue = digitalRead(buttonPin);

  if (pinValue != buttonStatus && (millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis();
    buttonStatus = pinValue;

    if (buttonStatus == LOW) {  // Button pressed
      quantumWalkStep();
    }
  }
}

void quantumWalkStep() {
  float newQuantumState[numPixels] = {0};

  // Apply Quantum Coin (Hadamard-like transformation)
  for (int i = 0; i < numPixels; i++) {
    if (quantumState[i] > 0) {
      float leftProb = quantumState[i] * 0.707;  // 1/sqrt(2)
      float rightProb = quantumState[i] * 0.707;

      // Interference effect: Each step moves in superposition
      if (i > 0) newQuantumState[i - 1] += leftProb;
      if (i < numPixels - 1) newQuantumState[i + 1] += rightProb;
    }
  }

  // Normalize and update state
  for (int i = 0; i < numPixels; i++) {
    quantumState[i] = newQuantumState[i];
  }

  updateLEDs();
}

void updateLEDs() {
  // Visualize quantum state using LED brightness
  for (int i = 0; i < numPixels; i++) {
    int brightness = int(quantumState[i] * 255);  // Scale probability to brightness
    strip.setPixelColor(i, strip.Color(0, 0, brightness));  // Blue for quantum visualization
  }
  strip.show();
}
