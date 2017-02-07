#include "all.h"
extern int menuIndex;
//extern bool drawn;
extern MenuItem menu[3];

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

        int x=20, y=0, w=16, h=16;

        //print label - Must be 4 chars long
        display.clearDisplay();
        display.fillRect(0,0,16,64,WHITE);
        display.drawLine(x+w*4,0,x+w*4,64, WHITE);


        display.setTextColor(BLACK);
        display.setTextSize(2);
        display.setCursor(3,1);
        display.print(menu[index]._name[0]);
        display.setCursor(3,17);
        display.print(menu[index]._name[1]);
        display.setCursor(3,33);
        display.print(menu[index]._name[2]);
        display.setCursor(3,49);
        display.print(menu[index]._name[3]);


        display.setTextColor(WHITE);

        display.setCursor(x,y);

        //print 1st pot
        for (int i=0; i<=menu[index]._cNum;i++){
          display.setTextSize(2);
          display.print(menu[index]._c1._name);
          display.setCursor(x+w*4+6,0);
          display.print(menu[index]._c1.cv);
          display.drawLine(x,h+1,128,h+1, WHITE);
        }


        //2nd pot
        // display.setCursor(64,24);
        // display.print(menu[index]._c2._name);
        // display.setCursor(64,36);
        // display.print(menu[index]._c2.cv);
        //
        // //3rd pot
        // display.setCursor(64,48);
        // display.print(menu[index]._c3._name);
        // display.setCursor(64,56);
        // display.print(menu[index]._c3.cv);
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
