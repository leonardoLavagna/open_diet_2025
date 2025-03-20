#include <Adafruit_NeoPixel.h>

const int buttonPin = 2;
const int ledPin = 4;
const int numPixels = 64;

int buttonStatus = HIGH;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;
int walkerPosition = 35;
bool measured = false;  // Track if measurement has occurred

struct ComplexNumber {
  float real;
  float imag;
};

// Quantum state: each position holds a complex amplitude
ComplexNumber quantumState[numPixels] = { {0, 0} };
Adafruit_NeoPixel strip(numPixels, ledPin, NEO_GRB + NEO_KHZ800);

// Function to compute the magnitude squared of a complex number
float complexMagnitudeSquared(ComplexNumber c) {
  return c.real * c.real + c.imag * c.imag;
}

// Function to multiply a complex number by a scalar
ComplexNumber complexMultiply(ComplexNumber c, float scalar) {
  return { c.real * scalar, c.imag * scalar };
}

// Function to add two complex numbers
ComplexNumber complexAdd(ComplexNumber a, ComplexNumber b) {
  return { a.real + b.real, a.imag + b.imag };
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  strip.begin();
  strip.show();

  // Initialize walker in superposition
  quantumState[walkerPosition] = { 1.0, 0.0 };
  updateLEDs();
}

void loop() {
  int pinValue = digitalRead(buttonPin);

  if (pinValue != buttonStatus && (millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis();
    buttonStatus = pinValue;

    if (buttonStatus == LOW) {  // Button pressed
      if (!measured) {
        measureQuantumState();  // Collapse to a single state
      } else {
        quantumWalkStep();  // Continue walking
      }
    }
  }
}

void quantumWalkStep() {
  ComplexNumber newQuantumState[numPixels] = { {0, 0} };

  // Apply Quantum Coin (Hadamard-like transformation)
  for (int i = 0; i < numPixels; i++) {
    if (complexMagnitudeSquared(quantumState[i]) > 0) {
      // Hadamard-like effect with phase shift
      ComplexNumber leftAmp = { quantumState[i].real * 0.707 - quantumState[i].imag * 0.707, 
                                quantumState[i].real * 0.707 + quantumState[i].imag * 0.707 };
      ComplexNumber rightAmp = { quantumState[i].real * 0.707 + quantumState[i].imag * 0.707, 
                                 quantumState[i].imag * 0.707 - quantumState[i].real * 0.707 };

      if (i > 0) newQuantumState[i - 1] = complexAdd(newQuantumState[i - 1], leftAmp);
      if (i < numPixels - 1) newQuantumState[i + 1] = complexAdd(newQuantumState[i + 1], rightAmp);
    }
  }

  // Normalize the state
  float totalProb = 0;
  for (int i = 0; i < numPixels; i++) {
    totalProb += complexMagnitudeSquared(newQuantumState[i]);  // Sum of squared magnitudes
  }
  if (totalProb > 0) {
    float normFactor = 1.0 / sqrt(totalProb);
    for (int i = 0; i < numPixels; i++) {
      newQuantumState[i] = complexMultiply(newQuantumState[i], normFactor);
    }
  }

  // Update state
  for (int i = 0; i < numPixels; i++) {
    quantumState[i] = newQuantumState[i];
  }

  measured = false;  // Reset measurement
  updateLEDs();
}

void measureQuantumState() {
  float probabilities[numPixels] = {0};
  float sum = 0;

  // Compute probabilities
  for (int i = 0; i < numPixels; i++) {
    probabilities[i] = complexMagnitudeSquared(quantumState[i]);  // Magnitude squared
    sum += probabilities[i];
  }

  // Normalize
  if (sum > 0) {
    for (int i = 0; i < numPixels; i++) {
      probabilities[i] /= sum;
    }
  }

  // Collapse to a single position
  float randomValue = (float)random(1000) / 1000.0;
  float cumulative = 0;
  for (int i = 0; i < numPixels; i++) {
    cumulative += probabilities[i];
    if (randomValue <= cumulative) {
      walkerPosition = i;
      break;
    }
  }

  // Reset quantum state with a collapsed position
  for (int i = 0; i < numPixels; i++) {
    quantumState[i] = (i == walkerPosition) ? ComplexNumber{ 1.0, 0.0 } : ComplexNumber{ 0.0, 0.0 };
  }

  measured = true;  // Set flag to prevent further evolution
  updateLEDs();
}

void updateLEDs() {
  for (int i = 0; i < numPixels; i++) {
    if (measured && i == walkerPosition) {
      strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red for collapsed state
    } else {
      int brightness = int(complexMagnitudeSquared(quantumState[i]) * 255);
      strip.setPixelColor(i, strip.Color(0, 0, brightness));  // Blue for superposition
    }
  }
  strip.show();
}
