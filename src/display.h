#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <MenuSystem.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include <MenuSystem.h>


void onItemSelected(MenuItem* p_menuItem);

void draw(String str);
void setupDisplay();
void setupMenu();
void updateDisplay();

#endif /* end of include guard:  */
