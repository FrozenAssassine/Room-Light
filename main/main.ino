#include <Adafruit_NeoPixel.h>
#include "RainbowCycle.h"

#define MAX_INPUT_VOLUME 500 // 10bit

Adafruit_NeoPixel rgb1(88, 12, NEO_GRB + NEO_KHZ800); // Screen backlight (88 leds)
Adafruit_NeoPixel rgb2(60, 14, NEO_GRB + NEO_KHZ800); // Top lamp (60 leds)
Adafruit_NeoPixel rgb3(42, 27, NEO_GRB + NEO_KHZ800); // Music reactive bar (42 leds)
Adafruit_NeoPixel rgb4(30, 26, NEO_GRB + NEO_KHZ800); // Name (Julius) (30 leds)
Adafruit_NeoPixel rgb5(24, 25, NEO_GRB + NEO_KHZ800); // Heads Up light (24 leds)
Adafruit_NeoPixel rgb6(48, 33, NEO_GRB + NEO_KHZ800); // 3d printer light (48 leds)
Adafruit_NeoPixel RGBS[6] = {rgb1, rgb2, rgb3, rgb4, rgb5, rgb6};

void setup()
{

  Serial.begin(115200);

  pinMode(35, INPUT); // RIGHT-audio
  pinMode(32, INPUT); // LEFT-audio

  // setup rgbs
  for (int i = 0; i < 6; i++)
  {
    RGBS[i].begin();
  }

  christmas_Setup();

  // bluePurple_Setup();

  // bootUp(RGBS);
}

void loop()
{
  // mode1();
  // BluePurpleMood_Main();
  ChristmasMood_Main();
}