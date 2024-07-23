#include <Adafruit_NeoPixel.h>
#include "RainbowCycle.h"

#define MAX_INPUT_VOLUME 500  //10bit

Adafruit_NeoPixel rgb1(88, 12, NEO_GRB + NEO_KHZ800);  //Screen backlight (88 leds)
Adafruit_NeoPixel rgb2(60, 14, NEO_GRB + NEO_KHZ800);  //Top lamp (60 leds)
Adafruit_NeoPixel rgb3(42, 27, NEO_GRB + NEO_KHZ800);  //Music reactive bar (42 leds)
Adafruit_NeoPixel rgb4(30, 26, NEO_GRB + NEO_KHZ800);  //Name (Julius) (30 leds)
Adafruit_NeoPixel rgb5(24, 25, NEO_GRB + NEO_KHZ800);  //Heads Up light (24 leds)
Adafruit_NeoPixel RGBS[5] = { rgb1, rgb2, rgb3, rgb4, rgb5 };

RainbowCycle cycle1;
RainbowCycle cycle2;
RainbowCycle cycle3;

void setup() {

  Serial.begin(115200);
  //Connect();

  pinMode(35, INPUT);  //RIGHT-audio
  pinMode(32, INPUT);  //LEFT-audio

  //setup rgbs
  for(int i = 0; i<5; i++){
	  RGBS[i].begin();
  }

  bootUp_Debug(RGBS);
}

void mode1() {
  int left = analogRead(35);
  int right = analogRead(32);

  cycle1.count++;
  cycle2.count++;
  cycle3.count++;

  int effectMode2 = MusicReactive2(RGBS, left, right);

  if(left > 360){
    cycle2.direction = 0;
    
    if(effectMode2 != 1)
      cycle3.direction = 1;
  }
  if(right > 360){
    cycle2.direction = 1;
    
    if(effectMode2 != 1)
      cycle3.direction = 0;
  }

  if (cycle1.count > 3)  //20 * 0,2ms = 0.5sec
	  cycle1.Update(rgb1, 80);
  if (cycle2.count > 1)
	  cycle2.Update2(rgb4);
  if (cycle3.count > 1 && effectMode2 != 0)
	  cycle3.Update3(rgb2, 255, 1);

  delay(.5);
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