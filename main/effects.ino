int numberOfLEDS = 6;  //The number of led items in the leds[] array

void setRangeColor(Adafruit_NeoPixel led, int start, int length, int red, int green, int blue) {
  for (int i = start; i < start + length; i++) {
    led.setPixelColor(i, red, green, blue);
  }
}

void setRangeColor(Adafruit_NeoPixel led, int start, int length, int color) {
  for (int i = start; i < start + length; i++) {
    led.setPixelColor(i, color);
  }
}

void setRangeOff(Adafruit_NeoPixel led, int start, int length) {
  for (int i = start; i < start + length; i++) {
    led.setPixelColor(i, 0);
  }
}

void allRainbow(Adafruit_NeoPixel leds[], int time) {
  for (int i = 0; i < numberOfLEDS; i++) {
    effect1(leds[i], time);
  }
}

void allStatic(Adafruit_NeoPixel leds[], int red, int green, int blue) {
  for (int i = 0; i < numberOfLEDS; i++) {
    setRangeColor(leds[i], 0, leds[i].numPixels(), red, green, blue);
    leds[i].show();
  }
}
void setAll(Adafruit_NeoPixel leds[], int red, int green, int blue){
    for(int i = 0; i<numberOfLEDS; i++){
     for(int j = 0; j<leds[i].numPixels(); j++){
       leds[i].setPixelColor(j, red,green,blue);
     }
     leds[i].show();
  }
}

void bootUp_Debug(Adafruit_NeoPixel leds[]) {
  delay(500);
  setAll(leds, 255,0,0);
  delay(300);
  setAll(leds, 0,255,0);
  delay(300);
  setAll(leds, 0,0,255);
  delay(300);
  setAll(leds,0,0,0);
  delay(300);

  for (int i = 0; i < numberOfLEDS; i++) {
    int color = 0, count = 0;
    for(int j = 0; j<leds[i].numPixels(); j++){
      leds[i].setPixelColor(count, leds[i].ColorHSV(color, 255, 255));
      leds[i].show();
      count++;
      color += (65025 / leds[i].numPixels());
      delay(10);
    }
  }

  delay(500);

  for(int i = numberOfLEDS - 1; i>=0; i--){
    for(int j = 0; j< leds[i].numPixels(); j++){
      leds[i].setPixelColor(j, 0,0,0);
    }
    delay(100);
    leds[i].show();
  }
}

void bootUp(Adafruit_NeoPixel leds[]) {
  delay(5000);
  setAll(leds, 255,0,0);
  delay(800);
  setAll(leds, 0,255,0);
  delay(800);
  setAll(leds, 0,0,255);
  delay(800);
  setAll(leds,0,0,0);
  delay(800);

  for (int i = 0; i < numberOfLEDS; i++) {
    int color = 0, count = 0;
    for(int j = 0; j<leds[i].numPixels(); j++){
      leds[i].setPixelColor(count, leds[i].ColorHSV(color, 255, 255));
      leds[i].show();
      count++;
      color += (65025 / leds[i].numPixels());
      delay(30);
    }
  }

  delay(5000);

  for(int i = numberOfLEDS - 1; i>=0; i--){
    for(int j = 0; j< leds[i].numPixels(); j++){
      leds[i].setPixelColor(j, 0,0,0);
    }
    delay(300);
    leds[i].show();
  }
}

void effect1(Adafruit_NeoPixel led, int time) {
  int color = 0;
  for (int i = 0; i < led.numPixels(); i++) {
    led.setPixelColor(i, led.ColorHSV(color));

    color += (65536 / led.numPixels());
    if (color > 65536)
      color = 0;

    led.show();
    delay(time);
  }
}

int leftOffCount, rightOffCount = 0;
int leftOffCount2, rightOffCount2 = 0;
int colorshift = 0;

void MusicReactive1(Adafruit_NeoPixel leds[]) {
  int left = analogRead(35);
  int right = analogRead(32);

  for (int i = 1; i < numberOfLEDS; i++) {
    int numberOfPixels = leds[i].numPixels();
    int left_map = map(left, 0, MAX_INPUT_VOLUME, numberOfPixels / 2, numberOfPixels);
    int right_map = map(right, 0, MAX_INPUT_VOLUME, 0, numberOfPixels / 2);
    int right_color = colorshift;
    int left_color = colorshift;

    /*if (i == 2)  //only for music reactive bars:
    {
      //left channel
      for (int j = numberOfPixels / 2; j < left_map; j++)  //set color
      {
        leds[i].setPixelColor(j, leds[i].ColorHSV(left_color));
        left_color += (65025 / (numberOfPixels / 2));
        if (left_color > 65025)
          left_color = 0;
      }

      for (int j = left_map; j < numberOfPixels; j++)  //make them off
        leds[i].setPixelColor(j, 0, 0, 0);

      //right channel
      for (int j = 0; j < right_map; j++)  //set color
      {
        leds[i].setPixelColor(j, leds[i].ColorHSV(right_color));
        right_color += (65025 / (numberOfPixels / 2));
        if (right_color > 65025)
          right_color = 0;
      }

      for (int j = right_map; j < numberOfPixels / 2; j++)  //make them off
        leds[i].setPixelColor(j, 0, 0, 0);
    } 
    else */
    if (i == 1)
    {
      right_color = left_color = colorshift;

      //left channel
      for (int j = numberOfPixels / 2; j < left_map; j++)  //set color
      {
        leds[i].setPixelColor(j, leds[i].ColorHSV(left_color));
        left_color += (65025 / (numberOfPixels / 2));
        if (left_color > 65025)
          left_color = 0;
      }
      if (left_map == numberOfPixels / 2) {
        leftOffCount++;
        if (leftOffCount > 12) {
          leftOffCount = 0;
          for (int j = left_map; j < numberOfPixels; j++)  //make them off
            leds[i].setPixelColor(j, 0, 0, 0);
        }
      }

      //right channel
      //for(int j = right_map; j<numberOfPixels / 2; j++)//set color
      for (int j = numberOfPixels / 2; j > (numberOfPixels / 2) - right_map; j--)  //set color
      {
        leds[i].setPixelColor(j, leds[i].ColorHSV(right_color));
        right_color += (65025 / (numberOfPixels / 2));
        if (right_color > 65025)
          right_color = 0;
      }

      if (right_map == 0) {
        rightOffCount++;
        if (rightOffCount > 12) {
          rightOffCount = 0;
          for (int j = 0; j < (numberOfPixels / 2) - right_map; j++)  //make them off
            leds[i].setPixelColor(j, 0, 0, 0);
        }
      }
    }
    else if(i == 4){
      right_color = left_color = colorshift;

      //left channel
      for (int j = numberOfPixels / 2; j < left_map; j++)  //set color
      {
        leds[i].setPixelColor(j, leds[i].ColorHSV(left_color));
        left_color += (65025 / (numberOfPixels / 2));
        if (left_color > 65025)
          left_color = 0;
      }
      if (left_map == numberOfPixels / 2) {
        leftOffCount2++;
        if (leftOffCount2 > 12) {
          leftOffCount2 = 0;
          for (int j = left_map; j < numberOfPixels; j++)  //make them off
            leds[i].setPixelColor(j, 0, 0, 0);
        }
      }

      //right channel
      //for(int j = right_map; j<numberOfPixels / 2; j++)//set color
      for (int j = numberOfPixels / 2; j > (numberOfPixels / 2) - right_map; j--)  //set color
      {
        leds[i].setPixelColor(j, leds[i].ColorHSV(right_color));
        right_color += (65025 / (numberOfPixels / 2));
        if (right_color > 65025)
          right_color = 0;
      }

      if (right_map == 0) {
        rightOffCount2++;
        if (rightOffCount2 > 12) {
          rightOffCount2 = 0;
          for (int j = 0; j < (numberOfPixels / 2) - right_map; j++)  //make them off
            leds[i].setPixelColor(j, 0, 0, 0);
        }
      }
    }
    colorshift += (65025 / 1000);
    if (colorshift > 65025)
      colorshift = 0;
    leds[i].show();
  }
}

int mode = 0;
int offCount = 0;
int count = 0;
int left_color2 = 0;
int right_color2 = 0;
int color3 = 0;
int effectMode2 = 0;
int effectMode2Count = 0;
int effectMode2OffCount = 0;

int MusicReactive2(Adafruit_NeoPixel leds[], int left, int right) {
  int right_color = colorshift;
  int left_color = colorshift;

  if(left > 332 || right > 332){
    effectMode2Count++;
    if(effectMode2Count > 130){
      effectMode2 = 1;
      effectMode2OffCount = 0;
    }
    if(effectMode2Count > 210){
      effectMode2 = 2;
      effectMode2OffCount = 0;
    }
  }
  else if(left < 20  || right < 20){
    effectMode2OffCount++;
    if(effectMode2OffCount > 200){
      effectMode2 = effectMode2OffCount = effectMode2Count = 0;
    }
  }
  else if(effectMode2Count > 400){
    effectMode2Count = effectMode2 = 0;
  }

  for (int i = 1; i < numberOfLEDS; i++) {
    if(i != 2 && i != 1 && i != 4)
      continue;
    
    int numberOfPixels = leds[i].numPixels();
    int left_map = map(left, 0, MAX_INPUT_VOLUME, numberOfPixels / 2, numberOfPixels);
    int right_map = map(right, 0, MAX_INPUT_VOLUME, 0, numberOfPixels / 2);

    if (i == 2)  //only for music reactive bars:
    {
      if(left > 360 || right > 360){
        count++;
        if(count > 4){
          mode = 1;
        }
      }
      else if(left < 100 || right < 100){
        offCount++;
        if(offCount > 40){
          mode = count = offCount = 0;
        }
      }

      if(mode == 0){

      //left channel
      for (int j = numberOfPixels / 2; j < left_map; j++)  //set color
      {
        leds[i].setPixelColor(j, leds[i].ColorHSV(left_color));
        left_color += (65025 / (numberOfPixels / 2));
        if (left_color > 65025)
          left_color = 0;
      }

      //right channel
      for (int j = 0; j < right_map; j++)  //set color
      {
        leds[i].setPixelColor(j, leds[i].ColorHSV(right_color));
        right_color += (65025 / (numberOfPixels / 2));
        if (right_color > 65025)
          right_color = 0;
      }

      for (int j = left_map; j < numberOfPixels; j++)  //make them off
        leds[i].setPixelColor(j, 0, 0, 0);
      for (int j = right_map; j < numberOfPixels / 2; j++)  //make them off
        leds[i].setPixelColor(j, 0, 0, 0);
      
      }else{
        int c1 = random(0, 5) * (6502 * 2);
        int c2 = random(0, 5) * (6502 * 2);
        for (int j = numberOfPixels / 2; j < left_map; j++)  //set color
        {
          leds[i].setPixelColor(j, leds[i].ColorHSV(c1));
        }
        for (int j = 0; j < right_map; j++)  //set color
        {
          leds[i].setPixelColor(j, leds[i].ColorHSV(c2));
        }
      }
    }
    else if (i == 1 && effectMode2 == 0) //top down light
    {
        if(left > 370){
          left_color2 += (65025 / 15);
          if (left_color2 > 65025)
            left_color2 = 0;
        }
        if(right > 370){
          right_color2 += (65025 / 15);
          if (right_color2 > 65025)
            right_color2 = 0;
        }
        //left channel
        for (int j = numberOfPixels / 2; j < left_map; j++)  //set color
        {
          leds[i].setPixelColor(j, leds[i].ColorHSV(left_color2));
        }
        //right channel
        for (int j = numberOfPixels / 2; j > (numberOfPixels / 2) - right_map; j--)  //set color
        {
          leds[i].setPixelColor(j, leds[i].ColorHSV(right_color2));
        }
      }

      if (left_map == numberOfPixels / 2) {
          leftOffCount++;
          if (leftOffCount > 12) {
            leftOffCount = 0;
            for (int j = left_map; j < numberOfPixels; j++)  //make them off
              leds[i].setPixelColor(j, 0);
          }
      }
      if (right_map == 0) {
        rightOffCount++;
        if (rightOffCount > 12) {
          rightOffCount = 0;
          for (int j = 0; j < (numberOfPixels / 2) - right_map; j++)  //make them off
            leds[i].setPixelColor(j, 0);
        }
    }
    else if(i == 4){ //heads Up light
      if(left>370 ||right > 370){
        color3 += (65025 / 30); 
        if(color3 > 65025)
          color3 = 0;
      }else if(left > 300 || right > 300){
        for(int j = 0; j < numberOfPixels; j++){
          leds[i].setPixelColor(j, leds[i].ColorHSV(color3));
        }
      }
      else if(left < 100 || right < 100){
        for(int j = 0; j < numberOfPixels; j++){
            leds[i].setPixelColor(j, 0);
        }
      }
    }
    leds[i].show();
  }
  return effectMode2;
}