//------ LIBRARY ------
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>


//------ DEFINE PINS ------                     
#define PIXEL_PIN    6   // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 5   // number of neopixel (change this accordingly)
#define BUTTON_PIN   7    // Button pin

#define LED_TYPE WS2812B 
#define BRIGHTNESS 150   /* Control the brightness of your leds */
#define SATURATION 255   /* Control the saturation of your leds */

CRGB leds[PIXEL_COUNT];

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = HIGH;
int showType = 0;



//------ SETUP CODE ------
void setup() {
  FastLED.addLeds<LED_TYPE, PIXEL_PIN>(leds, PIXEL_COUNT);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

//------ LOOP CODE ------
void loop() {
  for (int j = 0; j < 255; j++) {
    for (int i = 0; i < PIXEL_COUNT; i++) {
      leds[i] = CHSV(i - (j * 2), BRIGHTNESS, SATURATION); /* The higher the value 4 the less fade there is and vice versa */ 
    }
    FastLED.show();
    delay(25); 
  }
}
