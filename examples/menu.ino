/*
 * oled_nav.ino - Example code using the menu system library
 *
 * This example shows using the menu system with a el cheepo
 * SH1106 OLED display from eBay and a Sparkfun rotary encoder
 *
 * Hardware used is:
 *
 * - Teensy 3.2 (https://www.pjrc.com/store/teensy32.html)
 * - Sparkfun Rotary Encoder (https://www.sparkfun.com/products/10982)
 * - Cheap eBay SH1106 OLED Display (Adafruit's SSD1306 should also work)
 *
 * Software used is:
 *
 * - Adafruit mfGFX Graphics Library (https://forums.adafruit.com/viewtopic.php?f=47&t=61388)
 * - SH1106 display library (see http://tomashg.com/?p=1263)
 * - Teensy Encoder Library (https://www.pjrc.com/teensy/td_libs_Encoder.html)
 *
 * Copyright (c) 2016 arduino-menusystem
 * Licensed under the MIT license (see LICENSE)
 */

#include <Arduino.h>
#include <MenuSystem.h>

// Need these libraries for the OLED and Rotary Encoder
#include <SPI.h>
#include <Wire.h>
#include <Encoder.h>
#include <Adafruit_mfGFX.h>
#include <Adafruit_SH1106.h>

const byte ENC_LEFT_PIN             = 24;
const byte ENC_RIGHT_PIN            = 25;
const byte PUSH_BUTTON_PIN          = 26;
const byte OLED_RESET               = 33;

Encoder myEnc(ENC_LEFT_PIN, ENC_RIGHT_PIN);

Adafruit_SH1106  lcd(-1);
//Adafruit_SSD1306 lcd(OLED_RESET);

// renderer
class MyRenderer : public MenuComponentRenderer {
public:
    virtual void render(Menu const& menu) const {
        lcd.clearDisplay();
        lcd.setTextColor(WHITE);
        lcd.setCursor(0,0);
        lcd.print(menu.get_name());
        lcd.setCursor(0,20);
        menu.get_current_component()->render(*this);
        lcd.display();
    }

    virtual void render_menu_item(MenuItem const& menu_item) const {
        lcd.print(menu_item.get_name());
        lcd.display();
    }

    virtual void render_back_menu_item(BackMenuItem const& menu_item) const {
        lcd.print(menu_item.get_name());
        lcd.display();
    }

    virtual void render_numeric_menu_item(NumericMenuItem const& menu_item) const {
        lcd.print(menu_item.get_name());
        lcd.display();
    }

    virtual void render_menu(Menu const& menu) const {
        lcd.print(menu.get_name());
        lcd.display();
    }
};
MyRenderer my_renderer;

// Forward declarations
void on_item1_selected(MenuItem* p_menu_item);
void on_item2_selected(MenuItem* p_menu_item);
void on_item3_selected(MenuItem* p_menu_item);
void on_back_selected(MenuItem* p_menu_item);

int readEncoder(void);

// Menu variables

MenuSystem ms(my_renderer);
MenuItem mm_mi1("Level 1 - Item 1 (Item)",  &on_item1_selected);
MenuItem mm_mi2("Level 1 - Item 2 (Item)",  &on_item2_selected);
Menu mu1("Level 1 - Item 3 (Menu)");
MenuItem mu1_mi1("Level 2 - Item 1 (Item)", &on_item3_selected);
MenuItem mu1_mi2("Level 2 - Back",          &on_back_selected);


// Helper function(s) for OLED display

// Display (or erase) text on the OLED
void showIt(const char * text, boolean erase) {
   if (erase)
      lcd.setTextColor(BLACK);  
    else
      lcd.setTextColor(WHITE);
  
    lcd.setCursor(0,30);
    lcd.print(text);
    lcd.display();
}

// Main display routine for selection handling
void showSelected(const char * text) {
    showIt(text, false);               // Show the text
    delay(1500);                       // Wait for a moment
    showIt(text, true);                // Erase text
}

// Menu callback functions

void on_item1_selected(MenuItem* p_menu_item) {
  showSelected("Item1 Selected  ");
}

void on_item2_selected(MenuItem* p_menu_item) {
  showSelected("Item2 Selected  ");
}

void on_item3_selected(MenuItem* p_menu_item) {
  showSelected("Item3 Selected  ");
}

// This callback should be used any time a "back" selection is needed
void on_back_selected(MenuItem* p_menu_item) {
  ms.back();
}

// Get input from the Rotary Encoder
void rotaryHandler() {
  short command = readEncoder();
  switch (command) {
    case -1:             // LEFT
      ms.prev();
      ms.display();

      break;
    case 1:              // RIGHT
      ms.next();
      ms.display();

      break;
    case 0:              // SELECT
      ms.select();
      ms.display();
      delay(100);        // Crude debounce attempt

      break;        
  }
}

// Read the Rotary encoder and wait for a button press or movement
//
// Based on code from
//(https://simelectronics.wordpress.com/2012/11/10/using-encoders-with-x-plane/)
int readEncoder(void) {
  while (1) {
    // Has a button been pressed?
    if (digitalRead(PUSH_BUTTON_PIN) == HIGH) {
      // Yes.  Make sure it's been released
      while (digitalRead(PUSH_BUTTON_PIN) == HIGH) {}

      return 0;
     } else {
      // divide by 4 to find how many 'clicks' the encoder's gone through
      short myEncDiff = myEnc.read() / 4;
 
      if (myEncDiff) {
        // only done when we've reached a detent!
        myEnc.write(0);

        return myEncDiff;
       }
     }
  }
  
  return 0;     // Just to keep the compiler happy
}

// Standard arduino functions
void setup() {
  pinMode(PUSH_BUTTON_PIN, INPUT);
  
  lcd.begin(SH1106_SWITCHCAPVCC,  0x3C); // Default I2C Address
//lcd.begin(SSD1306_SWITCHCAPVCC, 0x3D); // Use I2C addr 0x3D

  lcd.clearDisplay();  
  lcd.drawPixel(0,0,BLACK);            // Remove stray pixel on screen??
  lcd.setTextColor(WHITE);  
  lcd.display();
  
  ms.get_root_menu().add_item(&mm_mi1);
  ms.get_root_menu().add_item(&mm_mi2);
  ms.get_root_menu().add_menu(&mu1);
  mu1.add_item(&mu1_mi1);
  mu1.add_item(&mu1_mi2);

  ms.display();
}

void loop() {
  rotaryHandler();
}