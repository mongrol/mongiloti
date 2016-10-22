#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "display.h"
#include "logo.h"

//set OLED
#define SSD1306_128_64
#define OLED_RESET 8

Adafruit_SSD1306 display(OLED_RESET);

//extern MenuSystem ms;

// Menu rootMenu("Mongiloti");
// Menu OSC("");
// MenuItem OSC_1("Detune");
// MenuItem OSC_2("Pitch");
// MenuItem OSC_3("Mix");
// Menu FIL("");
// MenuItem FIL_1("Frequency");
// MenuItem FIL_2("Resonance");

//void onItemSelected(MenuItem* p_menuItem){}

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

// void setupMenu() {
//         rootMenu.add_menu(&OSC);
//         OSC.add_item(&OSC_1, &onItemSelected);
//         OSC.add_item(&OSC_2, &onItemSelected);
//         rootMenu.add_menu(&FIL);
//         FIL.add_item(&FIL_1, &onItemSelected);
//         ms.set_root_menu(&rootMenu);
// }

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

// void displayMenu() {
//   lcd.clear();
//   lcd.setCursor(0,0);
//
//
//   //lcd.print("Current menu name: ");
//   lcd.print();
//
//   lcd.setCursor(0,1);
//
//   lcd.print(cp_menu->get_selected()->get_name());
// }
