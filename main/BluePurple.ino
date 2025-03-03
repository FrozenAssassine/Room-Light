int musicOffCounter = 0;
bool toggleAllTwoIterations = false;

void BluePurpleMood_Main() {
  int left = analogRead(32);
  int right = analogRead(35);

  if (left == 0 && right == 0) {
    delay(5);
    if (left == 0 && right == 0)
      musicOffCounter++;
    if (musicOffCounter > 100) {
      bluePurple_verticalBars();
      bluePurple_topLamp();
      bluePurple_headsupLight();
      delay(30);
      return;
    }
  } else {
    musicOffCounter = 0;
  }

  bluePurple_verticalBarsMusic(left, right);

  bluePurple_headsupLightMusic(left, right);

  if (!toggleAllTwoIterations) {
    bluePurple_topLampMusic(left, right);
  }

  toggleAllTwoIterations = !toggleAllTwoIterations;

  delay(15);
}

void bluePurple_Setup() {
  randomSeed(analogRead(0));
  bluePurple_screenLamp();
  bluePurple_textLamp();
  bluePurple_topLamp();

  bluePurple_headsupLight();
  bluePurple_printerLight();
}

void bluePurple_verticalBarsMusic(int left, int right) {
  int leftMapped = map(left, 0, 400, 0, 255);
  int rightMapped = map(right, 0, 400, 0, 255);

  rgb3.setPixelColor(21, rgb3.Color(leftMapped > 245 ? 15 : leftMapped, 0, leftMapped));
  for (int i = 0; i < 21; i++) {
    rgb3.setPixelColor(i, rgb3.getPixelColor(i + 1));
  }

  rgb3.setPixelColor(41, rgb3.Color(rightMapped > 245 ? 15 : rightMapped, 0, rightMapped));
  for (int i = 22; i < 41; i++) {
    rgb3.setPixelColor(i, rgb3.getPixelColor(i + 1));
  }


  rgb3.show();
}

void bluePurple_verticalBarsMusicUp(int left, int right) {
  int leftMapped = map(left, 0, 400, 0, 255);
  int rightMapped = map(right, 0, 400, 0, 255);

  for (int i = 20; i >= 0; i--) {
    rgb3.setPixelColor(i + 1, rgb3.getPixelColor(i));
  }

  if (random(0, 10) > 4) {
    rgb3.setPixelColor(0, rgb3.Color(leftMapped, 0, random(0, leftMapped)));
  } else {
    rgb3.setPixelColor(0, rgb3.Color(0, 0, 0));
  }

  for (int i = 40; i >= 22; i--) {
    rgb3.setPixelColor(i + 1, rgb3.getPixelColor(i));
  }

  if (random(0, 10) > 4) {
    rgb3.setPixelColor(22, rgb3.Color(rightMapped, 0, random(0, rightMapped)));
  } else {
    rgb3.setPixelColor(22, rgb3.Color(0, 0, 0));
  }

  rgb3.show();
}

void bluePurple_verticalBars() {
  if (random(0, 10) > 4) {
    rgb3.setPixelColor(21, rgb3.Color(random(2, 100), 0, random(2, 100)));
  } else {
    rgb3.setPixelColor(21, rgb3.Color(0, 0, 0));
  }
  for (int i = 0; i < 21; i++) {
    rgb3.setPixelColor(i, rgb3.getPixelColor(i + 1));
  }

  if (random(0, 10) > 4) {
    rgb3.setPixelColor(41, rgb3.Color(random(2, 100), 0, random(2, 100)));
  } else {
    rgb3.setPixelColor(41, rgb3.Color(0, 0, 0));
  }
  for (int i = 22; i < 41; i++) {
    rgb3.setPixelColor(i, rgb3.getPixelColor(i + 1));
  }

  rgb3.show();
}

void bluePurple_topLampMusic(int left, int right) {
  int leftMapped = map(right, 0, 400, 0, 255);  //swap of left and right is intended
  int rightMapped = map(left, 0, 400, 0, 255);


  if (leftMapped == 0) {
    rgb2.setPixelColor(0, 0, 232, 255);
  } else {
    rgb2.setPixelColor(0, rgb2.Color(rightMapped > 245 ? 15 : rightMapped, 0, rightMapped));
  }
  for (int i = 29; i > 0; i--) {
    rgb2.setPixelColor(i, rgb2.getPixelColor(i - 1));
  }

  if (leftMapped == 0) {
    rgb2.setPixelColor(59, 0, 232, 255);
  } else {
    rgb2.setPixelColor(59, rgb2.Color(leftMapped > 245 ? 15 : leftMapped, 0, leftMapped));
  }

  for (int i = 30; i < 59; i++) {
    rgb2.setPixelColor(i, rgb2.getPixelColor(i + 1));
  }

  rgb2.show();
}

void bluePurple_topLamp() {
  for (int i = 0; i < rgb2.numPixels(); i++) {
    rgb2.setPixelColor(i, 0, 232, 255);
  }
  rgb2.show();
}

void bluePurple_textLamp() {
  for (int i = 0; i < rgb4.numPixels(); i++) {
    rgb4.setPixelColor(i, 255, 0, 255);
    rgb4.show();
    delay(20);
  }
}

void bluePurple_screenLamp() {
  rgb1.setBrightness(100);
  for (int i = 0; i < rgb1.numPixels(); i++) {
    rgb1.setPixelColor(i, 200, 0, 255);
  }
  rgb1.show();
}

void bluePurple_headsupLight() {
  rgb5.setBrightness(100);
  for (int i = 0; i < rgb5.numPixels(); i++) {
    rgb5.setPixelColor(i, 150, 0, 255);
  }
  rgb5.show();
}

void bluePurple_headsupLightMusic(int left, int right) {
  int avgMapped = map((left + right) / 2, 0, 400, 0, 255);

  rgb5.setBrightness(avgMapped > 255 ? 255 : avgMapped < 225 ? 0 : avgMapped);
  for (int i = 0; i < rgb5.numPixels(); i++) {
    rgb5.setPixelColor(i, 255, 255, 255);
  }
  rgb5.show();
}

void bluePurple_printerLight() {
  rgb6.setBrightness(90);
  for (int i = 0; i < rgb6.numPixels(); i++) {
    rgb6.setPixelColor(i, 255, 150, 255);
    rgb6.show();
    delay(20);
  }
}