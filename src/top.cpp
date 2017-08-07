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

// Control CC's
#define CC_RATIO 20
#define CC_NOISE_DECAY 21
#define CC_BODY_DECAY 22
#define CC_TUNE 23
#define CC_PITCH_ENV 24
#define CC_PITCH_DECAY 25
#define CC_DRIVE 26
#define CC_NOISE_ACCENT 27
#define CC_BODY_ACCENT 28
#define CC_DRIVE_ACCENT 29


// Strings for Control labels
const char *L_RATIO = "Noise/Decay Ratio";
const char *L_NOISE_DECAY = "Noise Decay";
const char *L_BODY_DECAY = "Body Decay";
const char *L_TUNE = "Tune";
const char *L_PITCH_ENV = "Pitch Env";
const char *L_PITCH_DECAY = "Pitch Decay";
const char *L_DRIVE = "Drive";
const char *L_NOISE_ACCENT = "Noise Accent";
const char *L_BODY_ACCENT = "Body Accent";
const char *L_DRIVE_ACCENT = "Drive Accent";

const char *L_INSTRUMENT_1 = "Kick";
const char *L_INSTRUMENT_2 = "Snare";
const char *L_INSTRUMENT_3 = "cHat";
const char *L_INSTRUMENT_4 = "oHat";

//Create Instruments
Instrument Instruments[1] {
        { L_INSTRUMENT_1,
        {
                { L_RATIO, CC_RATIO, 0 },
                { L_NOISE_DECAY, CC_NOISE_DECAY, 0 },
                { L_BODY_DECAY, CC_BODY_DECAY, 0 },
                { L_TUNE, CC_TUNE, 0 },
                { L_PITCH_ENV, CC_PITCH_ENV, 0 },
                { L_PITCH_DECAY, CC_PITCH_DECAY, 0 },
                { L_DRIVE, CC_DRIVE, 0 },
                { L_NOISE_ACCENT, CC_NOISE_ACCENT, 0 },
                { L_BODY_ACCENT, CC_BODY_ACCENT, 0 },
                { L_DRIVE_ACCENT, CC_DRIVE_ACCENT, 0 }
                }
        }
};

int menuIndex = 0;
bool needDisplayUpdate = false;

// Create Pot objects

Pot pots[10] {
        POT_A0, POT_A1, POT_A2, POT_A3, POT_A6, POT_A7,
        POT_A8, POT_A9, POT_A10, POT_A11
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
        //processTrellis();
        if (needDisplayUpdate) {
                drawScreen();
                //Serial.print("updating screen");
                needDisplayUpdate = false;
        }
}
