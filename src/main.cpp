
#include "all.h"


void setup()   {
        //???
        analogReadResolution(7);
        analogReadAveraging(8);

        //setups
        //setupTrellis(); disabled due to power issues.
        setupDisplay();
        delay(1000); //display logo for a second

        setupButton();
        MIDI.begin();

}

void loop() {
        update();
        //display the currently set screen
        updateDisplay();
}
