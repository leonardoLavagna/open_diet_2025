#include <Adafruit_NeoPixel.h>

const int buttonPin = 2;
const int ledPin = 4; 
const int numPixels = 64;  

int buttonStatus = HIGH;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;
int walkerPosition = 35;  

Adafruit_NeoPixel strip(numPixels, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {
  int pinValue = digitalRead(buttonPin);

  if (pinValue != buttonStatus && (millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis();
    buttonStatus = pinValue;

    if (buttonStatus == LOW) {  // Button pressed
      randomWalk();
    }
  }
}

void randomWalk() {
  // Turn off previous position
  strip.setPixelColor(walkerPosition, strip.Color(0, 0, 0));

  // Move walker randomly: -1 (left) or +1 (right), staying within bounds
  int step = (random(0, 2) == 0) ? -1 : 1;
  walkerPosition = constrain(walkerPosition + step, 0, numPixels - 1);

  // Set new position with a random color
  strip.setPixelColor(walkerPosition,strip.Color(255, 0, 0));
  strip.show();

  Serial.print("New position: ");
  Serial.println(walkerPosition);
}
