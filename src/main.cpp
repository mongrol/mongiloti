
#include "all.h"

uint8_t menuIndex = 0;
bool drawn = true;

void setup()   {
        //???
        analogReadResolution(7);
        analogReadAveraging(8);

        //setups
        setupTrellis();
        setupDisplay();
        delay(1000); //display logo

        setupState();

        //setupButton();
        //setupPots();

        //update the display
        MIDI.begin();
}

void loop() {


        updateState();
        //display the currently set screen
        updateDisplay();
}
