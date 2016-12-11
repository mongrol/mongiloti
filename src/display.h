#ifndef DISPLAY_H
#define DISPLAY_H

#include "all.h"
#include "logo.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

extern State menuState;

void drawMenu(Pot * pot);
void draw(int cc, int value);
void draw(const char* label);
void setupDisplay();
void updateDisplay();

#endif /* end of include guard:  */
