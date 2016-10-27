#ifndef POT_H
#define POT_H
#include "control.h"
#include <MIDI.h>

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


void processPots();
void setupPots();

#define SMOOTH_ANALOG_INPUT_SIZE 2

class Pot : public Control {
public:
        Pot(int pin, const char* name, byte cc);
        void attach(int pin);
        void scale(int min, int max);
        int read();
        int raw();
private:
        int _samples[SMOOTH_ANALOG_INPUT_SIZE];
        int _pin;
        int _index;
        int _mapMin;
        int _mapMax;
        int _res;
};

#endif /* end of include guard: POT_H */
