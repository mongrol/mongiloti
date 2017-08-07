#include "all.h"
extern bool needDisplayUpdate;

extern Instrument Instruments[];


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

void drawScreen() {
        //draw a circle, like a dial
        display.clearDisplay();
        int x0 = 64;
        int y0 = 32;
        int r = 30;
        display.drawCircle(x0, y0, r, WHITE);

        //draft gauge drawing
        float degrees =  (float)Instruments[0].Controls[0].cv / 128 * 183 + 179;
        char outstr[15];
        dtostrf(degrees,7, 3, outstr);
        Serial.println(outstr);
        double theta = radians(degrees);
        int x = x0 + r * cos(theta);
        int y = y0 + r * sin(theta);

        Serial.printf("%d %d ", x, y);
        
        display.drawLine(x0, y0, x, y, WHITE);

        display.display();
}

void draw(int cc, int value) {


        display.print(cc);

        display.setTextSize(3);
        display.setCursor(0,32);
        display.print(value);
}

void updateDisplay(){

        display.display();
}
