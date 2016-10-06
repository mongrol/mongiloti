#ifndef TRELLIS_H
#define TRELLIS_H

#include "Adafruit_Trellis.h"

//set Trellis
#define MOMENTARY 0
#define LATCHING 1
#define MODE LATCHING

#define NUMTRELLIS 1
#define numKeys (NUMTRELLIS * 16)
#define INTPIN 9

void processTrellis();
void setupTrellis();

#endif
