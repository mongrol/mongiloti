#include "all.h"
extern bool needDisplayUpdate;

extern Instrument Instruments[];
extern DSTATE dstate;
extern int activePot;
extern Metro displayTimer;

// set OLED
#define SSD1306_128_64
#define OLED_RESET 8

Adafruit_SSD1306 display(OLED_RESET);

void setupDisplay() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3d);
  // draw logo
  display.clearDisplay();
  display.fillRect(0, 0, 16, 64, WHITE);
  display.fillRect(111, 0, 128, 64, WHITE);
  display.drawBitmap(16, 0, logo, 95, 64, 1);
  display.display();
  display.invertDisplay(false);
}

void drawDial(int x, int y, int r, int value) {

  // draw the half circle
  display.drawCircleHelper(x, y, r, 3, WHITE);
  display.drawLine(x - r, y, x - r + 2, y, WHITE);
  display.drawLine(x + r, y, x + r - 2, y, WHITE);

  // draw the needle;
  float degrees = (float)value / 128 * 183 + 179;
  //        char outstr[15];
  //        dtostrf(degrees,7, 3, outstr);
  //        Serial.println(outstr);
  double theta = radians(degrees);
  int x1 = x + r * cos(theta);
  int y1 = y + r * sin(theta);
  display.drawLine(x, y, x1, y1, WHITE);
}

void drawScreen() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 4);
  display.print(displayTimer.check());

  if (dstate == DIALS) {
    // draw top row
    int x = 32;
    int y = 14;
    int r = 14;
    drawDial(x, y, r, Instruments[0].Controls[0].cv);
    // display.setCursor(x-r,y+2);
    // display.print(Instruments[0].Controls[0]._name );

    x = 64;
    drawDial(x, y, r, Instruments[0].Controls[1].cv);
    x = 96;
    drawDial(x, y, r, Instruments[0].Controls[2].cv);

    // draw second row
    y = 40;
    x = 16;
    drawDial(x, y, r, Instruments[0].Controls[3].cv);
    x = 48;
    drawDial(x, y, r, Instruments[0].Controls[4].cv);
    x = 80;
    drawDial(x, y, r, Instruments[0].Controls[5].cv);
    x = 112;
    drawDial(x, y, r, Instruments[0].Controls[6].cv);

    // draw third row
    y = 60;
    x = 32;
    drawDial(x, y, r, Instruments[0].Controls[7].cv);
    x = 64;
    drawDial(x, y, r, Instruments[0].Controls[8].cv);
    x = 96;
    drawDial(x, y, r, Instruments[0].Controls[9].cv);
  }
  if (dstate == BIGDIAL) {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    // draw the moved dial
    int x = 64;
    int y = 32;
    int r = 32;
    drawDial(x, y, r, Instruments[0].Controls[activePot].cv);
    display.setCursor(0, y + 4);
    display.print(Instruments[0].Controls[activePot]._name);
  }
  //        display.setTextSize(1);
  //        display.setTextColor(WHITE);

  display.display();
}

void draw(int cc, int value) {
  display.print(cc);
  display.setTextSize(3);
  display.setCursor(0, 32);
  display.print(value);
}

void updateDisplay() { display.display(); }
