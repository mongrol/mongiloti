#include <Arduino.h>

#include <Encoder.h>
#include <MenuSystem.h>
#include <MIDI.h>
#include <SPI.h>
#include <Wire.h>

#include "trellis.h"
#include "render.h"
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





//set Encoder pins
Encoder myEnc(7, 6);

//set Midi channel
const int channel = 7;


void setup()   {

  //setup display
  setupDisplay();
  setupTrellis();

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

}

long oldEncoderPosition  = -999;
long newEncoderPosition = 10;

//rgb test
int rgbon = 155;
int rgboff = 255;


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

  processTrellis();


}
