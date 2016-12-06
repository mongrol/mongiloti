#include "all.h"

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

//const int potCount = 10;

void setupState()
{
    //setup controls


    //setup AxoGroup
}

void updateState()
{
    //check devices for change
    //processPots();
    //processEncoder();
    //processButton();
}
