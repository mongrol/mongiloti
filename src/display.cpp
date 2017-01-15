#include "all.h"
extern int menuIndex;
//extern bool drawn;
extern MenuItem menu[1];

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

        //Serial.printf("printing: %s ", menu[index].get_name() );
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(2);
        display.setCursor(0,0);
        display.print(menu[index]._name);

        //set row 2
        display.setTextSize(1);
        display.setCursor(0,22);
        display.print(menu[index]._c1._name);

        //set row 3
        display.setTextSize(1);
        display.setCursor(0,30);
        display.print(menu[index]._c1.cv);
}

void drawMenu(Pot * pot) {
        display.clearDisplay();
        display.setTextColor(WHITE);

        //set for top tow. Menu Label
        display.setTextSize(2);
        display.setCursor(0,0);
        //display.print(pot->p_control->get_name());

        display.drawLine(0, 16, display.width()-1, 16, WHITE);

        //set row 2
        display.setTextSize(1);
        display.setCursor(0,22);
        //display.print(pot->p_control->get_name());

        //set row 3
        display.setTextSize(3);
        display.setCursor(0,36);
        display.print("0123456");

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
