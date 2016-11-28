#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "display.h"
#include "logo.h"
#include "menu.h"

extern int menuIndex;
extern bool drawn;

//set OLED
#define SSD1306_128_64
#define OLED_RESET 8

Adafruit_SSD1306 display(OLED_RESET);

void setupDisplay() {
        display.begin(SSD1306_SWITCHCAPVCC, 0x3d);
        //draw logo
        display.clearDisplay();
        display.fillRect(0,0,16,64,WHITE);
        display.fillRect(111,0,128,64,WHITE);
        display.drawBitmap(16, 0,  logo, 95, 64, 1);
        display.display();
        display.invertDisplay(false);
}

void drawMenu(const int index) {

        Serial.printf("printing: %s\n", menu[index].name );
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(2);
        display.setCursor(0,0);
        display.print(menu[index].name);

        drawn = true;
}

void draw(const char* label, int value) {
        display.clearDisplay();
        display.setTextColor(WHITE);

        display.setTextSize(2);
        display.setCursor(0,0);
        display.print(label);

        display.setTextSize(3);
        display.setCursor(0,32);
        display.print(value);
}


void updateDisplay(){

        display.display();
}
