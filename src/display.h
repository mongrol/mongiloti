#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
//#include "MenuSystem.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"



void draw(const char* label, int value);
void setupDisplay();
//void setupMenu();
void updateDisplay();

#endif /* end of include guard:  */