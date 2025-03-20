#include <Adafruit_NeoPixel.h>

const int buttonPin = 2;
const int ledPin = 4;  
const int numPixels = 64;  

int buttonStatus = HIGH;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;
int walkerPosition = 35;  

float quantumState[numPixels] = {0};  // Probability amplitudes
bool isWaitingForNextPress = false;   // Flag to check if we're waiting for the next button press
int redLEDIndex = -1;  // Store the index of the red LED, -1 means no red LED

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

  // Only react to button press if not in the waiting state
  if (pinValue != buttonStatus && (millis() - lastDebounceTime) > debounceDelay && !isWaitingForNextPress) {
    lastDebounceTime = millis();
    buttonStatus = pinValue;

    if (buttonStatus == LOW) {  // Button pressed
      quantumWalkStep();  // Execute a quantum walk step
      isWaitingForNextPress = true;  // Start the waiting period before the next step
      delay(500);  // Short delay before turning one LED red
      turnOneBlueLEDRed();  // Turn one of the blue LEDs red
    }
  }

  // Reset the waiting flag to allow the next button press
  if (isWaitingForNextPress && (millis() - lastDebounceTime) > 1000) {
    isWaitingForNextPress = false;  // Ready for the next press
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
    // If this LED is the red one, set it red
    if (i == redLEDIndex) {
      strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red color
    } else {
      strip.setPixelColor(i, strip.Color(0, 0, brightness));  // Blue for quantum visualization
    }
  }
  strip.show();
}

void turnOneBlueLEDRed() {
  // First, turn off the previous red LED (if any)
  if (redLEDIndex != -1) {
    // Reset the previous red LED back to blue
    strip.setPixelColor(redLEDIndex, strip.Color(0, 0, int(quantumState[redLEDIndex] * 255)));  // Reset to blue
  }

  // Find all blue LEDs (those with non-zero quantum state)
  int blueLEDs[numPixels];
  int numBlueLEDs = 0;

  for (int i = 0; i < numPixels; i++) {
    if (quantumState[i] > 0) {  // Only consider LEDs with non-zero quantum state (blue LEDs)
      blueLEDs[numBlueLEDs++] = i;
    }
  }

  // If there are any blue LEDs, randomly choose one to turn red
  if (numBlueLEDs > 0) {
    // Randomly pick one of the blue LEDs to turn red
    redLEDIndex = blueLEDs[random(numBlueLEDs)];
    strip.setPixelColor(redLEDIndex, strip.Color(255, 0, 0));  // Turn selected LED red
    strip.show();
  }
}
