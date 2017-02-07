#include "all.h"

//MIDI Channel
#define CHANNEL 1

// POT to pin
#define POT_A0 0
#define POT_A1 1
#define POT_A2 2
#define POT_A3 3
#define POT_A6 6
#define POT_A7 7
#define POT_A8 8
#define POT_A9 9
#define POT_A10 10
#define POT_A11 11


// CC descriptions and CC number
// trying to stick to GM Midi standards or Micromonsta maps
#define CC_OSC1_PITCH 22
#define CC_OSC1_SHAPE 23
#define CC_OSC1_MIX 25
#define CC_OSC2_PITCH 27
#define CC_OSC2_SHAPE 28
#define CC_OSC2_MIX 30
#define CC_OSC3_PITCH 31
#define CC_OSC3_SHAPE 32
#define CC_OSC3_MIX 33

#define CC_ENV1_ATTACK 73
#define CC_ENV1_DECAY 75
#define CC_ENV1_SUSTAIN 79
#define CC_ENV1_RELEASE 72
#define CC_FILTER_CUTOFF 74
#define CC_FILTER_RESONANCE 71
#define CC_VCA_GAIN 77

// Strings for Menu labels
const char *LABEL_OSC1 = "OSC1";
const char *LABEL_OSC2 = "OSC2";
const char *LABEL_OSC3 = "OSC3";
const char *LABEL_PITCH = "Pitch";
const char *LABEL_SHAPE = "Shape";
const char *LABEL_MIX = "Mix";
const char *LABEL_ENV1 = "Env1";
const char *LABEL_ENV2 = "Env2";

const char *LABEL_ATTACK = "Attack";
const char *LABEL_DECAY = "Decay";
const char *LABEL_SUSTAIN = "Sustain";
const char *LABEL_RELEASE = "Release";
const char *LABEL_FILTER_CUTOFF = "Filter Cutoff";
const char *LABEL_FILTER_RESONANCE = "Filter Res";
const char *LABEL_VCA_GAIN = "VCA Gain";

//Create control structs
//Each control has a label, a CC assigned and holds the current value of the CC
Control controlOSC1Shape = { LABEL_SHAPE, CC_OSC1_SHAPE, 0 };
Control controlOSC1Pitch = { LABEL_PITCH, CC_OSC1_PITCH, 0 };
Control controlOSC1Mix = { LABEL_MIX, CC_OSC1_MIX, 0 };

Control controlOSC2Shape = { LABEL_SHAPE, CC_OSC2_SHAPE, 0 };
Control controlOSC2Pitch = { LABEL_PITCH, CC_OSC2_PITCH, 0 };
Control controlOSC2Mix = { LABEL_MIX, CC_OSC2_MIX, 0 };

Control controlOSC3Shape = { LABEL_SHAPE, CC_OSC3_SHAPE, 0 };
Control controlOSC3Pitch = { LABEL_PITCH, CC_OSC3_PITCH, 0 };
Control controlOSC3Mix = { LABEL_MIX, CC_OSC3_MIX, 0 };

int menuIndex = 0;

// Create menu objects.
// Each menu has a label and pointers to control structs

MenuItem menu[3] {
        { LABEL_OSC1, 3, controlOSC1Pitch, controlOSC1Shape, controlOSC1Mix },
        { LABEL_OSC2, 3, controlOSC2Pitch, controlOSC2Shape, controlOSC2Mix },
        { LABEL_OSC3, 3, controlOSC3Pitch, controlOSC3Shape, controlOSC3Mix }
};

// Create Pot objects
// Each Pot has a pointer to a valid Control.
// When we switch menu's the pointer may point to a different Control

bool drawn = true;

Pot pots[POTCOUNT] {
        { POT_A0, &controlOSC1Pitch, 0 },
        { POT_A1, &controlOSC1Shape, 0 },
        { POT_A2, &controlOSC1Mix, 0 }
        // { POT_A3 },
        // { POT_A6 },
        // { POT_A7 },
        // { POT_A8 },
        // { POT_A9 },
        // { POT_A10 },
        // { POT_A11 }
};

void push_cv(byte cc, byte cv)
{
        MIDI.sendControlChange(cc, cv, CHANNEL);
}


void update()
{
        //tests
        //Serial.printf(pots[0].p_control->get_name());

        //check devices for change
        processPots();
        processEncoder();
        processButton();
        processTrellis();
        drawMenu(menuIndex);
}
