
RainbowCycle cycle1;
RainbowCycle cycle2;
RainbowCycle cycle3;
RainbowCycle cycle4;

void mode1() {
  int left = analogRead(35);
  int right = analogRead(32);

  cycle1.count++;
  cycle2.count++;
  cycle3.count++;
  cycle4.count++;

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

 if (cycle4.count > 3)  //20 * 0,2ms = 0.5sec
    cycle4.Update2(rgb6, 255);

  delay(.5);
}

bool mode2_eff1_newClr_L = false;
bool mode2_eff1_newClr_R = false;
int mode2_eff1_clr_L = 0;
int mode2_eff1_clr_R = 0;
void mode2_eff1(int left, int right){

  if(right > 300){
    if(mode2_eff1_newClr_R)
      mode2_eff1_clr_R = random(0, 65536);
    
    for(int i = 0; i<rgb3.numPixels() / 2; i++){
      rgb3.setPixelColor(i, rgb3.ColorHSV(mode2_eff1_clr_R));
    }
  }

  if(left > 300){
    if(mode2_eff1_newClr_L)
      mode2_eff1_clr_L = random(0, 65536);
    
    for(int i = rgb3.numPixels() / 2; i<rgb3.numPixels(); i++){
        rgb3.setPixelColor(i, rgb3.ColorHSV(mode2_eff1_clr_L));
    }
  }

  mode2_eff1_newClr_L = left > 320;
  mode2_eff1_newClr_R = right > 320;

  rgb3.show();
  for(int i = 0 / 2; i<rgb3.numPixels(); i++){
      rgb3.setPixelColor(i, 0);
  }

  delay(random(0.5, 2));
}

int mode2_eff2_posX = 0;
int mode2_eff2_dir = 0;
int mode2_eff2_color_L = 0;
int mode2_eff2_color_R = 0;
void mode2_eff2(int left, int right){
  for(int i = 0; i<rgb2.numPixels(); i++){
    rgb2.setPixelColor(i, 0);
  }
  for(int i = 0; i<10; i++){
    rgb2.setPixelColor(i + mode2_eff2_posX, rgb2.ColorHSV(mode2_eff2_color_R));
  }
  rgb2.show();

  if(left > 350 || right > 350){
    mode2_eff2_color_R = random(0,64) * 1024;
  }

  mode2_eff2_posX += mode2_eff2_dir == 0 ? 1 : -1;

  if(mode2_eff2_posX  > rgb2.numPixels() - 10 || left > 350)
    mode2_eff2_dir = 1;
  if(mode2_eff2_posX <= 0 || right > 350)
    mode2_eff2_dir = 0;
}

bool mode2_eff3_newClr_L = false;
bool mode2_eff3_newClr_R = false;
int mode2_eff3_clr_L = 0;
int mode2_eff3_clr_R = 0;
void mode2_eff3(int left, int right){
  if(right > 300){
    if(mode2_eff3_newClr_R)
      mode2_eff3_clr_R = random(0, 65536);
    
    for(int i = 0; i<rgb1.numPixels() / 2; i++){
      rgb1.setPixelColor(i, rgb1.ColorHSV(mode2_eff3_clr_R));
    }
  }

  if(left > 300){
    if(mode2_eff3_newClr_L)
      mode2_eff3_clr_L = random(0, 65536);
    
    for(int i = rgb1.numPixels() / 2; i<rgb1.numPixels(); i++){
        rgb1.setPixelColor(i, rgb1.ColorHSV(mode2_eff3_clr_L));
    }
  }

  mode2_eff3_newClr_L = left > 320;
  mode2_eff3_newClr_R = right > 320;

  rgb1.show();
  for(int i = 0 / 2; i<rgb1.numPixels(); i++){
      rgb1.setPixelColor(i, 0);
  }

  delay(random(2, 10));
}

int mode2_eff4_posX = 0;
int mode2_eff4_dir = 0;
int mode2_eff4_color_L = 0;
int mode2_eff4_color_R = 0;
void mode2_eff4(int left, int right){
    for(int i = 0; i<rgb4.numPixels(); i++){
    rgb4.setPixelColor(i, 0);
  }
  for(int i = 0; i<10; i++){
    rgb4.setPixelColor(i + mode2_eff4_posX, rgb4.ColorHSV(mode2_eff4_color_R));
  }
  rgb4.show();

  if(left > 350 || right > 350){
    mode2_eff4_color_R = random(0,64) * 1024;
  }

  mode2_eff4_posX += mode2_eff4_dir == 0 ? 1 : -1;

  if(mode2_eff4_posX  > rgb4.numPixels() - 10 || left > 350)
    mode2_eff4_dir = 1;
  if(mode2_eff4_posX <= 0 || right > 350)
    mode2_eff4_dir = 0;
}

void mode2(){
  int left = analogRead(35);
  int right = analogRead(32);

  mode2_eff1(left, right);
  mode2_eff2(left, right);
  //mode2_eff3(left, right);

  if (cycle1.count++ > 10)
	  cycle1.Update(rgb1, 80);

  if(left > 450 || right > 450){
    int clr = rgb5.ColorHSV(random(0, 32) * 2048);
    for(int i = 0; i<rgb5.numPixels(); i++){
      rgb5.setPixelColor(i, clr);
    }

    for(int i = 0; i<rgb4.numPixels(); i++){
      rgb4.setPixelColor(i, clr);
    }
  }
  
  rgb5.show();
  rgb4.show();
  
  for(int i = 0; i<rgb5.numPixels(); i++){
    rgb5.setPixelColor(i, 0);
  }
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