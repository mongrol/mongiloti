#ifndef POT_H
#define POT_H
#include "all.h"


void processPots();

#define SMOOTH_ANALOG_INPUT_SIZE 1

class Pot {
public:
        Pot(int pin);
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
