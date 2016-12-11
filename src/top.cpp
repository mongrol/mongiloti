#include "all.h"

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
#define CC_OSC1_SHAPE 23
#define CC_OSC2_SHAPE 28
#define CC_OSC_MIX 31
#define CC_ENV1_ATTACK 73
#define CC_ENV1_DECAY 75
#define CC_ENV1_SUSTAIN 79
#define CC_ENV1_RELEASE 72
#define CC_FILTER_CUTOFF 74
#define CC_FILTER_RESONANCE 71
#define CC_VCA_GAIN 77

// Strings for Menu labels
const char *LABEL_OSC1_SHAPE = "OSC1 Shape";
const char *LABEL_OSC2_SHAPE = "OSC2 Shape";
const char *LABEL_OSC_MIX = "OSC Mix";
const char *LABEL_ENV1_ATTACK = "Env1 Atk";
const char *LABEL_ENV1_DECAY = "Env1 Dcy";
const char *LABEL_ENV1_SUSTAIN = "Env1 Sus";
const char *LABEL_ENV1_RELEASE = "Env1 Rel";
const char *LABEL_FILTER_CUTOFF = "Filter Cutoff";
const char *LABEL_FILTER_RESONANCE = "Filter Res";
const char *LABEL_VCA_GAIN = "VCA Gain";

//Create a static bunch of controls
//Each control has a label, a CC and a CV (current value)
Control controlOSC1Shape(LABEL_OSC1_SHAPE, CC_OSC1_SHAPE);

// Create Pot objects
// Each Pot has a pointer to a valid Control.
// When we switch menu's the pointer may point to a different Control

const int potCount = 10;

Pot pots[potCount] {
        { POT_A0, &controlOSC1Shape },
        { POT_A1 },
        { POT_A2 },
        { POT_A3 },
        { POT_A6 },
        { POT_A7 },
        { POT_A8 },
        { POT_A9 },
        { POT_A10 },
        { POT_A11 }
};


void setupState()
{
        //setup controls

        //setup AxoGroup
}

void updateState()
{
        //tests
        //Serial.printf(pots[0].p_control->get_name());

        //check devices for change
        //processPots();
        //processEncoder();
        processButton();
        processTrellis();
}
