#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
//#include "MenuSystem.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "menu.h"


void drawMenu(const int index);
void draw(int cc, int value);
void setupDisplay();
void updateDisplay();

#endif /* end of include guard:  */
