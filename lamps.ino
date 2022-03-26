#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN        D4
#define NEOPIXEL_LAMP_COUNT 12

Adafruit_NeoPixel neopixel(NEOPIXEL_LAMP_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
JsonArray lampsState;

// Call from loop
void lampsSetup() {
  neopixel.begin();
  neopixel.show();
}

void neoAllRgb (int r, int g, int b) {    
  for (int i = 0; i < NEOPIXEL_LAMP_COUNT; i++) {
    neopixel.setPixelColor(i, neopixel.Color(r, g, b));
  }
  neopixel.show();
}

void dynamicLamps(JsonArray value) {
  lampsState = value;
  int mode = value[0];
  int r = value[1];
  int g = value[2];
  int b = value[3];
  int brightness = value[4];

  switch(mode) {
    case 0: // RGB MODE
      neoAllRgb(r, g, b);
    break;
    
    default:
    break;
  }
}

void resetLampsState() {
  dynamicLamps(lampsState);
}
