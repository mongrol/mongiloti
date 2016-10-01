#include <Arduino.h>

#include <Encoder.h>
#include <MIDI.h>
#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_Trellis.h"

#include "smooth.h"
#include "logo.h"

//set POTS
#define POTCOUNT 10
SmoothAnalogInput pot0, pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8, pot9;
SmoothAnalogInput pots[POTCOUNT] = {
  pot0, pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8, pot9
};
int potValues[POTCOUNT];

//set button - PULLDOWN
#define BUTTON 2

//set RGB LED's - Analog , 255 to turn off
#define LED_RED 3
#define LED_GREEN 3
#define LED_BLUE 5

//set OLED
#define SSD1306_128_64
#define OLED_RESET 8
Adafruit_SSD1306 display(OLED_RESET);

//set Trellis
#define MOMENTARY 0
#define LATCHING 1
#define MODE LATCHING
Adafruit_Trellis matrix0 = Adafruit_Trellis();
Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0);
#define NUMTRELLIS 1
#define numKeys (NUMTRELLIS * 16)
#define INTPIN 9


//set Encoder pins
Encoder myEnc(7, 6);

//set Midi channel
const int channel = 7;



void setup()   {
  analogReadResolution(7);
  analogReadAveraging(8);
  Serial.begin(31250);
  MIDI.begin();

  //Attach pots A0-A3
  for (int i = 0;i<=4;i++){
    pots[i].attach(i);
    potValues[i] = pots[i].read();
    Serial.println("Reading pot:" + i );
  }

  //Attach pots A6-A11
  for (int i = 4;i<=9;i++){
    pots[i].attach(i+2);
    potValues[i] = pots[i].read();
    Serial.println("Reading pot:" + i );
  }

  // init button - PULLDOWN
  pinMode(BUTTON, INPUT_PULLDOWN);

  //RGB LED's (INPUT because of 5v instead of gnd)
  pinMode(LED_RED, INPUT);
  pinMode(LED_GREEN, INPUT);
  pinMode(LED_BLUE, INPUT);

  // init display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3d);

  //draw logo
  display.clearDisplay();
  display.fillRect(0,0,16,64,WHITE);
  display.fillRect(111,0,128,64,WHITE);
  display.drawBitmap(16, 0,  logo, 95, 64, 1);
  display.display();
  display.invertDisplay(false);

  // init Trellis  // INT pin requires a pullup
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);
  trellis.begin(0x70);
  // light up all the LEDs in order
  for (uint8_t i=0; i<numKeys; i++) {
    trellis.setLED(i);
    trellis.writeDisplay();
    delay(50);
  }
  // then turn them off
  for (uint8_t i=0; i<numKeys; i++) {
    trellis.clrLED(i);
    trellis.writeDisplay();
    delay(50);
  }
}

long oldEncoderPosition  = -999;
long newEncoderPosition = 10;

//rgb test
int rgbon = 155;
int rgboff = 255;

void draw(String str) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.print(str);

  display.display();
}

void loop() {

  delay(30); // 30ms delay is required for Trellis, TODO!

  //midi test
  //MIDI.sendNoteOn(50, 100, channel);
  //delay(1050);
  //MIDI.sendNoteOff(50, 100, channel);

  // read button
  if (digitalRead(BUTTON) == HIGH) {
    draw("button pressed");
  } else {
    // Serial.println("Button Not Pressed");
  }

  //rgb

  analogWrite(LED_RED, rgboff);
  analogWrite(LED_GREEN, rgboff);
  analogWrite(LED_BLUE, rgboff);

  newEncoderPosition = myEnc.read();
  if (newEncoderPosition != oldEncoderPosition) {
    oldEncoderPosition = newEncoderPosition;
    String label = "Enc:";
    label += myEnc.read();
    draw(label);
  }

  //scan pots for change
  for (int i = 0;i<=POTCOUNT;i++){
    int potValue = pots[i].read();
    if (potValues[i] != potValue){
      String label = "pot:";
      label += i;
      label += ":";
      label += potValue;
      draw(label);
      potValues[i] = potValue;
      if (i == 7){
        //send filter CC
        MIDI.sendControlChange(21, potValue, channel);
      }
    } else {
      /* draw(999); */
    }
  }

  //trellis
  if (MODE == LATCHING) {
    // If a button was just pressed or released...
    if (trellis.readSwitches()) {
      // go through every button
      for (uint8_t i=0; i<numKeys; i++) {
        // if it was pressed...
        if (trellis.justPressed(i)) {
          // Alternate the LED
          if (trellis.isLED(i))
            trellis.clrLED(i);
          else
            trellis.setLED(i);
        }
      }
      // tell the trellis to set the LEDs we requested
      trellis.writeDisplay();
    }
  }
}
