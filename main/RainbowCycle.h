#ifndef RainbowCycle_h
#define RainbowCycle_h

#include <Adafruit_NeoPixel.h>

class RainbowCycle {
  private: 
    int led = 0, direction = 0;
    unsigned long color = 0; // Changed 'color' to 'unsigned long' for better handling of color values
  
  public:
    int count = 0;
    RainbowCycle() {}

    void Update(Adafruit_NeoPixel& rgb, int bright = 255) {
      rgb.setPixelColor(led, rgb.ColorHSV(color, 255, bright));
      rgb.show();

      count = 0;
      if(direction == 0)
        led++;
      else 
        led--;
      
      color += (65025 / rgb.numPixels() / 2);
      if(color > 65025)
        color = 0;

      if(led > rgb.numPixels())
        direction = 1;
      else if(led == 0)
        direction = 0; 
    }

    void Update2(Adafruit_NeoPixel& rgb, int bright = 255) {
      rgb.setPixelColor(led, rgb.ColorHSV(color, 255, bright));
      rgb.show();

      count = 0;     
      led++;
      
      color += (65025 / rgb.numPixels() / 2);
      if(color > 65025)
        color = 0;

      if(led > rgb.numPixels())
        led = 0;
    }
};

#endif