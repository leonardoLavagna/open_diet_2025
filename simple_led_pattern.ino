#include <FastLED.h>

#define LED_PIN     4   
#define NUM_LEDS    64 
#define BRIGHTNESS  16
#define LED_TYPE    WS2812B
// Change to RGB or BRG if colors are wrong
#define COLOR_ORDER GRB  

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    delay(100);
}

void loop() {
    // Clear all LEDs at the beginning of each loop
    FastLED.clear();
    FastLED.show();  
    delay(100); 

    // LED animation
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Red;  
        FastLED.show();
        delay(100);
    }

    // Reset the LEDs by turning them off after the animation
    FastLED.clear(); 
    FastLED.show(); 
    delay(100);     
}

