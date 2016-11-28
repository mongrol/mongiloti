#include <Arduino.h>

#include <MIDI.h>
#include <SPI.h>
#include <Wire.h>

#include "encoder.h"
#include "pot.h"
#include "trellis.h"
#include "display.h"
#include "menu.h"

int menuIndex = 0;
bool drawn = true;

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

        //Set current Menu item
        //call MenuRenderer(currentMenuItem)
        //update the display
        MIDI.begin();
}


void loop() {
        //delay(30); // 30ms delay is required for Trellis, TODO!

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
        //redraw menu
        if (!drawn) {
                drawMenu(menuIndex);
        }

        //display the currently set screen
        updateDisplay();
}
