#include <Adafruit_NeoPixel.h>
#include "RainbowCycle.h"

#define MAX_INPUT_VOLUME 500  //10bit

Adafruit_NeoPixel rgb1(88, 12, NEO_GRB + NEO_KHZ800);  //Screen backlight (88 leds)
Adafruit_NeoPixel rgb2(60, 14, NEO_GRB + NEO_KHZ800);  //Top lamp (60 leds)
Adafruit_NeoPixel rgb3(42, 27, NEO_GRB + NEO_KHZ800);  //Music reactive bar (42 leds)
Adafruit_NeoPixel rgb4(30, 26, NEO_GRB + NEO_KHZ800);  //Name (Julius) (30 leds)
Adafruit_NeoPixel rgb5(24, 25, NEO_GRB + NEO_KHZ800);  //Heads Up light (24 leds)
Adafruit_NeoPixel RGBS[5] = { rgb1, rgb2, rgb3, rgb4, rgb5 };

int allLeds = rgb1.numPixels() + rgb2.numPixels() + rgb3.numPixels() + rgb4.numPixels();

void setup() {

  Serial.begin(115200);
  //Connect();

  pinMode(35, INPUT);  //RIGHT-audio
  pinMode(32, INPUT);  //LEFT-audio

  //setup rgbs
  for(int i = 0; i<5; i++){
    RGBS[i].begin();
  }

  bootUp(RGBS);
}

RainbowCycle cycle1;
RainbowCycle cycle2;

void mode1() {
  MusicReactive1(RGBS);

  cycle1.count++;
  cycle2.count++;

  if (cycle1.count > 5)  //5 * 10ms = 0.5sec
    cycle1.Update(rgb1, 80);
  if (cycle2.count > 1)
    cycle2.Update2(rgb4);

  delay(2);
}

void rgbRandom(int wait) {
  int color = 0;
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < RGBS[j].numPixels(); i++) {
      color += 65536 / (RGBS[j].numPixels() / random(1, 4)); //random(65536);
      if(color > 65536)
        color = 0;
      RGBS[j].setPixelColor(i, RGBS[j].ColorHSV(color, 255, 255));
    }
    RGBS[j].show();
  }
  delay(wait);
}


void rgbMatrix(int wait) {
  int color = 0;
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < RGBS[j].numPixels(); i++) {
      color += 65536 / (RGBS[j].numPixels() / random(1, 4)); //random(65536);
      if(color > 65536)
        color = 0;
      if (random(2) == 0) {
         RGBS[j].setPixelColor(i, RGBS[j].Color(0, 0, 0));
      } else {
        RGBS[j].setPixelColor(i, RGBS[j].ColorHSV(color, 255, 255));
      }
    }
    RGBS[j].show();
  }
  delay(wait);
}

void loop() {
  mode1();
  //greenMatrix(80);
}