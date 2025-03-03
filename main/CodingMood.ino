void CodingMood_Main(){
  verticalBars();
  delay(50);
}

void CodingMood_Setup(){
  randomSeed(analogRead(0));
  screenLamp();  
  textLamp();
    topLamp();

  headsupLight();
  printerLight();
}

void topLamp(){
  for(int i = 0; i<rgb2.numPixels(); i++){
    rgb2.setPixelColor(i, 255, 200, 220);
  }
  rgb2.show();
}

void verticalBars() {
  for (int i = 1; i < 22; i++) { 
    rgb3.setPixelColor(i-1, rgb3.getPixelColor(i));
  }

  if (random(0, 10) > 4) {
    rgb3.setPixelColor(21, rgb3.Color(random(2, 100), 0, random(2, 100)));
  } else {
    rgb3.setPixelColor(21, rgb3.Color(0, 0, 0));
  }

  for (int i = 22; i < 42; i++) { 
    rgb3.setPixelColor(i-1, rgb3.getPixelColor(i));
  }

  if (random(0, 10) > 4) {
    rgb3.setPixelColor(41, rgb3.Color(random(2, 100), 0, random(2, 100)));
  } else {
    rgb3.setPixelColor(41, rgb3.Color(0, 0, 0));
  }

  rgb3.show();
}

void textLamp(){
  for(int i = 0; i<rgb4.numPixels(); i++){
    rgb4.setPixelColor(i, 100,0,255);
    rgb4.show();
    delay(20);
  }
}

void screenLamp(){
  rgb1.setBrightness(100);
  for(int i = 0; i<rgb1.numPixels(); i++){
    rgb1.setPixelColor(i, 200, 0, 255);
  }
  rgb1.show();
}

void headsupLight(){
  rgb5.setBrightness(100);
  for(int i = 0; i<rgb1.numPixels(); i++){
    rgb5.setPixelColor(i,130, 0, 255);
  }
  rgb5.show();
}

void printerLight(){
  rgb6.setBrightness(90);
  for(int i = 0; i<rgb6.numPixels(); i++){
    rgb6.setPixelColor(i, 100,0,255);
    rgb6.show();
    delay(20);
  }
}