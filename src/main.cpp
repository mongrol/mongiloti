#include <Arduino.h>

#include <MIDI.h>
#include <SPI.h>
#include <Wire.h>

#include "defines.h"
#include "encoder.h"
#include "pot.h"
#include "trellis.h"
#include "display.h"

//rgb test
int rgbon = 155;
int rgboff = 255;
//const int ledPin = 13;

void setup()   {
        //???
        analogReadResolution(7);
        analogReadAveraging(8);

        //setups
        setupTrellis();
        setupDisplay();
        delay(1000); //display logo

        setupButton();
        setupPots();

        //setup Menu
        //Populate global array of structs.
        //Menu struct will contain, Label and a struct of controls

        //Set current Menu item
        //call MenuRenderer(currentMenuItem)
        //update the display
        MIDI.begin();
}


void loop() {
        delay(30); // 30ms delay is required for Trellis, TODO!

        //midi test
        //MIDI.sendNoteOn(50, 100, CHANNEL);
        //delay(500);
        //MIDI.sendNoteOff(50, 100, CHANNEL);
        //processTrellis();

        //timeout will set back to root Screen
        //processMenuTimout();

        //moving a pot sets the current display to the pot screen
        //triggers a menu render
        //reset screensaver timeout
        processPots();

        //moving encoder cycles the current menu level
        processEncoder();

        //button press will trigger the menu's callback.
        processButton();

        //if anything under current MenuItem has changed then.
        //call MenuRenderer(currentMenuItem)

        //display the currently set screen
        updateDisplay();
}
