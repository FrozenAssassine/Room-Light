#ifndef RainbowCycle_h
#define RainbowCycle_h

#include <Adafruit_NeoPixel.h>

class RainbowCycle {
  private: 
    unsigned long color = 0;
  
  public:
    int count = 0;
    int led = 0, direction = 0;
    RainbowCycle() {}

    //skipLast is so that I can only update half of the strip and do something else with the other leds
    void Update(Adafruit_NeoPixel& rgb, int bright = 255, int skipLast = 0) {
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

      if(led > rgb.numPixels() - skipLast)
        direction = 1;
      else if(led == 0)
        direction = 0; 
    }
    void Update3(Adafruit_NeoPixel& rgb, int bright = 255, int numLeds = 1) {

      int endLed = (direction == 0) ? led + numLeds - 1 : led - numLeds + 1;
      
      for(int i = led; (direction == 0) ? i <= endLed : i >= endLed; (direction == 0) ? i++ : i--) {
        rgb.setPixelColor(i, rgb.ColorHSV(color, 255, bright));
      }
      rgb.show();

      if(direction == 0)
        led += numLeds;
      else 
        led -= numLeds;

      color += (65025 / (rgb.numPixels() * 2));
      if(color > 65025)
        color = 0;

      if(led >= rgb.numPixels())
        led = 0;
      else if(led < 0)
        led = rgb.numPixels() - 1; 
    }

    void Update2(Adafruit_NeoPixel& rgb, int bright = 255) {
      rgb.setPixelColor(led, rgb.ColorHSV(color, 255, bright));
      rgb.show();

      count = 0;     
      if(direction == 0)
        led++;
      else 
        led--;
      
      color += (65025 / (rgb.numPixels() * 2));
      if(color > 65025)
        color = 0;

      if(led > rgb.numPixels())
        led = 0;
      else if(led <= 0)
        led = rgb.numPixels(); 
    }
};

#endif