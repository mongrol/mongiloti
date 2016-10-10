#include <Arduino.h>

#include <MenuSystem.h>
#include <MIDI.h>
#include <SPI.h>
#include <Wire.h>

#include "defines.h"
#include "encoder.h"
#include "pot.h"
#include "trellis.h"
#include "display.h"
#include "logo.h"



//set Midi channel
const int channel = 7;

//rgb test
int rgbon = 155;
int rgboff = 255;

void setup()   {

  //???
  analogReadResolution(7);
  analogReadAveraging(8);

  //do we need this? Not for MIDI anyway.
  Serial.begin(31250);

  //setup Midi
  MIDI.begin();

  //setups
  setupDisplay();
  setupMenu();
  setupEncoder();
  setupTrellis();

  //RGB LED's (INPUT because of 5v instead of gnd)
  pinMode(LED_RED, INPUT);
  pinMode(LED_GREEN, INPUT);
  pinMode(LED_BLUE, INPUT);
  //rgb
  analogWrite(LED_RED, rgboff);
  analogWrite(LED_GREEN, rgboff);
  analogWrite(LED_BLUE, rgboff);
}


void loop() {

  delay(30); // 30ms delay is required for Trellis, TODO!

  //midi test
  //MIDI.sendNoteOn(50, 100, channel);
  //delay(1050);
  //MIDI.sendNoteOff(50, 100, channel);

  processButton();
  processEncoder();
  processPots();
  processTrellis();

  updateDisplay();
}
