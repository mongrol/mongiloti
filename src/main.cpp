
#include "all.h"



void setup()   {
        //???
        analogReadResolution(7);
        analogReadAveraging(8);

        //setups
        setupTrellis();
        setupDisplay();
        delay(1000); //display logo for a second

        setupButton();
        setupPots();

        MIDI.begin();
}

void loop() {
        update();
        //display the currently set screen
        updateDisplay();
}
