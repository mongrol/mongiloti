#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "display.h"
#include "logo.h"

//set OLED
#define SSD1306_128_64
#define OLED_RESET 8

Adafruit_SSD1306 display(OLED_RESET);

MenuSystem ms;
Menu OSC("");
MenuItem OSC_1("Detune");
MenuItem OSC_2("Pitch");
Menu FIL("");
MenuItem FIL_1("Frequency");
MenuItem FIL_2("Resonance");

void onItemSelected(MenuItem* p_menuItem){

}

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

void draw(String str) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);
  display.setTextColor(WHITE);

  // Display the menu
  Menu const* cp_menu = ms.get_current_menu();
  display.print(cp_menu->get_name());
  display.setCursor(0,1);
  display.print(cp_menu->get_selected()->get_name());
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
