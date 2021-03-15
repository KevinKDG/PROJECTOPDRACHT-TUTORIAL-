//------ LIBRARY ------
#include <Adafruit_NeoPixel.h>


//------ DEFINE PINS ------                     
#define PIXEL_PIN    6    // Digital IO pin connected to the NeoPixel lED strip.
#define PIXEL_COUNT 5     // number of leds on the ledstrip
#define BUTTON_PIN   7    // Pin that is connected to the button



Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
bool oldState = HIGH;
int showType = 0;



//------ SETUP CODE ------
void setup() {
 
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show();                                 // Initialize all pixels to 'off'
}

//------ LOOP CODE ------
void loop() {
  
  bool newState = digitalRead(BUTTON_PIN);      // Get current button state.
  
  if (newState == LOW && oldState == HIGH) {    // Check if state changed from high to low (button press).
    delay(20);                                  // debounce
    newState = digitalRead(BUTTON_PIN);         // Check if button is still low after debounce.
    if (newState == LOW) {
      showType++;
      if (showType > 6)                         // Number of cases
        showType=0;
      switch_color(showType);                   // Switch cases
    }
  }

  oldState = newState;                          // Set the last button state to the old state.
}

void switch_color(int i) {
  switch(i){
    case 0: ChangeColor(strip.Color(0, 0, 0), 50);    // off
            break;
    case 1: ChangeColor(strip.Color(255, 0, 0), 50);  // Red
            break;
    case 2: ChangeColor(strip.Color(0, 255, 0), 50);  // Green
            break;
    case 3: ChangeColor(strip.Color(0, 0, 255), 50);  // Blue
            break;
    case 4: ChangeColor(strip.Color(255, 255, 0), 50);  // Yellow
            break;           
    case 5: ChangeColor(strip.Color(255, 255, 255), 50);  // White
            break;              
    case 6: ChangeColor(strip.Color(255, 147,41), 50);  // Warm light
            break;
                       
  }
}

void ChangeColor(uint32_t c, uint8_t wait) {      
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setBrightness(10);
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
