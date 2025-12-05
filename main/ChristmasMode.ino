int musicOffCounterChristmas = 0;
bool toggleAllTwoIterationsChristmas = false;
int christmasColorMode = 0;

void ChristmasMood_Main() {
  int left = analogRead(32);
  int right = analogRead(35);

  if (left == 0 && right == 0) {
    delay(5);
    if (left == 0 && right == 0)
      musicOffCounterChristmas++;
    if (musicOffCounterChristmas > 100) {
      christmas_verticalBars();
      christmas_topLamp();
      christmas_headsupLight();
      delay(30);
      return;
    }
  } else {
    musicOffCounterChristmas = 0;
  }

  christmas_verticalBarsMusic(left, right);

  christmas_headsupLightMusic(left, right);

  if (!toggleAllTwoIterationsChristmas) {
    christmas_topLampMusic(left, right);
  }

  toggleAllTwoIterationsChristmas = !toggleAllTwoIterationsChristmas;

  delay(15);
}

void christmas_Setup() {
  randomSeed(analogRead(0));
  christmas_screenLamp();
  christmas_textLamp();
  christmas_topLamp();

  christmas_headsupLight();
  christmas_printerLight();
}

void christmas_verticalBarsMusic(int left, int right) {
  int leftMapped = map(left, 0, 400, 0, 255);
  int rightMapped = map(right, 0, 400, 0, 255);

  // Left bar: Pure red with white sparkles on peaks
  if (leftMapped > 230) {
    rgb3.setPixelColor(21, rgb3.Color(255, 255, 255)); // White sparkle
  } else {
    rgb3.setPixelColor(21, rgb3.Color(leftMapped, 0, 0)); // Pure red
  }
  
  for (int i = 0; i < 21; i++) {
    rgb3.setPixelColor(i, rgb3.getPixelColor(i + 1));
  }

  // Right bar: Pure green with white sparkles on peaks
  if (rightMapped > 230) {
    rgb3.setPixelColor(41, rgb3.Color(255, 255, 255)); // White sparkle
  } else {
    rgb3.setPixelColor(41, rgb3.Color(0, rightMapped, 0)); // Pure green
  }
  
  for (int i = 22; i < 41; i++) {
    rgb3.setPixelColor(i, rgb3.getPixelColor(i + 1));
  }

  rgb3.show();
}

void christmas_verticalBarsMusicUp(int left, int right) {
  int leftMapped = map(left, 0, 400, 0, 255);
  int rightMapped = map(right, 0, 400, 0, 255);

  for (int i = 20; i >= 0; i--) {
    rgb3.setPixelColor(i + 1, rgb3.getPixelColor(i));
  }

  if (random(0, 10) > 4) {
    int colorPick = random(0, 3);
    if (colorPick == 0) {
      rgb3.setPixelColor(0, rgb3.Color(leftMapped, 0, 0)); // Red
    } else if (colorPick == 1) {
      rgb3.setPixelColor(0, rgb3.Color(0, leftMapped, 0)); // Green
    } else {
      rgb3.setPixelColor(0, rgb3.Color(255, 255, 255)); // White
    }
  } else {
    rgb3.setPixelColor(0, rgb3.Color(0, 0, 0));
  }

  for (int i = 40; i >= 22; i--) {
    rgb3.setPixelColor(i + 1, rgb3.getPixelColor(i));
  }

  if (random(0, 10) > 4) {
    int colorPick = random(0, 3);
    if (colorPick == 0) {
      rgb3.setPixelColor(22, rgb3.Color(rightMapped, 0, 0));
    } else if (colorPick == 1) {
      rgb3.setPixelColor(22, rgb3.Color(0, rightMapped, 0));
    } else {
      rgb3.setPixelColor(22, rgb3.Color(255, 255, 255));
    }
  } else {
    rgb3.setPixelColor(22, rgb3.Color(0, 0, 0));
  }

  rgb3.show();
}

void christmas_verticalBars() {
  if (random(0, 10) > 4) {
    int colorPick = random(0, 4);
    if (colorPick == 0 || colorPick == 1) {
      rgb3.setPixelColor(21, rgb3.Color(random(80, 255), 0, 0)); // Red (more likely)
    } else if (colorPick == 2) {
      rgb3.setPixelColor(21, rgb3.Color(0, random(80, 200), 0)); // Green
    } else {
      rgb3.setPixelColor(21, rgb3.Color(255, 255, 255)); // White accent
    }
  } else {
    rgb3.setPixelColor(21, rgb3.Color(0, 0, 0));
  }
  
  for (int i = 0; i < 21; i++) {
    rgb3.setPixelColor(i, rgb3.getPixelColor(i + 1));
  }

  if (random(0, 10) > 4) {
    int colorPick = random(0, 4);
    if (colorPick == 0 || colorPick == 1) {
      rgb3.setPixelColor(41, rgb3.Color(0, random(80, 200), 0)); // Green (more likely)
    } else if (colorPick == 2) {
      rgb3.setPixelColor(41, rgb3.Color(random(80, 255), 0, 0)); // Red
    } else {
      rgb3.setPixelColor(41, rgb3.Color(255, 255, 255)); // White accent
    }
  } else {
    rgb3.setPixelColor(41, rgb3.Color(0, 0, 0));
  }
  
  for (int i = 22; i < 41; i++) {
    rgb3.setPixelColor(i, rgb3.getPixelColor(i + 1));
  }

  rgb3.show();
}

void christmas_topLampMusic(int left, int right) {
  int leftMapped = map(right, 0, 400, 0, 255);  // swap of left and right is intended
  int rightMapped = map(left, 0, 400, 0, 255);

  // Create red and green traveling waves
  if (leftMapped == 0) {
    rgb2.setPixelColor(0, 150, 0, 0); // Soft red when silent
  } else {
    rgb2.setPixelColor(0, rgb2.Color(0, rightMapped, 0)); // Green wave
  }
  
  for (int i = 29; i > 0; i--) {
    rgb2.setPixelColor(i, rgb2.getPixelColor(i - 1));
  }

  if (leftMapped == 0) {
    rgb2.setPixelColor(59, 0, 120, 0); // Soft green when silent
  } else {
    rgb2.setPixelColor(59, rgb2.Color(leftMapped, 0, 0)); // Red wave
  }

  for (int i = 30; i < 59; i++) {
    rgb2.setPixelColor(i, rgb2.getPixelColor(i + 1));
  }

  rgb2.show();
}

void christmas_topLamp() {
  // Alternating red and green pattern
  for (int i = 0; i < rgb2.numPixels(); i++) {
    if (i % 2 == 0) {
      rgb2.setPixelColor(i, 220, 0, 0); // Bright red
    } else {
      rgb2.setPixelColor(i, 0, 180, 0); // Bright green
    }
  }
  rgb2.show();
}

void christmas_textLamp() {
  // Boot animation: Red and green chase with white accents
  for (int i = 0; i < rgb4.numPixels(); i++) {
    int pattern = i % 3;
    if (pattern == 0) {
      rgb4.setPixelColor(i, 255, 0, 0); // Red
    } else if (pattern == 1) {
      rgb4.setPixelColor(i, 0, 220, 0); // Green
    } else {
      rgb4.setPixelColor(i, 255, 255, 255); // White
    }
    rgb4.show();
    delay(20);
  }
}

void christmas_screenLamp() {
  rgb1.setBrightness(100);
  // Warm red ambient glow for screen
  for (int i = 0; i < rgb1.numPixels(); i++) {
    rgb1.setPixelColor(i, 255, 120, 10);
  }
  rgb1.show();
}

void christmas_headsupLight() {
  rgb5.setBrightness(100);
  // Soft green ambient
  for (int i = 0; i < rgb5.numPixels(); i++) {
    rgb5.setPixelColor(i, 0, 180, 0);
  }
  rgb5.show();
}

void christmas_headsupLightMusic(int left, int right) {
  int avgMapped = map((left + right) / 2, 0, 400, 0, 255);

  rgb5.setBrightness(avgMapped > 255 ? 255 : avgMapped < 225 ? 0 : avgMapped);
  
  // Alternate between red and green with music intensity
  unsigned long currentTime = millis();
  int colorCycle = (currentTime / 1000) % 2; // Switch every second
  
  if (colorCycle == 0) {
    for (int i = 0; i < rgb5.numPixels(); i++) {
      rgb5.setPixelColor(i, 255, 0, 0); // Red
    }
  } else {
    for (int i = 0; i < rgb5.numPixels(); i++) {
      rgb5.setPixelColor(i, 0, 255, 0); // Green
    }
  }
  rgb5.show();
}

void christmas_printerLight() {
  rgb6.setBrightness(90);
  // Red, green, white chase pattern
  for (int i = 0; i < rgb6.numPixels(); i++) {
    int pattern = i % 3;
    if (pattern == 0) {
      rgb6.setPixelColor(i, 255, 0, 0); // Red
    } else if (pattern == 1) {
      rgb6.setPixelColor(i, 0, 255, 0); // Green
    } else {
      rgb6.setPixelColor(i, 255, 255, 255); // White
    }
    rgb6.show();
    delay(20);
  }
}